/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 20:42:09 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/02/19 20:44:44 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

/* ------------------- CONSTRUCTORS & DECONSTRUCORS -------------------- */

WrongAnimal::WrongAnimal(void)
{
	std::cout << "A new WrongAnimal was born!" << std::endl;
	this->_type = "WrongAnimal";
}

WrongAnimal::WrongAnimal(const WrongAnimal &wrongAnimal)
{
	*this = wrongAnimal;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "An wrongAnimal died... :(" << std::endl;
}

/* ----------------------------- METHODS ------------------------------- */

void		WrongAnimal::makeSound(void) const
{
	std::cout << "some wrong animal noises..." << std::endl;
}

/* ----------------------------- SETTERS ------------------------------- */

void		WrongAnimal::setType(std::string type)
{
	this->_type = type;
}

/* ----------------------------- GETTERS ------------------------------- */

std::string	WrongAnimal::getType() const
{
	return(this->_type);
}

/* ---------------------------- OVERLOADS ------------------------------ */

std::ostream	&operator<<(std::ostream &stream, WrongAnimal const &wrongAnimal)
{
	stream << wrongAnimal.getType() << std::endl;
	return (stream);
}

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &copy)
{
	this->_type = copy.getType();
	return (*this);
}