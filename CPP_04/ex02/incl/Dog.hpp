/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 19:22:20 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/02/20 18:25:37 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class	Dog: public Animal
{
	public:
		/* --------- CONSTRUCTORS & DECONSTRUCORS ---------- */
		Dog();
		~Dog();
		Dog(const Dog &animal);

		/* ------------------- METHODS --------------------- */
		void		makeSound(void) const;
		void		print(std::ostream &stream) const;

		/* ------------------- SETTERS --------------------- */

		/* ------------------- GETTERS --------------------- */
		std::string		getType() const;
		Brain*			getBrain(void) const;

		/* ------------------ OVERLOADS -------------------- */
		Dog	&operator=(const Dog &copy);

	protected:
		std::string	_type;

	private:
		Brain		*_brain;
};

#endif