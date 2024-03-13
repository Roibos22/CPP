/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 19:44:42 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/02/21 15:38:15 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "Character.hpp"

/* ------------------- CONSTRUCTORS & DECONSTRUCORS -------------------- */

Cure::Cure()
{
	//std::cout << "Cure Default Constructor called" << std::endl;
	this->setType("cure");
}

Cure::~Cure()
{
	//std::cout << "Cure Deconstructor called" << std::endl;
}

Cure::Cure(const Cure &cure) { *this = cure; }

/* ----------------------------- METHODS ------------------------------- */

Cure*	Cure::clone(void) const
{
	return (Cure*)this;
}

void	Cure::use(ICharacter &target)
{
	Character*	character = dynamic_cast<Character*>(&target);
	std::cout << "* heals " << character->getName() << "'s wound *" << std::endl;
}

/* ------------------------ SETTERS & GETTERS -------------------------- */

/* ---------------------------- OVERLOADS ------------------------------ */


Cure		&Cure::operator=(const Cure &origin)
{
	this->_type = origin._type;
	return (*this);
}
