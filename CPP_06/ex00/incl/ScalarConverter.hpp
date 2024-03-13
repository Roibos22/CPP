/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 18:33:42 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/03/11 00:13:34 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <regex.h>

enum	e_type
{
	UNDEFINED,
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	NOTANUMBER,
	POS_INF,
	NEG_INF
};

class	ScalarConverter
{
	public:

		/* ------------------- METHODS --------------------- */
		static void	convert(const std::string &str);
		static bool	checkFormat(std::string str, const std::string pattern);
		static void	convertChar(const std::string str);
		static void	convertInt(const std::string str);
		static void	convertDouble(const std::string str);
		static void	convertFloat(const std::string str);
		static void	printConversions(char c, int i, float f, double d, std::string str);

		/* -------------- SETTERS & GETTERS ---------------- */
		static e_type	getType(const::std::string &str);

		/* ------------------ OVERLOADS -------------------- */
		ScalarConverter	&operator=(const ScalarConverter &);

	protected:
	
	private:
		/* --------- CONSTRUCTORS & DECONSTRUCORS ---------- */
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(const ScalarConverter &scalarconverter);
		static	e_type	_type;
};


std::ostream	&operator<<(std::ostream &stream, ScalarConverter const &scalarconverter);

#endif // ScalarConverter_HPP
