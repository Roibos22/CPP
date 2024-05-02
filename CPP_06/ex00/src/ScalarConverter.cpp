/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 18:33:45 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/04/30 15:21:03 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

e_type	ScalarConverter::_type = UNDEFINED;

/* ------------------- CONSTRUCTORS & DECONSTRUCORS -------------------- */

ScalarConverter::ScalarConverter()
{
	//std::cout << "ScalarConverter Default Constructor called" << std::endl;
}

ScalarConverter::~ScalarConverter()
{
	//std::cout << "ScalarConverter Deconstructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &scalarconverter) { *this = scalarconverter; }

/* ----------------------------- METHODS ------------------------------- */

void	ScalarConverter::convert(const std::string& str)
{
	_type = getType(str);
	switch (_type)
	{
		case NOTANUMBER:
			std::cout << "char: impossible"<< std::endl;
			std::cout << "int: impossible"<< std::endl;
			std::cout << "float: nanf"<< std::endl;
			std::cout << "double: nan"<< std::endl;
			break;
		case POS_INF:
			std::cout << "char: impossible"<< std::endl;
			std::cout << "int: impossible"<< std::endl;
			std::cout << "float: +inff"<< std::endl;
			std::cout << "double: +inf"<< std::endl;
			break;
		case NEG_INF:
			std::cout << "char: impossible"<< std::endl;
			std::cout << "int: impossible"<< std::endl;
			std::cout << "float: -inff"<< std::endl;
			std::cout << "double: -inf"<< std::endl;
			break;
		case CHAR:
			convertChar(str);
			break;
		case INT:
			convertInt(str);
			break;
		case FLOAT:
			convertFloat(str);
			break;
		case DOUBLE:
			convertDouble(str);
			break;
		case UNDEFINED:
			std::cout << "Error: Could not assign a type to \"" << str << "\"" << std::endl;
			break;
	}
}

bool	ScalarConverter::checkFormat(const std::string str, const std::string pattern)
{
	regex_t		regex;
	if (regcomp(&regex, pattern.c_str(), REG_EXTENDED) != 0)
	{
		std::cout << "Regex failed" << std::endl;
		return (false);
	}
	bool	match = regexec(&regex, str.c_str(), 0, NULL, 0) == 0;
	regfree(&regex);
	return (match);
}


void	ScalarConverter::convertChar(const std::string str)
{
	char	c = str[0]; // TODO
	int		i = static_cast<int>(c);
	float	f = static_cast<float>(c);
	double	d = static_cast<double>(c);
	printConversions(c, i, f, d, str);
}

void	ScalarConverter::convertInt(const std::string str)
{
	int			i = atoi(str.c_str());
	char		c = static_cast<char>(i);
	float		f = static_cast<float>(i);
	double		d = static_cast<double>(i);
	printConversions(c, i, f, d, str);
}

void	ScalarConverter::convertFloat(const std::string str)
{
	float		f = strtof(str.c_str(), NULL);
	int			i = static_cast<int>(f);
	char		c = static_cast<char>(f);
	double		d = static_cast<double>(f);
	printConversions(c, i, f, d, str);
}

void	ScalarConverter::convertDouble(const std::string str)
{
	double		d = strtod(str.c_str(), NULL);
	float		f = static_cast<float>(d);
	int			i = static_cast<int>(d);
	char		c = static_cast<char>(d);
	printConversions(c, i, f, d, str);
}

void	ScalarConverter::printConversions(char c, int i, float f, double d, std::string str)
{
	long long input = atoll(str.c_str());
	input = 0;

	//bool	impFlag = false;

	// PRINT CHAR
	if (d < 0 || d > 255)
		std::cout << "char: impossible" << std::endl;
	else if (isprint(c))
		std::cout << "char: '" << c << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;

	// PRINT INT
	if (d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << i << std::endl;

	// PRINT Float
	std::cout << "float: ";
	if (std::isnan(static_cast<double>(f)))
		std::cout << "impossible" << std::endl;
	else
	{
		std::cout << f;
		if ((int)f == f) // TODO
			std::cout << ".0";
		std::cout << "f" << std::endl;
	}
	
	// PRINT DOUBLE
	std::cout << "double: ";
	if (std::isnan(d))
		std::cout << " impossible " << std::endl;
	/* if (d < std::numeric_limits<double>::min() || d > std::numeric_limits<double>::max())
		std::cout << " impossible " << std::numeric_limits<double>::min() << std::endl; */
	else
	{
		std::cout << d;
		if ((int)d == d) // TODO
			std::cout << ".0";
		std::cout << std::endl;
	}
}

/* ------------------------ SETTERS & GETTERS -------------------------- */

e_type	ScalarConverter::getType(const::std::string &str)
{
	e_type res = UNDEFINED;
	if (str == "nan" || str == "nanf")
		return(NOTANUMBER);
	if (str == "+inf" || str == "+inff")
		return(POS_INF);
	if (str == "-inf" || str == "-inff")
		return(NEG_INF);
	if (checkFormat(str, "^.$") && !isdigit(str[0]))
		res = CHAR;
	if (checkFormat(str, "^[[:space:]]*[+-]?[0-9]+$"))
		res = INT;
	if (checkFormat(str, "^[[:space:]]*[+-]?[0-9]+\\.[0-9]+f$") || str == "nanf" || str == "+inff" || str == "-inff")
		res = FLOAT;
	if (checkFormat(str, "^[[:space:]]*[+-]?[0-9]+\\.[0-9]+$")|| str == "nan" || str == "+inf" || str == "-inf")
		res = DOUBLE;
	std::cout << res << std::endl;
	return (res);
}

/* ---------------------------- OVERLOADS ------------------------------ */

ScalarConverter		&ScalarConverter::operator=(const ScalarConverter &origin)
{
	if (this != &origin)
		return *this;
	return *this;
}

std::ostream	&operator<<(std::ostream &stream, ScalarConverter const &scalarconverter)
{
	(void)scalarconverter;
	stream << "Scalar Converter" << std::endl;
	return (stream);
}

