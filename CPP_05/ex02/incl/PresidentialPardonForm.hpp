/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 22:32:28 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/02/29 23:00:03 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include "AForm.hpp"
#include "fstream"

class	PresidentialPardonForm: public AForm
{
	public:
		/* --------- CONSTRUCTORS & DECONSTRUCORS ---------- */
		PresidentialPardonForm();
		~PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm &presidentialPardonForm);
		PresidentialPardonForm(std::string target);

		/* ------------------- METHODS --------------------- */
		void		getExecuted(Bureaucrat const &bureaucrat) const;

		/* -------------- SETTERS & GETTERS ---------------- */
		std::string	getTarget() const;

		/* ------------------- GETTERS --------------------- */

		/* ------------------ OVERLOADS -------------------- */
		PresidentialPardonForm	&operator=(const PresidentialPardonForm &);

	protected:
	
	private:
		std::string	_target;

};

//std::ostream	&operator<<(std::ostream &stream, ShrubberyCreationForm const &shrubberycreationform);

#endif // PresidentialPardonForm_HPP
