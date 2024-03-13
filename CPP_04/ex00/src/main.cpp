/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 19:32:53 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/02/21 15:26:26 by lgrimmei         ###   ########.fr       */
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
		const Animal* meta = new Animal();
		const WrongAnimal* wrongMeta = new WrongAnimal();
		const Animal* i = new Cat();
		const Animal* j = new Dog();
		const WrongAnimal* k = new WrongCat();

		std::cout << std::endl;

		std::cout << meta->getType() << ": ";
		meta->makeSound();
		std::cout << i->getType() << ": ";
		i->makeSound();
		std::cout << j->getType() << ": ";
		j->makeSound();
		std::cout << wrongMeta->getType() << ": ";
		wrongMeta->makeSound();
		std::cout << k->getType() << ": ";
		k->makeSound();

		std::cout << std::endl;

		delete(meta);
		delete(wrongMeta);
		delete(i);
		delete(j);
		delete(k);
	}

	return (0);
}