/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileReader.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 18:25:59 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/05/03 19:34:14 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CSVREADER_HPP
#define CSVREADER_HPP

#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include <string>

class	BitcoinExchange
{
	public:
		/* --------- CONSTRUCTORS & DECONSTRUCORS ---------- */
		BitcoinExchange();
		BitcoinExchange(std::string filename);
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &csvreader);

		/* ------------------- METHODS --------------------- */
		int	readDb();
		int	readInputFile();
		int		validateDate(std::string date);
		double	validateValueDb(std::string value);
		double	validateValueInput(std::string value);
		bool	onlyDigits(std::string str);
		void	printRes(int date, double value, std::string dateString);
		void	calculateValues( void );

		/* -------------- SETTERS & GETTERS ---------------- */
		std::string				getFilenameInput() const;
		std::map<int, double>	getContentDb() const;
		
		/* ------------------ EXCEPTIONS ------------------- */
		class	InvalidDateException: public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};
		class	InvalidValueException: public std::exception
		{
			virtual const char	*what() const throw();
		};
		class	InvalidHeaderException: public std::exception
		{
			virtual const char	*what() const throw();
		};
		class	ValueNegativeException: public std::exception
		{
			virtual const char	*what() const throw();
		};
		class	ValueTooLargeException: public std::exception
		{
			virtual const char	*what() const throw();
		};

	
		/* ------------------ OVERLOADS -------------------- */
		BitcoinExchange	&operator=(const BitcoinExchange &);

	protected:

	private:
		std::string				_filenameInput;
		std::map<int, double>	_contentDb;
		std::map<int, double>	_contentInput;
};

std::ostream	&operator<<(std::ostream &stream, BitcoinExchange const &csvreader);

#endif // CSVReader_HPP
