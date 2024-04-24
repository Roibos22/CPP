/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 20:02:59 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/04/24 18:41:04 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <cstdlib>

// allocate vector?
// function that fills vector with n numbers

int main(void)
{
	{
		std::cout << "--- TESTING Subject Test ---" << std::endl;
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}

	{
		std::cout << "--- TESTING addNumber() ---" << std::endl;
		Span	s(5);

		try
		{
			s.addNumber(42);
			std::cout << s << std::endl;
			s.addNumber(22);
			std::cout << s << std::endl;
			s.addNumber(-2);
			std::cout << s << std::endl;
			s.addNumber(420);
			std::cout << s << std::endl;
			s.addNumber(7);
			std::cout << s << std::endl;
			s.addNumber(70);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << s << std::endl;

		std::cout << "--- TESTING longestSpan() ---" << std::endl;
		try
		{
			std::cout << s.longestSpan() << std::endl;
			Span	s2(1);
			s2.addNumber(42);
			s2.longestSpan();
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}

		std::cout << "--- TESTING shortestSpan() ---" << std::endl;
		try
		{
			std::cout << s.shortestSpan() << std::endl;
			Span	s2(1);
			s2.addNumber(42);
			s2.shortestSpan();
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << "--- TESTING fill random (40420) ---" << std::endl;
	try
	{
		Span	s(42042);
		s.fillRandom(s.getStartVector(), s.getEndVector());
		//std::cout << s << std::endl;
		std::cout << s.shortestSpan() << std::endl;
		std::cout << s.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	
}

/* 
int main()
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	return 0;
}
 */