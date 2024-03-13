/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 23:15:56 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/02/29 00:03:12 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{

	try
	{
		std::cout << "--- Test Default Constructor ---" << std::endl;
		Bureaucrat	Hermione;
		std::cout << Hermione << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl << std::endl;
	}

	try
	{
		std::cout << "--- Test Assignment Constructor ---" << std::endl;
		Bureaucrat	Harry("Harry", 3);
		std::cout << Harry << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl << std::endl;
	}

	try
	{
		std::cout << "--- Test Assignment Constructor Too Low ---" << std::endl;
		Bureaucrat	Ron("Ron", 151);
		std::cout << Ron << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl << std::endl;
	}

	try
	{
		std::cout << "--- Test Assignment Constructor Too High ---" << std::endl;
		Bureaucrat	Dobby("Dobby", 0);
		std::cout << Dobby << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl << std::endl;
	}

	try
	{
		std::cout << "--- Test Increment Grade ---" << std::endl;
		Bureaucrat	Luna("Luna", 5);
		std::cout << Luna;
		Luna.incrementGrade();
		std::cout << Luna << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl << std::endl;
	}

	try
	{
		std::cout << "--- Test Increment Grade Too High ---" << std::endl;
		Bureaucrat	Dumbledore("Dumbledore", 1);
		std::cout << Dumbledore;
		Dumbledore.incrementGrade();
		std::cout << Dumbledore << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl << std::endl;
	}

	try
	{
		std::cout << "--- Test Decrement Grade ---" << std::endl;
		Bureaucrat	Rubeus("Rubeus", 5);
		std::cout << Rubeus;
		Rubeus.decrementGrade();
		std::cout << Rubeus << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl << std::endl;
	}

	try
	{
		std::cout << "--- Test Decrement Grade Too Low ---" << std::endl;
		Bureaucrat	Draco("Draco", 150);
		std::cout << Draco;
		Draco.decrementGrade();
		std::cout << Draco << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl << std::endl;
	}
}