/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 01:56:40 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/04/30 14:30:32 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#ifndef ITER_HPP
# define ITER_HPP

class Awesome;

template<typename T, typename F>
void iter(T arr[], size_t len, F func)
{
	for (size_t i = 0; i < len; ++i) {
		func(arr[i]);
	}
	std::cout << std::endl;
}

template <typename T>
void	printGeneric(T &a)
{
	std::cout << a << std::endl;
}

#endif // ITER_HPP
