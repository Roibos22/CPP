/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CSVReader.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 18:25:59 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/04/26 18:53:58 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CSVREADER_HPP
#define CSVREADER_HPP

#include <iostream>
#include <map>
#include <fstream>

class	CSVReader
{
	public:
		/* --------- CONSTRUCTORS & DECONSTRUCORS ---------- */
		CSVReader();
		CSVReader(std::string filename, std::string delimiter);
		~CSVReader();
		CSVReader(const CSVReader &csvreader);

		/* ------------------- METHODS --------------------- */
		void	readFile();
		int		validateDate(std::string date);
		int		validateValue(std::string value);

		/* -------------- SETTERS & GETTERS ---------------- */
		std::string							getFilename() const;
		std::string							getDelimiter() const;
		std::map<std::string, std::string>	getContent() const;
		
		/* ------------------ EXCEPTIONS ------------------- */

		/* ------------------ OVERLOADS -------------------- */
		CSVReader	&operator=(const CSVReader &);

	protected:

	private:
		std::string							_filename;
		std::string							_delimiter;
		std::map<std::string, std::string>	_content;
};

std::ostream	&operator<<(std::ostream &stream, CSVReader const &csvreader);

#endif // CSVReader_HPP
