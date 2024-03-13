/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:28:28 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/02/18 16:00:43 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	{
		ClapTrap	a("Trappy");
		std::cout << a;
		a.attack("Target");
		a.attack("Target");
		a.attack("Target");
		a.attack("Target");
		a.attack("Target");
		a.attack("Target");
		a.attack("Target");
		a.attack("Target");
		a.beRepaired(5);
		std::cout << a;
		a.attack("Target");
		a.attack("Target");
		a.beRepaired(5);
		std::cout << a;
	}
	std::cout << std::endl;
	{
		ClapTrap	a("Trappy");
		std::cout << a;
		a.takeDamage(15);
		std::cout << a;
		a.attack("Target");
		a.beRepaired(5);
		std::cout << a;
	}
	std::cout << std::endl;
	{
		ClapTrap	a("Trappy");
		ClapTrap	b(a);
		ClapTrap	c = a;
		std::cout << a << b << c;
	}
}