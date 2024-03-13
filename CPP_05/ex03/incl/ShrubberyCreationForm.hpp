/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 22:32:28 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/02/29 22:32:31 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include "AForm.hpp"
#include "fstream"

class	ShrubberyCreationForm: public AForm
{
	public:
		/* --------- CONSTRUCTORS & DECONSTRUCORS ---------- */
		ShrubberyCreationForm();
		~ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm &shrubberycreationform);
		ShrubberyCreationForm(std::string target);

		/* ------------------- METHODS --------------------- */
		void		getExecuted(Bureaucrat const &bureaucrat) const;

		/* -------------- SETTERS & GETTERS ---------------- */
		std::string	getTarget() const;

		/* ------------------- GETTERS --------------------- */

		/* ------------------ OVERLOADS -------------------- */
		ShrubberyCreationForm	&operator=(const ShrubberyCreationForm &);

	protected:
	
	private:
		std::string	_target;

};

//std::ostream	&operator<<(std::ostream &stream, ShrubberyCreationForm const &shrubberycreationform);

#endif // ShrubberyCreationForm_HPP
