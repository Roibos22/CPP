/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CSVReader.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 18:25:57 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/04/29 18:52:31 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CSVReader.hpp"

/* ------------------- CONSTRUCTORS & DECONSTRUCORS -------------------- */

CSVReader::CSVReader()
{

}

CSVReader::CSVReader(std::string filename, std::string delimiter)
{
	this->_filename = filename;
	this->_delimiter = delimiter;
	this->readFile();
}

CSVReader::~CSVReader()
{

}

CSVReader::CSVReader(const CSVReader &csvreader) { *this = csvreader; }

/* ----------------------------- METHODS ------------------------------- */

void	CSVReader::readFile()
{
	std::ifstream	file(this->_filename.c_str());
	std::string		line;
	std::string		date;
	std::string		value;

	if (!file.is_open())
	{
		std::cerr << "File not found." << std::endl;
		return ;
	}

	std::getline(file, line);
	while (std::getline(file, line))
	{
		if (line.find(this->_delimiter) != std::string::npos)
		{
			date = line.substr(0, line.find(this->_delimiter));
			value = line.substr(line.find(this->_delimiter) + 1);
			if (validateDate(date) && validateValue(value))
				this->_content[date] = value;
			else
				std::cerr << "Invalid line: " << line << std::endl; // TODO: throw exception
			//std::cout << date << " : " << this->_content[date] << " | ";
		}
	}
	file.close();
}

int		CSVReader::validateDate(std::string date)
{
	std::cout << date << std::endl;
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return (0);
	std::string	year = date.substr(0, 4);
	std::string	month = date.substr(5, 2);
	std::string	day = date.substr(8, 2);
	if (year.length() != 4 || month.length() != 2 || day.length() != 2)
		return (0);
	if (!isdigit(year[0]) || !isdigit(year[1]) || !isdigit(year[2]) || !isdigit(year[3]))
		return (0);
	if (!isdigit(month[0]) || !isdigit(month[1]) || atoi(month.c_str()) > 12)
		return (0);
	if (!isdigit(day[0]) || !isdigit(day[1]) || atoi(day.c_str()) > 31)
		return (0);
	return (1);
}

int		CSVReader::validateValue(std::string value)
{
	std::cout << value << std::endl;
	return (1);
}

/* ------------------------ SETTERS & GETTERS -------------------------- */

std::string CSVReader::getFilename() const
{
	return this->_filename;
}

std::string CSVReader::getDelimiter() const
{
	return this->_delimiter;
}

std::map<std::string, std::string> CSVReader::getContent() const
{
	return this->_content;
}

/* --------------------------- EXCEPTIONS ------------------------------ */

/* ---------------------------- OVERLOADS ------------------------------ */


CSVReader		&CSVReader::operator=(const CSVReader &origin)
{
	if (this != &origin)
	{
		this->_filename = origin.getFilename();
		this->_delimiter = origin.getDelimiter();
	}
	return (*this);
}

std::ostream	&operator<<(std::ostream &stream, CSVReader const &csvreader)
{
	stream << "CSVReader" << std::endl;
	stream << "File: " << csvreader.getFilename() << std::endl;
	stream << "Delimiter: " << csvreader.getDelimiter() << std::endl; 
	//stream << "Content:" << std::endl;

	return (stream);
}

