/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:28:28 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/02/18 16:11:19 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	{
		FragTrap	a("Fraggy");
		std::cout << a;
		for (int i = 0; i < 99; i++)
			a.attack("Target");
		std::cout << a;
		a.beRepaired(5);
		a.beRepaired(5);
		a.attack("Target");
		std::cout << a;
	}
	std::cout << std::endl;
	{
		FragTrap	a("Fraggy");
		std::cout << a;
		a.takeDamage(150);
		std::cout << a;
		a.attack("Target");
		a.beRepaired(5);
		std::cout << a;
	}
	std::cout << std::endl;
	{
		FragTrap	a("Fraggy");
		FragTrap	b(a);
		FragTrap	c = a;
		a.highFivesGuys();
		b.highFivesGuys();
		c.highFivesGuys();
		std::cout << a << b << c;
	}
}