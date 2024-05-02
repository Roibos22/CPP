/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileReader.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 18:25:57 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/05/02 20:21:02 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FileReader.hpp"

/* ------------------- CONSTRUCTORS & DECONSTRUCORS -------------------- */

FileReader::FileReader()
{

}

FileReader::FileReader(std::string filename)
{
	this->_filenameInput = filename;
	this->readDb();
	this->readInputFile();
}

FileReader::~FileReader()
{

}

FileReader::FileReader(const FileReader &csvreader) { *this = csvreader; }

/* ----------------------------- METHODS ------------------------------- */

void	FileReader::readInputFile()
{
	std::string		line;
	std::string 	delimiter = " | ";
	std::ifstream	file(this->_filenameInput.c_str());
	if (!file.is_open())
	{
		std::cerr << "File not found." << std::endl;
		return ;
	}
	
	std::getline(file, line);
	try
	{
		if (line != "date | value")
			std::cerr << "Invalid header." << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	while (std::getline(file, line))
	{
		std::string	dateString = line.substr(0, line.find(delimiter));
		std::string	valueString = line.substr(line.find(delimiter) + 3);
		
		int			date;
		double		value;
		try
		{
			date = validateDate(dateString);
			//std::cout << date << std::endl;
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		try
		{
			value = validateValue(valueString);
			//std::cout << value << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		std::cout << dateString << " => " << value << " => ";
		
		// find date in db
		
		std::map<int, double>::iterator it; // Declare iterator explicitly
		it = this->_contentDb.find(date); // Assign result of find to iterator
		if (it != this->_contentDb.end())
		{
			double res = it->second * value;
			std::cout << res << std::endl;
		} else {
			std::cout << "Key not found." << std::endl;
		}

	}
}

void	FileReader::readDb()
{
	std::ifstream	file("data.csv");
	std::string		line;
	std::string 	delimiter = ",";

	if (!file.is_open())
	{
		std::cerr << "File not found." << std::endl;
		return ;
	}

	std::getline(file, line);
	try
	{
		if (line != "date,exchange_rate")
			std::cerr << "Invalid header." << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
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
				//std::cout << date << std::endl;
			} catch (std::exception &e) {
				std::cerr << e.what() << std::endl;
			}
			try
			{
				value = validateValue(valueString);
				this->_contentDb.insert(std::pair<int, double>(date, value));
				//std::cout << date << " => " << value << std::endl;
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << std::endl;
			}
		}
	}
	file.close();
}


double		FileReader::validateValue(std::string valueString)
{
	double	value;
	std::istringstream iss(valueString);
	//std::cout << valueString << " -> ";
	iss >> value;
	if (iss.fail())
		return (throw InvalidValueException(), 0);
	//std::cout << std::endl << valueString << " -> " << value << std::endl;
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
	//std::cout << date << " -> ";
	
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

const char*	FileReader::InvalidHeaderException::what() const throw()
{
	return "Invalid Header";
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

