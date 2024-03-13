/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 05:39:11 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/03/02 00:17:14 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"

/* ------------------- CONSTRUCTORS & DECONSTRUCORS -------------------- */

ShrubberyCreationForm::ShrubberyCreationForm():
	AForm("Shrubbery Creation Form", false, 145, 137) { }

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	//std::cout << "ShrubberyCreationForm Deconstructor called" << std::endl;
}

//ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &shrubberycreationform) { *this = shrubberycreationform; }

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &copy)
		: AForm((AForm &)copy)	{}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target):
	AForm("Shrubbery Creation Form", false, 145, 137), _target(target) { }

/* ----------------------------- METHODS ------------------------------- */

void	ShrubberyCreationForm::getExecuted(Bureaucrat const &) const
{
	std::string		filename = "./" + this->getTarget() + "_shruberry";
	std::ofstream	shrubbery(filename.c_str());

	shrubbery << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << std::endl;
	shrubbery << "MMMMMMMMMMMMMMMMMMMMMNk:'';0MMMMMMMMMMMMMMMMMMMMMM" << std::endl;
	shrubbery << "MMMMMMMMMMMMKdOWMMMXd,  .'lXMMMMMMMMMMMMMMMMMMMMMM" << std::endl;
	shrubbery << "MMMMMMMMMMMWo .OMWO,  .c0NWMMMMMMMMMMMMMMMMMMMMMMM" << std::endl;
	shrubbery << "MMMMMMMMMMMK, '0No.  ,OWNX0dlcloddkXMMMMMMMMMMMMMM" << std::endl;
	shrubbery << "MMMMMMMMMMMk. cKl  .lKOl,..       .kMMMMMMMMMMMMMM" << std::endl;
	shrubbery << "MMMMMMMMMMNc  oo.  :k:.    .cxkddd0WMMMMMMMMMMMMMM" << std::endl;
	shrubbery << "MMMMMMMMMM0' .;.  .;.   ;okXWMMMMMMMMMMMMMMMMMMMMM" << std::endl;
	shrubbery << "MMMMMMMMMM0'      .    cXMNOl::::clodONMMMMMMMMMMM" << std::endl;
	shrubbery << "MMMMMMMMMM0,          ;kd:,           cXMMMMMMMMMM" << std::endl;
	shrubbery << "MMMMMMMMMMk.         .;.     .;:::c,   :KMMMMMMMMM" << std::endl;
	shrubbery << "MMMMMMMMMMk.                'kWMMMMNkl. ,0MMMMMMMM" << std::endl;
	shrubbery << "MMMMMMMMMMK,              .lXMMMMMMMMNc  :NMMMMMMM" << std::endl;
	shrubbery << "MMMMMMMMMMWl              cNMMMMMMMMMK,  '0MMMMMMM" << std::endl;
	shrubbery << "MMMMMMMMMMMO'             ;XMMMMMMMWKo.   dMMMMMMM" << std::endl;
	shrubbery << "MMMMMMMMMMMWl              ;xO0NWXx;.    .xMMMMMMM" << std::endl;
	shrubbery << "MMMMMMMMMMMMk.                .';'      ,kNMMMMMMM" << std::endl;
	shrubbery << "MMMMMMMMMMMMO.                        ,xNMMMMMMMMM" << std::endl;
	shrubbery << "MMMMMMMMMMMWo                       .oXMMMMMMMMMMM" << std::endl;
	shrubbery << "MMMMMMMMMMWx.                      :0WMMMMMMMMMMMM" << std::endl;
	shrubbery << "MMMMMMMMMMMO'                    ,xNMMMMMMMMMMMMMM" << std::endl;
	shrubbery << "MMMMMMMMMMMW0,              .,cdONMMMMMMMMMMMMMMMM" << std::endl;
	shrubbery << "MMMMMMMMMMMMMXl.         .'o0NMMMMMMMMMMMMMMMMMMMM" << std::endl;
	shrubbery << "MMMMMMMMMMMMMMWO:.     .o0XMMMMMMMMMMMMMMMMMMMMMMM" << std::endl;
	shrubbery << "MMMMMMMMMMMMMMMMW0l'  'OWMMMMMMMMMMMMMMMMMMMMMMMMM" << std::endl;
	shrubbery << "MMMMMMMMMMMMMMMMMMMXdcOMMMMMMMMMMMMMMMMMMMMMMMMMMM" << std::endl;
	shrubbery.close();
}

/* ------------------------ SETTERS & GETTERS -------------------------- */

std::string	ShrubberyCreationForm::getTarget() const
{
	return this->_target;
}

/* ---------------------------- OVERLOADS ------------------------------ */

ShrubberyCreationForm		&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &origin)
{
	if (this != &origin)
		this->_target = origin.getTarget();
	return *this;
}

std::ostream	&operator<<(std::ostream &stream, ShrubberyCreationForm const &shrubberyCreationForm)
{
	stream << shrubberyCreationForm.getName() << std::endl;
	return (stream);
}

