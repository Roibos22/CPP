/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 14:01:28 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/05/07 00:10:46 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// TODO one element in agrs

int main (int argc, char *argv[])
{
	if (argc == 1)
	{
		std::cerr << "Error" << std::endl;
		return (1);
	}
	
	try
	{
		PmergeMe pme(argc, argv);
		pme.sortVector();
		pme.printResult();
	}
	catch ( const std::exception &e )
	{
		std::cout << e.what() << std::endl;
	}


	//std::cout << std::endl << pme << std::endl;
}