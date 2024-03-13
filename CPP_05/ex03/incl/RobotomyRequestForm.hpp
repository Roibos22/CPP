/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 22:32:28 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/02/29 22:35:29 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include "AForm.hpp"
#include "fstream"

class	RobotomyRequestForm: public AForm
{
	public:
		/* --------- CONSTRUCTORS & DECONSTRUCORS ---------- */
		RobotomyRequestForm();
		~RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm &robotomyRequestForm);
		RobotomyRequestForm(std::string target);

		/* ------------------- METHODS --------------------- */
		void		getExecuted(Bureaucrat const &bureaucrat) const;

		/* -------------- SETTERS & GETTERS ---------------- */
		std::string	getTarget() const;

		/* ------------------- GETTERS --------------------- */

		/* ------------------ OVERLOADS -------------------- */
		RobotomyRequestForm	&operator=(const RobotomyRequestForm &);

	protected:
	
	private:
		std::string	_target;

};

//std::ostream	&operator<<(std::ostream &stream, ShrubberyCreationForm const &shrubberycreationform);

#endif // RobotomyRequestForm_HPP
