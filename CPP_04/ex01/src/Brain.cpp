/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:51:38 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/02/20 16:18:09 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

/* ------------------- CONSTRUCTORS & DECONSTRUCORS -------------------- */

Brain::Brain()
{
	std::cout << "Brain Default Constructor called" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain Deconstructor called" << std::endl;
}

Brain::Brain(const Brain &brain) { *this = brain; }

/* ----------------------------- METHODS ------------------------------- */

/* ----------------------------- SETTERS ------------------------------- */

void		Brain::setIdea(int i, std::string idea)
{
	this->_ideas[i] = idea;
}

/* ----------------------------- GETTERS ------------------------------- */

std::string	Brain::getIdea(int i) const
{
	return (this->_ideas[i]);
}

/* ---------------------------- OVERLOADS ------------------------------ */


Brain		&Brain::operator=(const Brain &origin)
{
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = origin._ideas[i];
	return (*this);
}

std::ostream	&operator<<(std::ostream &stream, Brain const &brain)
{
	stream << brain.getIdea(0) << std::endl;
	return (stream);
}

