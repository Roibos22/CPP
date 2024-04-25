/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 15:08:04 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/04/25 17:44:01 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

/* ------------------- CONSTRUCTORS & DECONSTRUCORS -------------------- */

template <typename T>
MutantStack<T>::MutantStack() { return; }

template <typename T>
MutantStack<T>::~MutantStack() { return; }

template <typename T>
MutantStack<T>::MutantStack(const MutantStack &mutantstack) { *this = mutantstack; }

/* ----------------------------- METHODS ------------------------------- */

/* ------------------------ SETTERS & GETTERS -------------------------- */

/* --------------------------- EXCEPTIONS ------------------------------ */

/* ---------------------------- OVERLOADS ------------------------------ */

template <typename T>
MutantStack<T>		&MutantStack<T>::operator=(const MutantStack &origin)
{
	(void)origin;
	return (*this);
}

/*
std::ostream	&operator<<(std::ostream &stream, MutantStack const &mutantstack)
{
	(void)mutantstack;
	return (stream);
}
 */
