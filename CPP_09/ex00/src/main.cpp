/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 18:31:27 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/05/03 20:52:09 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <BitcoinExchange.hpp>

// TODO: check for max int

int main( int argc, char *argv[] )
{
	if (argc != 2)
	{
		std::cerr << "Error: could not open file" << std::endl;
		return (-1);
	}
	BitcoinExchange	fileReader(argv[1]);
	fileReader.calculateValues();
	return (0);
}