/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 14:01:28 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/05/07 13:17:57 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// TODO one element in agrs
// TODO ./PmergeMe 10 9 8 7 6
// TODO time management also included!

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
		pme.sortDeque();
		pme.printResult();
	}
	catch ( const std::exception &e )
	{
		std::cout << e.what() << std::endl;
	}


	//std::cout << std::endl << pme << std::endl;
}