/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 20:41:39 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/03/06 21:29:57 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

/* ------------------- CONSTRUCTORS & DECONSTRUCORS -------------------- */

Serializer::Serializer()
{
	//std::cout << "Serializer Default Constructor called" << std::endl;
}

Serializer::~Serializer()
{
	//std::cout << "Serializer Deconstructor called" << std::endl;
}

Serializer::Serializer(const Serializer &serializer) { *this = serializer; }

/* ----------------------------- METHODS ------------------------------- */

uintptr_t	Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data*		Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}

/* ------------------------ SETTERS & GETTERS -------------------------- */

/* ---------------------------- OVERLOADS ------------------------------ */


Serializer		&Serializer::operator=(const Serializer &origin)
{
	if (this != &origin)
		return *this;
	return *this;
}

std::ostream	&operator<<(std::ostream &stream, Serializer const &serializer)
{
	(void)serializer;
	stream << "Serializer" << std::endl;
	return (stream);
}

