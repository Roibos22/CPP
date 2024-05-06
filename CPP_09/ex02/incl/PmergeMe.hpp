/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 14:01:33 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/05/06 14:12:22 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <cstdlib>
#include <deque>
#include <vector>

class	PmergeMe
{
	public:
		/* --------- CONSTRUCTORS & DECONSTRUCORS ---------- */
		PmergeMe();
		PmergeMe(int argc, char **argv);
		~PmergeMe();
		PmergeMe(const PmergeMe &pme);

		/* -------------- SETTERS & GETTERS ---------------- */
		std::vector<int>	getVector() const;
		std::deque<int>		getDeque() const;

		/* ------------------ EXCEPTIONS ------------------- */

		/* ------------------ OVERLOADS -------------------- */
		PmergeMe	&operator=(const PmergeMe &);

	protected:
	
	private:
		std::deque<int>		_deque;
		std::vector<int>	_vector;
};

std::ostream	&operator<<(std::ostream &stream, PmergeMe const &pme);

#endif // PMERGEME_HPP
