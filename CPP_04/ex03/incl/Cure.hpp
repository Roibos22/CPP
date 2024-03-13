/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 19:44:40 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/02/20 23:14:28 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include <iostream>
#include "AMateria.hpp"

class	Cure: public AMateria
{
	public:
		/* --------- CONSTRUCTORS & DECONSTRUCORS ---------- */
		Cure();
		~Cure();
		Cure(const Cure &cure);

		/* ------------------- METHODS --------------------- */
		Cure*	clone(void) const;
		void	use(ICharacter &target);

		/* -------------- SETTERS & GETTERS ---------------- */

		/* ------------------- GETTERS --------------------- */

		/* ------------------ OVERLOADS -------------------- */
		Cure	&operator=(const Cure &);

	protected:
	
	private:

};

#endif // Cure_HPP
