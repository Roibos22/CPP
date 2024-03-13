/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 00:11:15 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/03/01 03:20:36 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class	AForm
{
	public:
		/* --------- CONSTRUCTORS & DECONSTRUCORS ---------- */
		AForm();
		virtual ~AForm();
		AForm(const AForm &form);
		AForm(std::string name, bool isSigned, int requiredGradeSign, int requiredGradeExecute);

		/* ------------------- METHODS --------------------- */
		void			beSigned(Bureaucrat bureaucrat);
		void			execute(Bureaucrat const &bureaucrat) const;
		virtual void	getExecuted(Bureaucrat const &bureaucrat) const = 0;

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
		class	FormNotSigned: public std::exception
		{
			virtual const char	*what() const throw();
		};

		/* ------------------ OVERLOADS -------------------- */
		AForm	&operator=(const AForm &);

	protected:
	
	private:
		const std::string	_name;
		bool				_signed;
		const int			_requiredGradeSign;
		const int			_requiredGradeExecute;
};

std::ostream	&operator<<(std::ostream &stream, AForm const &form);

#endif // AForm_HPP
