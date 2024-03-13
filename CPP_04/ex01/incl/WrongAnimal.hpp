/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 20:42:07 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/02/19 21:27:43 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class	WrongAnimal
{
	public:
		/* --------- CONSTRUCTORS & DECONSTRUCORS ---------- */
		WrongAnimal();
		~WrongAnimal();
		WrongAnimal(const WrongAnimal &wrongAnimal);

		/* ------------------- METHODS --------------------- */
		void	makeSound(void) const;

		/* ------------------- SETTERS --------------------- */
		void			setType(std::string type);

		/* ------------------- GETTERS --------------------- */
		std::string		getType() const;

		/* ------------------ OVERLOADS -------------------- */
		WrongAnimal	&operator=(const WrongAnimal &);

	protected:
		std::string	_type;

	private:

};

std::ostream	&operator<<(std::ostream &stream, WrongAnimal const &wronganimal);

#endif // WrongAnimal_HPP
