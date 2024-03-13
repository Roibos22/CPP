/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 20:59:04 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/02/20 21:00:34 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP
#define IMATERIASOURCE_HPP

#include <iostream>
#include "AMateria.hpp"

class	IMateriaSource
{
	public:
		/* --------- CONSTRUCTORS & DECONSTRUCORS ---------- */
		virtual ~IMateriaSource() {}
		virtual void		learnMateria(AMateria*) = 0;
		virtual AMateria*	createMateria(std::string const &type) = 0;

		/* ------------------- METHODS --------------------- */

		/* -------------- SETTERS & GETTERS ---------------- */

		/* ------------------- GETTERS --------------------- */

		/* ------------------ OVERLOADS -------------------- */

	protected:
	
	private:

};

#endif // IMateriaSource_HPP
