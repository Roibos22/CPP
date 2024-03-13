/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 02:48:53 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/03/09 23:02:30 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>

template <typename T>
class	Array
{
	public:
		/* --------- CONSTRUCTORS & DECONSTRUCORS ---------- */
		Array();
		Array(unsigned int n);
		Array(const Array &array);
		~Array();

		/* ------------------- METHODS --------------------- */
		int	size();

		/* -------------- SETTERS & GETTERS ---------------- */

		/* ------------------ EXCEPTIONS ------------------- */
		class	IndexOutOfBounds: public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Error: index is out of bounds");
				}
		};

		/* ------------------ OVERLOADS -------------------- */
		Array	&operator=(const Array &src);
		T		&operator[](const int n);

	protected:
	
	private:
		T*		_array;
		int		_size;
};

//std::ostream	&operator<<(std::ostream &stream, Array const &array);

#include "Array.tpp"

#endif // Array_HPP
