/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 00:11:17 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/03/02 05:36:44 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

/* ------------------- CONSTRUCTORS & DECONSTRUCORS -------------------- */

AForm::AForm(): 
	_name("Default Form"), _signed(false), _requiredGradeSign(1), _requiredGradeExecute(1) {}

AForm::~AForm()
{
	//std::cout << "Form Deconstructor called" << std::endl;
}

AForm::AForm(const AForm &src):
	_name(src._name), _signed(src._signed), _requiredGradeSign(src._requiredGradeSign), _requiredGradeExecute(src._requiredGradeSign) {}

AForm::AForm(std::string name, bool isSigned, int requiredGradeSign, int requiredGradeExecute): 
	_name(name), _signed(isSigned), _requiredGradeSign(requiredGradeSign), _requiredGradeExecute(requiredGradeExecute) {}

/* ----------------------------- METHODS ------------------------------- */

void		AForm::beSigned(Bureaucrat bureaucrat)
{
	if (bureaucrat.getGrade() <= this->getRequiredGradeSign() && this->_signed == false)
		this->_signed = true;
	else
		throw GradeTooLowException();
}

void		AForm::execute(Bureaucrat const &burueaucrat) const
{
	if (!this->getSigned())
		throw AForm::FormNotSigned();
	if (burueaucrat.getGrade() > this->getRequiredGradeExecute())
		throw AForm::GradeTooLowException();
	this->getExecuted(burueaucrat);
}

/* ------------------------ SETTERS & GETTERS -------------------------- */

std::string	AForm::getName() const
{
	return this->_name;
}

bool		AForm::getSigned() const
{
	return this->_signed;
}

int	AForm::getRequiredGradeSign() const
{
	return this->_requiredGradeSign;
}

int	AForm::getRequiredGradeExecute() const
{
	return this->_requiredGradeExecute;
}

/* --------------------------- EXCEPTIONS ------------------------------ */

const char*	AForm::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char*	AForm::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

const char*	AForm::FormNotSigned::what() const throw()
{
	return "Could not execute form as not signed";
}

/* ---------------------------- OVERLOADS ------------------------------ */

AForm		&AForm::operator=(const AForm &origin)
{
	if (this != &origin)
		this->_signed = origin.getSigned();
	return *this;
}

std::ostream	&operator<<(std::ostream &stream, AForm const &form)
{
	stream << form.getName()
		   << " is " << (form.getSigned() ? "signed. " : "not signed. ")
		   << "Required sign grade: " << form.getRequiredGradeSign()
		   << " Required execute grade: " << form.getRequiredGradeExecute()
		   << std::endl;
	return (stream);
}

