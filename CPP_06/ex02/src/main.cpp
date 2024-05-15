/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 21:46:03 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/05/15 15:06:11 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <Base.hpp>
#include <A.hpp>
#include <B.hpp>
#include <C.hpp>
#include <cstdlib>
#include <ctime> 
#include <exception>

Base	*generate(void)
{
	long	seed = 42;
	std::srand((std::time(&seed)));

	int	n = rand() % 3;
	switch(n)
	{
		case 0:
			return new A();
		case 1:
			return new B();
		case 2:
			return new C();
		default:
			return (NULL);
	}
}

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p) && dynamic_cast<A*>(p) != NULL)
		std::cout << "*: Identified Class A!" << std::endl;
	else if (dynamic_cast<B*>(p) && dynamic_cast<B*>(p) != NULL)
		std::cout << "*: Identified Class B!" << std::endl;
	else if (dynamic_cast<C*>(p) && dynamic_cast<C*>(p) != NULL)
		std::cout << "*: Identified Class C!" << std::endl;
	else
		std::cout << "*: Could not identify a class" << std::endl;
}

void	identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "&: Identified Class A!" << std::endl;
	}
	catch (const std::exception& e)
	{
		try
		{
			(void)dynamic_cast<B&>(p);
			std::cout << "&: Identified Class B!" << std::endl;
		}
		catch(const std::exception& e)
		{
			try
			{
				(void)dynamic_cast<C&>(p);
				std::cout << "&: Identified Class C!" << std::endl;
			}
			catch(const std::exception& e)
			{
				std::cout << "&: Could not identify a class" << std::endl;
			}
		}
	}
}

int	main(void)
{
	Base	*obj = generate();
	identify(obj);
	identify(*obj);
	delete (obj);
}