/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 03:08:43 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/03/07 20:26:32 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int	main(void)
{
	{
		std::cout << "--- TESTING EMPTY ARRAY ---" << std::endl;
		try
		{
			Array<int>	test;
			test[0] = 1;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	{
		std::cout << "--- TESTING ARRAY WITH N ELEMENTS ---" << std::endl;
		try
		{
			Array<int>	test(3);
			test[0] = 1;
			std::cout << test[0] << std::endl;
			
			std::cout << "--- TESTING SIZE METHODS ---" << std::endl;
			std::cout << test.size() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	{
		std::cout << "--- TESTING COPY CONSTRUCTOR ---" << std::endl;
		try
		{
			Array<int>	original(2);
			original[0] = 1;
			original[1] = 2;
			std::cout << "Original before: " << original[0] << ", " << original[1] << std::endl;
			Array<int>	copy(original);
			std::cout << "Copy before: " << copy[0] << ", " << copy[1] << std::endl;
			copy[0] = 3;
			copy[1] = 4;
			std::cout << "Original after: " << original[0] << ", " << original[1] << std::endl;
			std::cout << "Copy after: " << copy[0] << ", " << copy[1] << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	{
		std::cout << "--- TESTING EQUAL OVERLOAD ---" << std::endl;
		try
		{
			Array<int>	original(2);
			original[0] = 1;
			original[1] = 2;
			std::cout << "Original before: " << original[0] << ", " << original[1] << std::endl;
			Array<int>	copy;
			copy = original;
			std::cout << "Copy before: " << copy[0] << ", " << copy[1] << std::endl;
			copy[0] = 3;
			copy[1] = 4;
			std::cout << "Original after: " << original[0] << ", " << original[1] << std::endl;
			std::cout << "Copy after: " << copy[0] << ", " << copy[1] << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}


}