/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 01:51:41 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/04/30 14:30:17 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int	main(void)
{
	int		intArr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	char	charArr[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g'};

	iter(intArr, 10, printGeneric<int>);
	iter(charArr, 7, printGeneric<char>);
}
