/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 20:45:15 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/04/29 20:21:17 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main(void)
{
	Data*	data = new Data;
	data->magicNumber = 42;
	data->magicString = "42Berlin";

	std::cout << "Original: " << data->magicNumber << " & " << data->magicString << std::endl;

	uintptr_t	serialized = Serializer::serialize(data);
	std::cout << "Serialized: " << serialized << std::endl;

	Data		*deserialized = Serializer::deserialize(serialized);
	std::cout << "Deserialized: " << deserialized->magicNumber << " & " << deserialized->magicString << std::endl;

	delete (data);
}
