/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 19:44:12 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/02/20 18:24:58 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class	Cat: public Animal
{
	public:
		/* --------- CONSTRUCTORS & DECONSTRUCORS ---------- */
		Cat();
		~Cat();
		Cat(const Cat &cat);

		/* ------------------- METHODS --------------------- */
		void		makeSound(void) const;
		void		print(std::ostream &stream) const;

		/* ------------------- SETTERS --------------------- */

		/* ------------------- GETTERS --------------------- */
		std::string		getType() const;
		Brain*			getBrain(void) const;

		/* ------------------ OVERLOADS -------------------- */
		Cat	&operator=(const Cat &);

	protected:
		std::string	_type;

	private:
		Brain		*_brain;
};

#endif
