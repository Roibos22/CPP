/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 20:15:27 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/02/25 19:38:36 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

#include <iostream>
#include "AMateria.hpp"

class	AMateria;

class	ICharacter
{
	public:
		/* --------- CONSTRUCTORS & DECONSTRUCORS ---------- */
		virtual ~ICharacter() {};

		/* ------------------- METHODS --------------------- */
		virtual void equip(AMateria* m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use(int idx, ICharacter& target) = 0;

		/* -------------- SETTERS & GETTERS ---------------- */
		virtual std::string const & getName() const = 0;

		/* ------------------- GETTERS --------------------- */

		/* ------------------ OVERLOADS -------------------- */
		ICharacter	&operator=(const ICharacter &);

	protected:
	
	private:

};

std::ostream	&operator<<(std::ostream &stream, ICharacter const &icharacter);

#endif // ICharacter_HPP
