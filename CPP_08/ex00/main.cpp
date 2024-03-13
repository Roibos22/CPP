/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 21:45:42 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/03/10 06:12:01 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int	main(void)
{
	/* Other way to create a vector
	std::vector<int>vec;
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(5);
	vec.push_back(7);
	vec.push_back(11); */

	static const int			arr[] = {2, 3, 5, 7, 11};
	std::vector<int>			vec(arr, arr + sizeof(arr) / sizeof(arr[0]));
	std::vector<int>::iterator	it;

	for (int i = 0; i < 14; i++)
	{
		try
		{
			it = easyfind(vec, i);
			std::cout << "Found value: " << i << " at index " << *it << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
}