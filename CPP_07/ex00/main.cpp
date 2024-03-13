/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 23:54:55 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/03/07 01:43:36 by lgrimmei         ###   ########.fr       */
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
	std::cout << "s1: " << s1 << " s2: " << s2 << " max: " << max(s1, s2) << std::endl;
}
