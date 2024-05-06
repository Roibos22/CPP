/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 14:01:28 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/05/06 15:26:10 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "PmergeMe.hpp"

int main (int argc, char *argv[])
{
	if (argc == 1)
		std::cerr << "Error" << std::endl;
	
	PmergeMe pme(argc, argv);
	pme.sortVector();
	std::cout << pme << std::endl;
	// create PmergeMe

	// run sort

	// print res
}