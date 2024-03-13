/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 21:19:47 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/02/19 21:22:01 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include <iostream>
#include "WrongAnimal.hpp"

class	WrongCat: public WrongAnimal
{
	public:
		/* --------- CONSTRUCTORS & DECONSTRUCORS ---------- */
		WrongCat();
		~WrongCat();
		WrongCat(const WrongCat &wrongcat);

		/* ------------------- METHODS --------------------- */
		void		makeSound(void) const;

		/* ------------------- SETTERS --------------------- */

		/* ------------------- GETTERS --------------------- */
		std::string		getType() const;

		/* ------------------ OVERLOADS -------------------- */
		WrongCat	&operator=(const WrongCat &);

	protected:
		std::string	_type;

	private:

};

std::ostream	&operator<<(std::ostream &stream, WrongCat const &wrongCat);

#endif // WrongCat_HPP
