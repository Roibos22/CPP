/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 19:24:33 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/02/20 18:25:44 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/* ------------------- CONSTRUCTORS & DECONSTRUCORS -------------------- */

Dog::Dog(void): Animal()
{
	std::cout << "A new Dog was born!" << std::endl;
	this->_type = "Dog";
	this->_brain = new Brain();
	for (int i = 0; i < 100; i++)
		this->_brain->setIdea(i, "What a genius idea!");
}

Dog::Dog(const Dog &dog)
{
	this->_type = dog.getType() + "_copy";
	this->_brain = new Brain();
	for (int i = 0; i < 100; i++)
		this->_brain->setIdea(i, "What a genius id... where did you copy that from?!");}

Dog::~Dog()
{
	delete(this->_brain);
	std::cout << "A dog died... :(" << std::endl;}

/* ----------------------------- METHODS ------------------------------- */

void		Dog::makeSound(void) const
{
	std::cout << "WUFF! WUFF!" << std::endl;
}

void		Dog::print(std::ostream& stream) const
{
	stream << this->getType() << std::endl;
	for (int i = 0; i < 100; i++)
		stream << this->getBrain()->getIdea(i) << std::endl;
}

/* ----------------------------- SETTERS ------------------------------- */

/* ----------------------------- GETTERS ------------------------------- */

std::string	Dog::getType() const
{
	return(this->_type);
}

Brain*	Dog::getBrain(void) const
{
	return (this->_brain);
}

/* ---------------------------- OVERLOADS ------------------------------ */

Dog	&Dog::operator=(const Dog &copy)
{
	this->_type = copy.getType();
	return (*this);
}