/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 03:06:56 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/03/07 20:43:47 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

/* --------- CONSTRUCTORS & DECONSTRUCORS ---------- */
template <typename T>
Array<T>::Array(): _array(NULL), _size(0) { }

template <typename T>
Array<T>::Array(unsigned int n): _array(new T[n]), _size(n) { }

template <typename T>
Array<T>::Array(const Array &array)
{
	_size = array._size;
	if (_size == 0)
		_array = NULL;
	else
	{
		_array = new T[_size];
		for (int i = 0; i < array._size; i++)
			_array[i] = array._array[i];
	}
}

template <typename T>
Array<T>::~Array()
{
	delete [] (this->_array);
}

/* ------------------- METHODS --------------------- */
template <typename T>
int	Array<T>::size()
{
	return (this->_size);
}

/* ------------------ OVERLOADS -------------------- */
template <typename T>
T	&Array<T>::operator[](const int n)
{
	if (n < 0 || n >= this->_size)
		throw Array::IndexOutOfBounds();
	else
		return (_array[n]);
}

template <typename T>
Array<T>	&Array<T>::operator=(const Array<T> &src)
{
	if (this != &src)
	{
		delete [] this->_array;
		this->_size = src._size;
		this->_array = new T[this->_size];
		for (int i = 0; i < this->_size; i++)
			this->_array[i] = src._array[i];
	}
	return (*this);
}
