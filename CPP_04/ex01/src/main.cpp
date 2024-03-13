/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 19:32:53 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/02/21 15:31:22 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main (void)
{
	{
		Animal*	animals[4];
		for (int i = 0; i < 2; i++)
			animals[i] = new Cat();
		for (int i = 2; i < 4; i++)
			animals[i] = new Dog();

		Cat*	originalCat = dynamic_cast<Cat*>(animals[0]);
		Cat		copycat(*originalCat);

		Dog*	originalDog = dynamic_cast<Dog*>(animals[2]);
		Dog		copydog(*originalDog);

		std::cout << std::endl;

		std::cout << *animals[0] << std::endl;
		std::cout << copycat << std::endl;
		std::cout << copydog << std::endl;

		std::cout << std::endl;

		for (int i = 0; i < 4; i++)
			delete(animals[i]);
		//delete(*copycat);
	}

	std::cout << std::endl;

	{
		Animal	tiger;
		Cat		cat;
	}

	return (0);
}