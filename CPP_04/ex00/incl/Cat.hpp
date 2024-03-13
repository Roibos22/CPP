/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 19:44:12 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/02/19 20:31:10 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include "Animal.hpp"

class	Cat: public Animal
{
	public:
		/* --------- CONSTRUCTORS & DECONSTRUCORS ---------- */
		Cat();
		~Cat();
		Cat(const Cat &cat);

		/* ------------------- METHODS --------------------- */
		void		makeSound(void) const;

		/* ------------------- SETTERS --------------------- */

		/* ------------------- GETTERS --------------------- */
		std::string		getType() const;

		/* ------------------ OVERLOADS -------------------- */
		Cat	&operator=(const Cat &);

	protected:
		std::string	_type;

	private:

};

std::ostream	&operator<<(std::ostream &stream, Cat const &cat);

#endif // Cat_HPP
