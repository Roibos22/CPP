/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 19:35:54 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/05/03 20:58:01 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

// TODO: segfaults
// TODO: expression does not end in 1 number

int main( int argc, char *argv[])
{
	if (argc != 2)
		std::cerr << "Error" << std::endl;
	else
	{
		RPN rpn(argv[1]);
		rpn.calculate();
	}
}