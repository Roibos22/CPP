/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 19:21:18 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/02/25 20:35:01 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Character.hpp"

/* ------------------- CONSTRUCTORS & DECONSTRUCORS -------------------- */

AMateria::AMateria()
{
	//std::cout << "AMateria Default Constructor called" << std::endl;
}

AMateria::~AMateria()
{
	//std::cout << "AMateria Deconstructor called" << std::endl;
}

AMateria::AMateria(const AMateria &aMateria)
{
	*this = aMateria;
}

AMateria::AMateria(std::string const& type)
{
	this->_type = type;
}

/* ----------------------------- METHODS ------------------------------- */

void	AMateria::use(ICharacter &target)
{
	Character*	character = dynamic_cast<Character*>(&target);
	std::cout << "* soem Materia is used at  " << character->getName() << " *" << std::endl;
}

/* ------------------------ SETTERS & GETTERS -------------------------- */

std::string const &AMateria::getType() const
{
	return (this->_type);
}

void	AMateria::setType(std::string type)
{
	this->_type = type;
}

/* ---------------------------- OVERLOADS ------------------------------ */

AMateria		&AMateria::operator=(const AMateria &origin)
{
	this->_type = origin._type;
	return (*this);
}

std::ostream	&operator<<(std::ostream &stream, AMateria const &aMateria)
{
	stream << aMateria.getType() << std::endl;
	return (stream);
}

