/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 23:15:56 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/02/29 23:12:02 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	{
		std::cout << "--- Test Shrubbery Form ---" << std::endl;
		ShrubberyCreationForm shrubb("shrubb");
		Bureaucrat	Harry("Harry", 150);
		Bureaucrat	Ron("Ron", 1);
		std::cout << shrubb << Harry << Ron;
		Harry.executeForm(shrubb);
		Ron.executeForm(shrubb);
		Harry.signForm(shrubb);
		Ron.signForm(shrubb);
		Harry.executeForm(shrubb);
		Ron.executeForm(shrubb);
	}

	{
		std::cout << std::endl << "--- Test Robotomy Form ---" << std::endl;
		RobotomyRequestForm robo("robo");
		Bureaucrat	Harry("Harry", 150);
		Bureaucrat	Ron("Ron", 1);
		std::cout << robo << Harry << Ron;
		Harry.executeForm(robo);
		Ron.executeForm(robo);
		Harry.signForm(robo);
		Ron.signForm(robo);
		Harry.executeForm(robo);
		Ron.executeForm(robo);
	}

	{
		std::cout << std::endl << "--- Test Presidential Form ---" << std::endl;
		PresidentialPardonForm presi("presi");
		Bureaucrat	Harry("Harry", 150);
		Bureaucrat	Ron("Ron", 1);
		std::cout << presi << Harry << Ron;
		Harry.executeForm(presi);
		Ron.executeForm(presi);
		Harry.signForm(presi);
		Ron.signForm(presi);
		Harry.executeForm(presi);
		Ron.executeForm(presi);
	}
}