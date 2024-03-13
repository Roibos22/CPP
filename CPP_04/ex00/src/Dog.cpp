/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 19:24:33 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/02/19 20:36:37 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/* ------------------- CONSTRUCTORS & DECONSTRUCORS -------------------- */

Dog::Dog(void): Animal()
{
	this->_type = "Dog";
	std::cout << "A new Dog was born!" << std::endl;
}

Dog::Dog(const Dog &dog)
{
	*this = dog;
}

Dog::~Dog()
{
	std::cout << "A dog died... :(" << std::endl;
}

/* ----------------------------- METHODS ------------------------------- */

void		Dog::makeSound(void) const
{
	std::cout << "WUFF! WUFF!" << std::endl;
}

/* ----------------------------- SETTERS ------------------------------- */

/* ----------------------------- GETTERS ------------------------------- */

std::string	Dog::getType() const
{
	return(this->_type);
}

/* ---------------------------- OVERLOADS ------------------------------ */

std::ostream	&operator<<(std::ostream &stream, Dog const &dog)
{
	stream << dog.getType() << std::endl;
	return (stream);
}

Dog	&Dog::operator=(const Dog &copy)
{
	this->_type = copy.getType();
	return (*this);
}