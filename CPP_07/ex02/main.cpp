/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 03:08:43 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/04/30 15:07:26 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>

#define MAX_VAL 750
int subject( void )
{
	std::cout << "--- TESTING SUBJECT ---" << std::endl;
	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	//SCOPE
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}
	try
	{
		numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = rand();
	}
	delete [] mirror;//
	return 0;
}

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
	subject();
}

