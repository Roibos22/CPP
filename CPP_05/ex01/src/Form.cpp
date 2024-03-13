/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 00:11:17 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/03/02 05:37:17 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

/* ------------------- CONSTRUCTORS & DECONSTRUCORS -------------------- */

Form::Form(): 
	_name("Default Form"), _signed(false), _requiredGradeSign(1), _requiredGradeExecute(1) {}

Form::~Form()
{
	//std::cout << "Form Deconstructor called" << std::endl;
}

Form::Form(const Form &src):
	_name(src._name), _signed(src._signed), _requiredGradeSign(src._requiredGradeSign), _requiredGradeExecute(src._requiredGradeSign) {}

Form::Form(std::string name, bool isSigned, int requiredGradeSign, int requiredGradeExecute): 
	_name(name), _signed(isSigned), _requiredGradeSign(requiredGradeSign), _requiredGradeExecute(requiredGradeExecute) {}

/* ----------------------------- METHODS ------------------------------- */

void		Form::beSigned(Bureaucrat bureaucrat)
{
	if (bureaucrat.getGrade() <= this->getRequiredGradeSign() && this->_signed == false)
		this->_signed = true;
	else
		throw GradeTooLowException();
}

/* ------------------------ SETTERS & GETTERS -------------------------- */

std::string	Form::getName() const
{
	return this->_name;
}

bool		Form::getSigned() const
{
	return this->_signed;
}

int	Form::getRequiredGradeSign() const
{
	return this->_requiredGradeSign;
}

int	Form::getRequiredGradeExecute() const
{
	return this->_requiredGradeExecute;
}

/* --------------------------- EXCEPTIONS ------------------------------ */

const char*	Form::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char*	Form::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

/* ---------------------------- OVERLOADS ------------------------------ */

Form		&Form::operator=(const Form &origin)
{
	if (this != &origin)
		this->_signed = origin.getSigned();
	return *this;
}

std::ostream	&operator<<(std::ostream &stream, Form const &form)
{
	stream << form.getName()
		   << " is " << (form.getSigned() ? "signed. " : "not signed. ")
		   << "Required sign grade: " << form.getRequiredGradeSign()
		   << " Required execute grade: " << form.getRequiredGradeExecute()
		   << std::endl;
	return (stream);
}

