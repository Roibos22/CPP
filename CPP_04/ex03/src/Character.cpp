/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 19:51:55 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/02/25 19:40:15 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

/* ------------------- CONSTRUCTORS & DECONSTRUCORS -------------------- */

Character::Character()
{
	//std::cout << "Character Default Constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}

Character::Character(std::string name)
{
	//std::cout << "Character Name Constructor called" << std::endl;
	this->_name = name;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}

Character::~Character()
{
	//std::cout << "Character Deconstructor called" << std::endl;
}

Character::Character(const Character &character)
{
	this->_name = character._name;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = character._inventory[i]->clone();
}

/* ----------------------------- METHODS ------------------------------- */

void	Character::equip(AMateria* m)
{
	if (m == 0)
		return ;
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] == NULL)
		{
			this->_inventory[i] = m;
			return ;
		}
	}
	std::cout << "* " << this->getName() << " already has a full invenory *" << std::endl;
}

void	Character::unequip(int idx)
{
	if (idx < 0 || idx > 3 || this->_inventory[idx] == NULL)
		std::cout << "* " << this->getName() << " already unequiped at position " << idx << " *" << std::endl;
	else
	{
		this->_inventory[idx] = NULL;
		std::cout << "* " << this->getName() << " now unequiped at position " << idx << " *" << std::endl;
	}
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3 || this->_inventory[idx] == NULL)
		std::cout << "* " << this->getName() << " cant use Materia at position " << idx << " *" << std::endl;
	else
		this->_inventory[idx]->use(target);
}

/* ------------------------ SETTERS & GETTERS -------------------------- */

void		Character::setName(std::string name)
{
	this->_name = name;
}

const std::string& Character::getName() const
{
	return (this->_name);
}

/* ---------------------------- OVERLOADS ------------------------------ */


Character		&Character::operator=(const Character &origin)
{
	this->_name = origin._name;
	for (int i = 0; i < 4; i++)
		delete(this->_inventory[i]);
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = origin._inventory[i]->clone();
	return (*this);
}

std::ostream	&operator<<(std::ostream &stream, Character const &character)
{
	stream << character.getName() << std::endl;
	return (stream);
}

