/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 21:01:40 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/02/22 17:38:00 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

/* ------------------- CONSTRUCTORS & DECONSTRUCORS -------------------- */

MateriaSource::MateriaSource()
{
	//std::cout << "MateriaSource Default Constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}

MateriaSource::~MateriaSource()
{
	//std::cout << "MateriaSource Deconstructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] != NULL)
			delete (this->_inventory[i]);
	}
}

MateriaSource::MateriaSource(const MateriaSource &materiasource) { *this = materiasource; }

/* ----------------------------- METHODS ------------------------------- */

void		MateriaSource::learnMateria(AMateria* m)
{
	for (int i = 0; i < 3; i++)
	{
		if (this->_inventory[i] == NULL)
		{
			this->_inventory[i] = m;
			//std::cout << "Learned new Materia" << m->getType() << std::endl;
			return ;
		}
	}
	//std::cout << "Can not learn new Materia" << std::endl;
	delete (m);
}

AMateria*	MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] != NULL && this->_inventory[i]->getType() == type)
			return (this->_inventory[i]->clone());
	}
	return (0);
}

/* ------------------------ SETTERS & GETTERS -------------------------- */

/* ---------------------------- OVERLOADS ------------------------------ */


MateriaSource		&MateriaSource::operator=(const MateriaSource &origin)
{
	(void)origin;
	return (*this);
}

std::ostream	&operator<<(std::ostream &stream, MateriaSource const &materiasource)
{
	(void)materiasource;
	return (stream);
}

