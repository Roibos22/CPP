/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileReader.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 18:25:57 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/05/02 18:56:12 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FileReader.hpp"

// validate date
	// validate year: min first date, max int max
	// validate month: min 1, max 12
	// validate day:
		// if i == 2 && if year % 4 == 0 - 29 else - 28
		// if i <= 7
			// for % 2 != 0: min 1, max 31
			// for % 2 == 0: min 1, max 30
		// for i <= 12
			// for % 2 != 0: min 1, max 30
			// for % 2 == 0: min 1, max 31
		// 1 - 31
		// 2 - special
		// 3 - 31
		// 4 - 30
		// 5 - 31
		// 6 - 30
		// 7 - 31
		// 8 - 31
		// 9 - 30
		// 10 - 31
		// 11 - 30
		// 12 - 31
	// transform date from YYYY-MM-DD to YYYYMMDD (make calculations easier)
	// empty files!
	// correct header

/* ------------------- CONSTRUCTORS & DECONSTRUCORS -------------------- */

FileReader::FileReader()
{

}

FileReader::FileReader(std::string filename)
{
	this->_filenameInput = filename;
	this->readDb();
}

FileReader::~FileReader()
{

}

FileReader::FileReader(const FileReader &csvreader) { *this = csvreader; }

/* ----------------------------- METHODS ------------------------------- */

void	FileReader::readDb()
{
	std::ifstream	file(this->_filenameInput.c_str());
	std::string		line;
	std::string 	delimiter = ",";

	if (!file.is_open())
	{
		std::cerr << "File not found." << std::endl;
		return ;
	}

	std::getline(file, line);
	while (std::getline(file, line))
	{
		if (line.find(delimiter) != std::string::npos)
		{
			std::string	dateString = line.substr(0, line.find(delimiter));
			std::string	valueString = line.substr(line.find(delimiter) + 1);
			int			date;
			double		value;
			try
			{
				date = validateDate(dateString);
				std::cout << date << std::endl;
			} catch (std::exception &e) {
				std::cerr << e.what() << std::endl;
			}
			try
			{
				value = validateValue(valueString);
				std::cout << value << std::endl;
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << std::endl;
			}
			
			//if (validateDate(date) && validateValue(value))
			//this->_contentDb[date] = value;
			//else
			//	std::cerr << "Invalid line: " << line << std::endl; // TODO: throw exception
			//std::cout << date << " : " << this->_content[date] << " | ";
		}
	}
	file.close();
}


double		FileReader::validateValue(std::string valueString)
{
	double	value;
	std::istringstream iss(valueString);
	std::cout << valueString << " -> ";
	iss >> value;
	if (iss.fail())
		return (throw InvalidValueException(), 0);
	return (value);
}

bool	FileReader::onlyDigits(std::string str)
{
	for (std::size_t i = 0; i < str.size(); ++i)
		if (!std::isdigit(str.at(i)))
			return false;
	return true;
}

int		FileReader::validateDate(std::string date)
{
	int	res;
	int	year;
	int	month;
	int	day;
	std::cout << date << " -> ";
	
	std::string yearString = date.substr(0, date.find("-"));
	int len0 = yearString.length();
	std::string monthString = date.substr(len0 + 1, date.find("-", len0 + 1) - len0 - 1);
	int len0len1 = len0 + monthString.length();
	std::string dayString = date.substr(len0len1 + 2);

	std::istringstream issYear(yearString);
	std::istringstream issMonth(monthString);
	std::istringstream issDay(dayString);

	if (!onlyDigits(yearString) || !onlyDigits(monthString) || !onlyDigits(dayString))
		return (throw InvalidDateException(), 0);
	if (yearString.length() < 4 || monthString.length() != 2 || dayString.length() != 2)
		return (throw InvalidDateException(), 0);
	issYear >> year;
	issMonth >> month;
	issDay >> day;
	if (issYear.fail() || issMonth.fail() || issDay.fail())
		return (throw InvalidDateException(), 0);
	if (year < 2004 || year > 9999 || month < 1 || month > 12) // TODO adjust max year
		return (throw InvalidDateException(), 0);
	if (month == 2 && year % 4 == 0 && day > 29)
		return (throw InvalidDateException(), 0);
	else if (month == 2 && year % 4 != 0 && day > 28)
		return (throw InvalidDateException(), 0);
	else if (month <= 7)
	{
		if ((month % 2 != 0 && day > 31) || (month % 2 == 0 && day > 30))
			return (throw InvalidDateException(), 0);
	}
	else if (month <= 12)
	{
		if ((month % 2 != 0 && day > 30) || (month % 2 == 0 && day > 31))
			return (throw InvalidDateException(), 0);
	}

	res = year * 10000 + month * 100 + day;
	return (res);
}


/* ------------------------ SETTERS & GETTERS -------------------------- */

std::string FileReader::getFilenameInput() const
{
	return this->_filenameInput;
}


std::map<int, double> FileReader::getContentDb() const
{
	return this->_contentDb;
}

/* --------------------------- EXCEPTIONS ------------------------------ */
const char*	FileReader::InvalidDateException::what() const throw()
{
	return "Invalid Date";
}

const char*	FileReader::InvalidValueException::what() const throw()
{
	return "Invalid Value";
}

/* ---------------------------- OVERLOADS ------------------------------ */


FileReader		&FileReader::operator=(const FileReader &origin)
{
	if (this != &origin)
	{
		this->_filenameInput = origin.getFilenameInput();
	}
	return (*this);
}

std::ostream	&operator<<(std::ostream &stream, FileReader const &csvreader)
{
	stream << "CSVReader" << std::endl;
	stream << "File: " << csvreader.getFilenameInput() << std::endl;
	//stream << "Content:" << std::endl;

	return (stream);
}

