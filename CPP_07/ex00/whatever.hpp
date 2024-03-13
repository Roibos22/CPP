/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 23:54:53 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/03/07 01:41:33 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <iostream>

template <typename T>
void	swap(T &a, T &b)
{
	T	tmp = a;
	a = b;
	b = tmp;
}

template <typename T>
T		min(T &a, T &b)
{
	return (a < b ? a : b);
}

template <typename T>
T		max(T &a, T &b)
{
	return (a > b ? a : b);
}

#endif