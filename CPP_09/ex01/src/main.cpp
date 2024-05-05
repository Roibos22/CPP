/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leon <leon@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 19:35:54 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/05/05 18:50:35 by leon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

// TODO: segfaults
// TODO: expression does not end in 1 number
	// make it so if it does not end in one number the rest is just printed

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