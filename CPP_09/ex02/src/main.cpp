/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 14:01:28 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/05/07 15:21:23 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main (int argc, char *argv[])
{
	if (argc == 1)
	{
		std::cerr << "Error" << std::endl;
		return (1);
	}

	try
	{
		PmergeMe	pme;
		pme.sortVector(argc, argv);
		pme.sortDeque(argc, argv);
		pme.printResult();
		PmergeMe	pme2(pme);
		std::cout << pme2;
	}
	catch ( const std::exception &e )
	{
		std::cerr << e.what() << std::endl;
		return (1);
	}

	return (0);
}