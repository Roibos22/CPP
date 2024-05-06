/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 14:01:28 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/05/06 23:59:31 by lgrimmei         ###   ########.fr       */
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
	
	PmergeMe pme(argc, argv);
	pme.sortVector();
	pme.printResult();

	//std::cout << std::endl << pme << std::endl;
}