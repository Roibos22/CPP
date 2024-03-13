/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 23:15:56 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/02/29 05:22:47 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	Form		easyForm("Easy Form", false, 150, 150);
	Form		hardForm("Hard Form", false, 1, 1);
	Form		signedForm("Signed Form", true, 150, 150);
	Bureaucrat	Albus("Albus", 42);


	std::cout << "--- Test Sign Form possible ---" << std::endl;
	std::cout << easyForm;
	Albus.signForm(easyForm);
	std::cout << easyForm << std::endl;

	std::cout << "--- Test Sign Form not possible---" << std::endl;
	std::cout << hardForm;
	Albus.signForm(hardForm);
	std::cout << hardForm << std::endl;

	std::cout << "--- Test Sign Form already signed ---" << std::endl;
	std::cout << signedForm;
	Albus.signForm(signedForm);
	std::cout << signedForm << std::endl;
}