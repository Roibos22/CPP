/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 02:19:58 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/03/02 04:42:31 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

/* ------------------- CONSTRUCTORS & DECONSTRUCORS -------------------- */

Intern::Intern() { }

Intern::~Intern() { }

Intern::Intern(const Intern &intern) { *this = intern; }

/* ----------------------------- METHODS ------------------------------- */

AForm*	Intern::makeForm(std::string formName, std::string target) const
{
	std::string forms[] = {"Shrubbery Creation Form", "Robotomy Request Form", "Presidential Pardon Form"};
	int			i = 0;

	while (i < 3)
	{
		if (forms[i] == formName)
			break ;
		i++;
	}
	std::cout << i << std::endl;
	switch(i)
	{
		case 0:
			std::cout << "Intern creates " << forms[i] << std::endl;
			return (new ShrubberyCreationForm(target));
		case 1:
			std::cout << "Intern creates " << forms[i] << std::endl;
			return (new RobotomyRequestForm(target));
		case 2:
			std::cout << "Intern creates " << forms[i] << std::endl;
			return (new PresidentialPardonForm(target));
		default:
			//delete [] forms;
			throw Intern::FormCreationError();
	}
	return (NULL);
}


/* ------------------------ SETTERS & GETTERS -------------------------- */

/* ---------------------------- EXCEPTIONS ----------------------------- */

const char*	Intern::FormCreationError::what() const throw()
{
	return "Could not create form";
}

/* ---------------------------- OVERLOADS ------------------------------ */

Intern		&Intern::operator=(const Intern &origin)
{
	if (this != &origin)
		return *this;
	return *this;
}

std::ostream	&operator<<(std::ostream &stream, Intern const &intern)
{
	(void)intern;

	stream << "Some Intern" << std::endl;
	return (stream);
}

