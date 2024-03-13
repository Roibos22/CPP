/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 19:44:38 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/02/25 20:50:57 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Character.hpp"

/* ------------------- CONSTRUCTORS & DECONSTRUCORS -------------------- */

Ice::Ice()
{
	//std::cout << "Ice Default Constructor called" << std::endl;
	this->setType("ice");
}

Ice::~Ice()
{
	//std::cout << "Ice Deconstructor called" << std::endl;
}

Ice::Ice(const Ice &ice) { *this = ice; }

/* ----------------------------- METHODS ------------------------------- */

Ice*	Ice::clone(void) const
{
	return (Ice*)this;
}

void	Ice::use(ICharacter &target)
{
	Character*	character = dynamic_cast<Character*>(&target);
	std::cout << "* shoots an ice bolt at " << character->getName() << " *" << std::endl;
}

/* ------------------------ SETTERS & GETTERS -------------------------- */

/* ---------------------------- OVERLOADS ------------------------------ */


Ice		&Ice::operator=(const Ice &origin)
{
	this->_type = origin._type;
	return (*this);
}

