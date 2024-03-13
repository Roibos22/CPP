/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 20:01:25 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/02/29 21:30:10 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/* ------------------- CONSTRUCTORS & DECONSTRUCORS -------------------- */

Bureaucrat::Bureaucrat():
	_name("Default"), _grade(42) { }

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	else
		this->_grade = grade;
}

Bureaucrat::~Bureaucrat() { }

Bureaucrat::Bureaucrat(const Bureaucrat &src): 
	_name(src._name), _grade(src._grade) { }

/* ----------------------------- METHODS ------------------------------- */

void		Bureaucrat::incrementGrade()
{
	if (this->_grade == 1)
		throw GradeTooHighException();
	else
		this->_grade--;
}

void		Bureaucrat::decrementGrade()
{
	if (this->_grade == 150)
		throw GradeTooLowException();
	else
		this->_grade++;
}

void		Bureaucrat::signForm(AForm &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->getName() << " signed " << form.getName() << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << this->getName() << " could not sign " << form.getName() << std::endl;
	}
}

void		Bureaucrat::executeForm(AForm const &form)
{
	try
	{
		form.execute(*this);
		std::cout << this->getName() << " executed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

/* ------------------------ SETTERS & GETTERS -------------------------- */

std::string	Bureaucrat::getName() const
{
	return (this->_name);
}

int			Bureaucrat::getGrade() const
{
	return (this->_grade);
}

/* --------------------------- EXCEPTIONS ------------------------------ */

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

/* ---------------------------- OVERLOADS ------------------------------ */

Bureaucrat		&Bureaucrat::operator=(const Bureaucrat &origin)
{
	if (this != &origin)
		this->_grade = origin.getGrade();
	return *this;
}

std::ostream	&operator<<(std::ostream &stream, Bureaucrat const &bureaucrat)
{
	stream << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
	return (stream);
}
