/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 17:51:53 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/04/29 13:28:59 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ScalarConverter.hpp>

// implicit downcast from double to float when using atof - DONE
// forgot to check for overflows
	// char: 0 - 255, sonst impossible
	// int: MIN_INT - MAX_INT, sonst impossible
	// float:
	// double:
// exact name of the executable in ex00 - DONE

int main(int argc, char *argv[])
{
	//Class is not instantiable
	//ScalarConverter test;

	if (argc != 2)
		std::cout << "Usage: ./conversion [str]" << std::endl;
	else
		ScalarConverter::convert(argv[1]);
}

// --- TYPE CASTING IN C++ ---
// IMPLICIT CONVERSION
//	- done by the compiler, upcasting always
//	- potential errors and loss of information
//	- example: int x = 10; char y = 'a'; z = x + y; z will be concerted to ASCII 97, so z = 107
// EXPLICIT CONVERSION (C-STYLE)
//	- user can decide what type to cast a value to
//	- upcasting, downcasting, and const casting.
//	- example: double x = 1.2; int sum = (int)x + 1; sum = 2
// DYNAMIC CAST <- ex02
//	- used to downcast in inheritance hirachies
//	- runtime check and returns NULL for pointers and std::bad_cast for references
// STATIC CAST <- ex00
//	- used for coversion betwwen related types (eg. int to float)
//	- no runtime check, but compile time cast
//	- more restricitve than c-style casting
// CONST CAST
//	- used to add or remove const from a variable
// REINTERPRET CAST <- ex01
//	- most dangerous
//	- can convert anything to anything
//	- no guarantees about result of conversion