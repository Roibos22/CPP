/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 20:02:59 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/04/24 19:22:15 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <cstdlib>

// equal overload (check if spans are same size)

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

	std::cout << "--- TESTING = overlaod ---" << std::endl;
	try
	{
		Span	s1(5);
		Span	s2(5);
		Span	s3;
		s1.fillRandom(s1.getStartVector(), s1.getEndVector());
		std::cout << s1 << std::endl;

		s2 = s1;
		std::cout << s2 << std::endl;
		s3 = s1;
		std::cout << s3 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
