/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 18:31:27 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/05/02 19:07:23 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <FileReader.hpp>

int main( int argc, char *argv[] )
{
	if (argc != 2)
		return (0); // TODO
	FileReader	fileReader(argv[1]);
	//std::cout << csvReader;
}