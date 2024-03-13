/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 21:17:42 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/02/19 21:23:49 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

/* ------------------- CONSTRUCTORS & DECONSTRUCORS -------------------- */

WrongCat::WrongCat()
{
	this->_type = "WrongCat";
	std::cout << "A new WrongCat was born!" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "A WrongCat died... :(" << std::endl;
}

WrongCat::WrongCat(const WrongCat &wrongCat) { *this = wrongCat; }

/* ----------------------------- METHODS ------------------------------- */

void		WrongCat::makeSound(void) const
{
	std::cout << "some wrong cat noises" << std::endl;
}

/* ----------------------------- SETTERS ------------------------------- */

/* ----------------------------- GETTERS ------------------------------- */

std::string	WrongCat::getType() const
{
	return(this->_type);
}

/* ---------------------------- OVERLOADS ------------------------------ */


WrongCat		&WrongCat::operator=(const WrongCat &origin)
{
	this->_type = origin.getType();
	return (*this);
}

std::ostream	&operator<<(std::ostream &stream, WrongCat const &wrongcat)
{
	stream << wrongcat.getType() << std::endl;
	return (stream);
}

