/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 02:20:00 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/03/02 03:54:28 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "AForm.hpp"

class	Intern
{
	public:
		/* --------- CONSTRUCTORS & DECONSTRUCORS ---------- */
		Intern();
		~Intern();
		Intern(const Intern &intern);

		/* ------------------- METHODS --------------------- */
		AForm	*makeForm(std::string formName, std::string target) const;

		/* -------------- SETTERS & GETTERS ---------------- */

		/* ------------------ EXCEPTIONS ------------------- */
		class	FormCreationError: public std::exception
		{
			// Overrides what() from exception class while not able to throw
			virtual const char	*what() const throw();
		};

		/* ------------------ OVERLOADS -------------------- */
		Intern	&operator=(const Intern &);

	protected:
	
	private:

};

std::ostream	&operator<<(std::ostream &stream, Intern const &intern);

#endif // Intern_HPP
