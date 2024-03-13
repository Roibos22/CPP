/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 21:01:33 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/02/20 23:32:16 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include <iostream>
#include "IMateriaSource.hpp"

class	MateriaSource: public IMateriaSource
{
	public:
		/* --------- CONSTRUCTORS & DECONSTRUCORS ---------- */
		MateriaSource();
		~MateriaSource();
		MateriaSource(const MateriaSource &materiasource);

		/* ------------------- METHODS --------------------- */
		void		learnMateria(AMateria*);
		AMateria*	createMateria(std::string const &type);

		/* -------------- SETTERS & GETTERS ---------------- */

		/* ------------------- GETTERS --------------------- */

		/* ------------------ OVERLOADS -------------------- */
		MateriaSource	&operator=(const MateriaSource &);

	protected:
	
	private:
		AMateria*	_inventory[4];
};

std::ostream	&operator<<(std::ostream &stream, MateriaSource const &materiasource);

#endif // MateriaSource_HPP
