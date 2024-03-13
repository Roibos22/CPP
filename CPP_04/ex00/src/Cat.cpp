/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 19:44:05 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/02/19 20:36:40 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

/* ------------------- CONSTRUCTORS & DECONSTRUCORS -------------------- */

Cat::Cat()
{
	this->_type = "Cat";
	std::cout << "A new Cat was born!" << std::endl;
}

Cat::~Cat()
{
	std::cout << "A cat died... :(" << std::endl;
}

Cat::Cat(const Cat &cat) { *this = cat; }

/* ----------------------------- METHODS ------------------------------- */

void		Cat::makeSound(void) const
{
	std::cout << "miaaaauuuuu" << std::endl;
}

/* ----------------------------- SETTERS ------------------------------- */

/* ----------------------------- GETTERS ------------------------------- */

std::string	Cat::getType() const
{
	return(this->_type);
}

/* ---------------------------- OVERLOADS ------------------------------ */


Cat		&Cat::operator=(const Cat &origin)
{
	this->_type = origin.getType();
	return (*this);
}

std::ostream	&operator<<(std::ostream &stream, Cat const &cat)
{
	stream << cat.getType() << std::endl;
	return (stream);
}

