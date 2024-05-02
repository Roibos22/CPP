/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileReader.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 18:25:59 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/05/02 19:05:30 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CSVREADER_HPP
#define CSVREADER_HPP

#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include <string>

class	FileReader
{
	public:
		/* --------- CONSTRUCTORS & DECONSTRUCORS ---------- */
		FileReader();
		FileReader(std::string filename);
		~FileReader();
		FileReader(const FileReader &csvreader);

		/* ------------------- METHODS --------------------- */
		void	readDb();
		void	readInputFile();
		int		validateDate(std::string date);
		double	validateValue(std::string value);
		bool	onlyDigits(std::string str);

		/* -------------- SETTERS & GETTERS ---------------- */
		std::string				getFilenameInput() const;
		std::map<int, double>	getContentDb() const;
		
		/* ------------------ EXCEPTIONS ------------------- */
		class	InvalidDateException: public std::exception
		{
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
	
		/* ------------------ OVERLOADS -------------------- */
		FileReader	&operator=(const FileReader &);

	protected:

	private:
		std::string				_filenameInput;
		std::map<int, double>	_contentDb;
		std::map<int, double>	_contentInput;
};

std::ostream	&operator<<(std::ostream &stream, FileReader const &csvreader);

#endif // CSVReader_HPP
