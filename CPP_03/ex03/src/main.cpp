/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:28:28 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/02/18 16:14:25 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main(void)
{
	{
		DiamondTrap	a("Diddy");
		std::cout << a;
		for (int i = 0; i < 49; i++)
			a.attack("Target");
		std::cout << a;
		a.beRepaired(5);
		a.beRepaired(5);
		a.attack("Target");
		std::cout << a;
	}
	std::cout << std::endl;
	{
		DiamondTrap	a("Diddy");
		std::cout << a;
		a.takeDamage(150);
		std::cout << a;
		a.attack("Target");
		a.beRepaired(5);
		std::cout << a;
	}
	std::cout << std::endl;
	{
		DiamondTrap	a("Diddy");
		DiamondTrap	b(a);
		DiamondTrap	c = a;
		a.whoAmI();
		b.whoAmI();
		c.whoAmI();
		std::cout << a << b << c;
	}
}

/* 		ClapTrap	a("Trappy");
		std::cout << std::endl;

		ScavTrap	b("Scavvy");
		std::cout << std::endl;

		FragTrap	c("Fraggy");
		std::cout << std::endl;
 */

/* 
		std::cout << b << a << c << d << std::endl;

		//a.guardGate();
		b.guardGate();
		//c.guardGate()
		std::cout << b << a << c << std::endl;

		//a.highFivesGuys();
		//b.highFivesGuys();
		c.highFivesGuys();
		std::cout << b << a << c << std::endl;

		a.attack("Target");
		b.attack("Target");
		c.attack("Target");
		std::cout << b << a << c << std::endl;

		a.takeDamage(5);
		b.takeDamage(5);
		c.takeDamage(5);
		std::cout << b << a << c << std::endl;

		a.beRepaired(10);
		b.beRepaired(10);
		c.beRepaired(10);
		std::cout << b << a << c << std::endl; */