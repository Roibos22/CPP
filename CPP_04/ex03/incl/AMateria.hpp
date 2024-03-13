/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 19:34:36 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/02/25 19:32:48 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include "ICharacter.hpp"

class	ICharacter;

class	AMateria
{
	public:
		/* --------- CONSTRUCTORS & DECONSTRUCORS ---------- */
		AMateria();
		virtual ~AMateria();
		AMateria(const AMateria &aMateria);

		AMateria(std::string const & type);

		/* ------------------- METHODS --------------------- */
		virtual AMateria*	clone(void) const = 0;
		virtual void		use(ICharacter &target);

		/* -------------- SETTERS & GETTERS ---------------- */
		std::string			const &getType() const;
		void				setType(std::string);
	
		/* ------------------ OVERLOADS -------------------- */
		AMateria	&operator=(const AMateria &);

	protected:
		std::string	_type;

	private:
};

#endif // AMateria_HPP
