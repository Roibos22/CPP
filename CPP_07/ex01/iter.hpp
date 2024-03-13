/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 01:56:40 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/03/07 02:13:32 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#ifndef ITER_HPP
# define ITER_HPP

template <typename T>
void	iter(T arr[], size_t len, void func(const T&))
{
	for (size_t i = 0; i < len; ++i)
		func(arr[i]);
	std:: cout << std::endl;
}

template <typename T>
void	printGeneric(T &a)
{
	std::cout << a << " ";
}

#endif // ITER_HPP
