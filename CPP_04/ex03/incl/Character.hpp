/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 19:51:58 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/02/25 19:38:45 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include "ICharacter.hpp"
#include "AMateria.hpp"

class	Character: public ICharacter
{
	public:
		/* --------- CONSTRUCTORS & DECONSTRUCORS ---------- */
		Character();
		Character(std::string name);
		~Character();
		Character(const Character &character);

		/* ------------------- METHODS --------------------- */
		void	equip(AMateria* m);
		void	unequip(int idx);
		void	use(int idx, ICharacter& target);

		/* -------------- SETTERS & GETTERS ---------------- */
		void		setName(std::string name);
		std::string const & getName() const;

		/* ------------------- GETTERS --------------------- */

		/* ------------------ OVERLOADS -------------------- */
		Character	&operator=(const Character &);

	protected:
	
	private:
		AMateria*	_inventory[4];
		std::string	_name;
};

std::ostream	&operator<<(std::ostream &stream, Character const &character);

#endif // Character_HPP
