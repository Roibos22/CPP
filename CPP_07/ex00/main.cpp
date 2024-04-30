/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 23:54:55 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/04/29 18:28:26 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

int	main(void)
{
	int			a = 4;
	int			b = 2;
	std::string	s1 = "42 is love";
	std::string	s2 = "berlin is love";

	std::cout << "--- TESTING SWAP ---" << std::endl;
	std::cout << "a: " << a << " b: " << b << std::endl;
	swap(a, b);
	std::cout << "a: " << a << " b: " << b << std::endl;
	std::cout << "s1: " << s1 << " s2: " << s2 << std::endl;
	swap(s1, s2);
	std::cout << "s1: " << s1 << " s2: " << s2 << std::endl << std::endl;

	std::cout << "--- TESTING MIN ---" << std::endl;
	std::cout << "a: " << a << " b: " << b << " min: " << min(a, b) << std::endl;
	std::cout << "s1: " << s1 << " s2: " << s2 << " min: " << min(s1, s2) << std::endl << std::endl;

	std::cout << "--- TESTING MAX ---" << std::endl;
	std::cout << "a: " << a << " b: " << b << " max: " << max(a, b) << std::endl;
	std::cout << "s1: " << s1 << " s2: " << s2 << " max: " << max(s1, s2) << std::endl << std::endl;

	//std::cout << "--- TESTING MAX (Wrong Types) ---" << std::endl;
	//std::cout << "a: " << a << " s1: " << s1 << " max: " << max(a, s1) << std::endl;
	//std::cout << "b: " << b << " s2: " << s2 << " max: " << max(b, s2) << std::endl;

	{
		std::cout << "--- TESTING Subject ---" << std::endl;
		int a = 2;
		int b = 3;
		std::swap( a, b );
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
		std::string c = "chaine1";
		std::string d = "chaine2";
		std::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
		std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	}

}
