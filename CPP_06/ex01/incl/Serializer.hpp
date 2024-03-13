/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 20:41:37 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/03/11 00:16:23 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <stdint.h>
#include "Data.hpp"

class	Serializer
{
	public:
		/* ------------------- METHODS --------------------- */
		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);

		/* -------------- SETTERS & GETTERS ---------------- */

		/* ------------------- GETTERS --------------------- */

		/* ------------------ OVERLOADS -------------------- */
		Serializer	&operator=(const Serializer &);

	protected:
	
	private:
		/* --------- CONSTRUCTORS & DECONSTRUCORS ---------- */
		Serializer();
		~Serializer();
		Serializer(const Serializer &serializer);
};

std::ostream	&operator<<(std::ostream &stream, Serializer const &serializer);

#endif // Serializer_HPP
