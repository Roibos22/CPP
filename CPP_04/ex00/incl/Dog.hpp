/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 19:22:20 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/02/19 20:31:58 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include <iostream>
#include "Animal.hpp"

class	Dog: public Animal
{
	public:
		/* --------- CONSTRUCTORS & DECONSTRUCORS ---------- */
		Dog();
		~Dog();
		Dog(const Dog &animal);
		/* ------------------- METHODS --------------------- */
		void		makeSound(void) const;

		/* ------------------- SETTERS --------------------- */

		/* ------------------- GETTERS --------------------- */
		std::string		getType() const;

		/* ------------------ OVERLOADS -------------------- */
		Dog	&operator=(const Dog &copy);

	protected:
		std::string	_type;

	private:

};

std::ostream	&operator<<(std::ostream &stream, Dog const &dog);

#endif