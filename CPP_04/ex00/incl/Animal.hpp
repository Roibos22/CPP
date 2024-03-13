/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 19:22:20 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/02/19 20:33:52 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class	Animal
{
	private:

	protected:
		std::string	_type;

	public:
		// DE/CONSTRUCTORS
		Animal();
		virtual ~Animal();
		Animal(const Animal &animal);
		Animal	&operator=(const Animal &copy);

		// METHODS
		virtual void	makeSound(void) const;

		// SETTERS
		void			setType(std::string type);

		// GETTERS
		virtual std::string		getType() const;

};

std::ostream	&operator<<(std::ostream &stream, Animal const &animal);

#endif