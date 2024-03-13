/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 00:11:15 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/02/29 05:08:09 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class	Form
{
	public:
		/* --------- CONSTRUCTORS & DECONSTRUCORS ---------- */
		Form();
		~Form();
		Form(const Form &form);
		Form(std::string name, bool isSigned, int requiredGradeSign, int requiredGradeExecute);

		/* ------------------- METHODS --------------------- */
		void		beSigned(Bureaucrat bureaucrat);

		/* -------------- SETTERS & GETTERS ---------------- */
		std::string	getName() const;
		bool		getSigned() const;
		int			getRequiredGradeSign() const;
		int			getRequiredGradeExecute() const;

		/* ----------------- EXCEPTIONS -------------------- */
		class	GradeTooHighException: public std::exception
		{
			// Overrides what() from exception class while not able to throw
			virtual const char	*what() const throw();
		};
		class	GradeTooLowException: public std::exception
		{
			virtual const char	*what() const throw();
		};

		/* ------------------ OVERLOADS -------------------- */
		Form	&operator=(const Form &);

	protected:
	
	private:
		const std::string	_name;
		bool				_signed;
		const int			_requiredGradeSign;
		const int			_requiredGradeExecute;
};

std::ostream	&operator<<(std::ostream &stream, Form const &form);

#endif // Form_HPP
