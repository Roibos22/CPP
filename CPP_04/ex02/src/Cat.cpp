/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 19:44:05 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/02/20 18:24:33 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

/* ------------------- CONSTRUCTORS & DECONSTRUCORS -------------------- */

Cat::Cat()
{
	std::cout << "A new Cat was born!" << std::endl;
	this->_type = "Cat";
	this->_brain = new Brain();
	for (int i = 0; i < 100; i++)
		this->_brain->setIdea(i, "What a genius idea!");
}

Cat::~Cat()
{
	delete(this->_brain);
	std::cout << "A cat died... :(" << std::endl;
}

Cat::Cat(const Cat &cat)
{
	this->_type = cat.getType() + "_copy";
	this->_brain = new Brain();
	for (int i = 0; i < 100; i++)
		this->_brain->setIdea(i, "What a genius id... where did you copy that from?!");
}

/* ----------------------------- METHODS ------------------------------- */

void		Cat::makeSound(void) const
{
	std::cout << "miaaaauuuuu" << std::endl;
}

void		Cat::print(std::ostream& stream) const
{
	stream << this->getType() << std::endl;
	for (int i = 0; i < 100; i++)
		stream << this->getBrain()->getIdea(i) << std::endl;
}

/* ----------------------------- SETTERS ------------------------------- */

/* ----------------------------- GETTERS ------------------------------- */

std::string	Cat::getType() const
{
	return(this->_type);
}

Brain*	Cat::getBrain(void) const
{
	return (this->_brain);
}

/* ---------------------------- OVERLOADS ------------------------------ */

Cat		&Cat::operator=(const Cat &origin)
{
	this->_type = origin.getType();
	return (*this);
}

