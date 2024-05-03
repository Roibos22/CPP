/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 18:25:57 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/05/03 18:57:44 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

/* ------------------- CONSTRUCTORS & DECONSTRUCORS -------------------- */

BitcoinExchange::BitcoinExchange()
{

}

BitcoinExchange::BitcoinExchange(std::string filename)
{
	this->_filenameInput = filename;
}

BitcoinExchange::~BitcoinExchange()
{

}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &csvreader) { *this = csvreader; }

/* ----------------------------- METHODS ------------------------------- */

void	BitcoinExchange::calculateValues( void )
{
	if (this->readDb() == -1)
		return ;
	if (this->readInputFile() == -1)
		return ;
}

void	BitcoinExchange::printRes(int date, double value, std::string dateString)
{
	std::map<int, double>::iterator it;
	it = this->_contentDb.find(date);

	std::cout << dateString << " => " << value << " => ";
	if (it != this->_contentDb.end())
	{
		double res = it->second * value;
		std::cout << res << std::endl;
	}
	else
	{
		//std::cout << "Exact Date not found." << std::endl;
		std::map<int, double>::iterator it = this->_contentDb.upper_bound(date);
		if (it != this->_contentDb.begin()) {
			--it;
			//std::cout << "Closest Date found that is smaller: " << it->first << std::endl;
			std::cout << it->second * value << std::endl;
		} else {
			std::cout << "No smaller date found." << std::endl;
		}
	}
}

int	BitcoinExchange::readInputFile()
{
	std::string		line;
	std::string 	delimiter = " | ";
	std::ifstream	file(this->_filenameInput.c_str());
	if (!file.is_open())
	{
		std::cerr << "Error: could not open file" << std::endl;
		return (-1);
	}
	
	std::getline(file, line);
	try
	{
		if (line != "date | value")
			throw InvalidHeaderException();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return (-1);
	}

	while (std::getline(file, line))
	{
		if (line.empty())
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}
		std::string	dateString = line.substr(0, line.find(delimiter));
		std::string	valueString = line.substr(line.find(delimiter) + 3);

		int		date;
		double	value;
		try
		{
			date = validateDate(dateString);
			value = validateValueInput(valueString);
			printRes(date, value, dateString);
		}
		catch(const ValueNegativeException& e)
		{
			std::cerr << "Error: not a positive number" << std::endl;
		}
		catch(const ValueTooLargeException& e)
		{
			std::cerr << "Error: too large a number" << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << "Error: bad input => " << line << std::endl;
		}
	}
	return (0);
}

int	BitcoinExchange::readDb()
{
	std::ifstream	file("data.csv");
	std::string		line;
	std::string 	delimiter = ",";

	if (!file.is_open())
	{
		std::cerr << "Error: could not open data.csv" << std::endl;
		return (-1);
	}

	std::getline(file, line);
	try
	{
		if (line != "date,exchange_rate")
			throw InvalidHeaderException();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return (-1);
	}
	
	while (std::getline(file, line))
	{
		if (line.empty())
		{
			std::cerr << "Error: bad database" << line << std::endl;
			return (-1);
		}
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
				std::cerr << e.what() << " in databse" << std::endl;
				return (-1);
			}
			try
			{
				value = validateValueDb(valueString);
				this->_contentDb.insert(std::pair<int, double>(date, value));
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << " in databse" << std::endl;
				return (-1);
			}
		}
		else
		{
			std::cerr << "Error: bad database" << std::endl;
			return (-1);
		}
	}
	file.close();
	return (0);
}


double		BitcoinExchange::validateValueDb(std::string valueString)
{
	double	value;
	std::istringstream iss(valueString);
	iss >> value;
	if (iss.fail())
		return (throw InvalidValueException(), 0);
	return (value);
}

double		BitcoinExchange::validateValueInput(std::string valueString)
{
	double	value;
	std::istringstream iss(valueString);
	iss >> value;
	if (iss.fail())
		return (throw InvalidValueException(), 0);
	if (value < 0)
		return (throw ValueNegativeException(), 0);
	if (value > 1000)
		return (throw ValueTooLargeException(), 0);
	return (value);
}

bool	BitcoinExchange::onlyDigits(std::string str)
{
	for (std::size_t i = 0; i < str.size(); ++i)
		if (!std::isdigit(str.at(i)))
			return false;
	return true;
}

int		BitcoinExchange::validateDate(std::string date)
{
	int	res;
	int	year;
	int	month;
	int	day;
	
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

std::string BitcoinExchange::getFilenameInput() const
{
	return this->_filenameInput;
}


std::map<int, double> BitcoinExchange::getContentDb() const
{
	return this->_contentDb;
}

/* --------------------------- EXCEPTIONS ------------------------------ */
const char*	BitcoinExchange::InvalidDateException::what() const throw()
{
	return "Error: Invalid Date";
}

const char*	BitcoinExchange::InvalidValueException::what() const throw()
{
	return "Error: Invalid Value";
}

const char*	BitcoinExchange::InvalidHeaderException::what() const throw()
{
	return "Error: Invalid Header";
}

const char*	BitcoinExchange::ValueNegativeException::what() const throw()
{
	return "Error: not a positive number";
}

const char*	BitcoinExchange::ValueTooLargeException::what() const throw()
{
	return "Error: too large a number";
}

/* ---------------------------- OVERLOADS ------------------------------ */


BitcoinExchange		&BitcoinExchange::operator=(const BitcoinExchange &origin)
{
	if (this != &origin)
	{
		this->_filenameInput = origin.getFilenameInput();
	}
	return (*this);
}

std::ostream	&operator<<(std::ostream &stream, BitcoinExchange const &csvreader)
{
	stream << "CSVReader" << std::endl;
	stream << "File: " << csvreader.getFilenameInput() << std::endl;
	return (stream);
}

