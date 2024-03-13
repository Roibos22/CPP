/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 19:24:33 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/02/19 20:32:25 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

/* ------------------- CONSTRUCTORS & DECONSTRUCORS -------------------- */

Animal::Animal(void)
{
	std::cout << "A new Animal was born!" << std::endl;
	this->_type = "Animal";
}

Animal::Animal(const Animal &animal)
{
	*this = animal;
}

Animal::~Animal()
{
	std::cout << "An animal died... :(" << std::endl;
}

/* ----------------------------- METHODS ------------------------------- */

void		Animal::makeSound(void) const
{
	std::cout << "some random animal noises..." << std::endl;
}

/* ----------------------------- SETTERS ------------------------------- */

void		Animal::setType(std::string type)
{
	this->_type = type;
}

/* ----------------------------- GETTERS ------------------------------- */

std::string	Animal::getType() const
{
	return(this->_type);
}

/* ---------------------------- OVERLOADS ------------------------------ */

std::ostream	&operator<<(std::ostream &stream, Animal const &animal)
{
	stream << animal.getType() << std::endl;
	return (stream);
}

Animal	&Animal::operator=(const Animal &copy)
{
	this->_type = copy.getType();
	return (*this);
}