/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 05:39:11 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/02/29 22:25:00 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"
#include <cstdlib>

/* ------------------- CONSTRUCTORS & DECONSTRUCORS -------------------- */

RobotomyRequestForm::RobotomyRequestForm():
	AForm("Robotomy Request Form", false, 72, 45) { }

RobotomyRequestForm::~RobotomyRequestForm()
{
	//std::cout << "Robotomy Request Form Deconstructor called" << std::endl;
}

//RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &robotomyRequestForm) { *this = robotomyRequestForm; }

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &copy)
		: AForm((AForm &)copy)	{}

RobotomyRequestForm::RobotomyRequestForm(std::string target):
	AForm("Robotomy Request Form", false, 72, 45), _target(target) { }

/* ----------------------------- METHODS ------------------------------- */

void	RobotomyRequestForm::getExecuted(Bureaucrat const &) const
{
	std::cout << "Drilllllllllllllllll" << std::endl;
	if (rand() % 2)
		std::cout << this->_target << " has been robotomized!" << std::endl;
	else
		std::cout << "Executed this time!" << std::endl;
}

/* ------------------------ SETTERS & GETTERS -------------------------- */

std::string	RobotomyRequestForm::getTarget() const
{
	return this->_target;
}

/* ---------------------------- OVERLOADS ------------------------------ */

RobotomyRequestForm		&RobotomyRequestForm::operator=(const RobotomyRequestForm &origin)
{
	if (this != &origin)
		this->_target = origin.getTarget();
	return *this;
}

std::ostream	&operator<<(std::ostream &stream, RobotomyRequestForm const &robotomyRequestForm)
{
	stream << robotomyRequestForm.getName() << std::endl;
	return (stream);
}

