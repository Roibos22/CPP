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

#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include <cstdlib>

/* ------------------- CONSTRUCTORS & DECONSTRUCORS -------------------- */

PresidentialPardonForm::PresidentialPardonForm():
	AForm("Presidential Pardon Form", false, 25, 5) { }

PresidentialPardonForm::~PresidentialPardonForm()
{
	//std::cout << "Presidential Pardon Form Deconstructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &presidentialPardonForm) { *this = presidentialPardonForm; }

PresidentialPardonForm::PresidentialPardonForm(std::string target):
	AForm("Presidential Pardon Form", false, 25, 5), _target(target) { }

/* ----------------------------- METHODS ------------------------------- */

void	PresidentialPardonForm::getExecuted(Bureaucrat const &) const
{
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

/* ------------------------ SETTERS & GETTERS -------------------------- */

std::string	PresidentialPardonForm::getTarget() const
{
	return this->_target;
}

/* ---------------------------- OVERLOADS ------------------------------ */

PresidentialPardonForm		&PresidentialPardonForm::operator=(const PresidentialPardonForm &origin)
{
	if (this != &origin)
		this->_target = origin.getTarget();
	return *this;
}

std::ostream	&operator<<(std::ostream &stream, PresidentialPardonForm const &presidentialPardonForm)
{
	stream << presidentialPardonForm.getName() << std::endl;
	return (stream);
}

