/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 19:44:32 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/02/20 21:18:31 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include <iostream>
#include "AMateria.hpp"

class	Ice: public AMateria
{
	public:
		/* --------- CONSTRUCTORS & DECONSTRUCORS ---------- */
		Ice();
		~Ice();
		Ice(const Ice &ice);

		/* ------------------- METHODS --------------------- */
		Ice*	clone(void) const;
		void	use(ICharacter &target);
		/* -------------- SETTERS & GETTERS ---------------- */

		/* ------------------- GETTERS --------------------- */

		/* ------------------ OVERLOADS -------------------- */
		Ice	&operator=(const Ice &);

	protected:
	
	private:

};

#endif // Ice_HPP
