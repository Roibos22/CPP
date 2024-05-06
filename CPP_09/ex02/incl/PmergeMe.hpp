/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 14:01:33 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/05/06 15:26:41 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <cstdlib>
#include <deque>
#include <vector>
#include <ctime>
#include <unistd.h> // TODO DELETE

class	PmergeMe
{
	public:
		/* --------- CONSTRUCTORS & DECONSTRUCORS ---------- */
		PmergeMe();
		PmergeMe(int argc, char **argv);
		~PmergeMe();
		PmergeMe(const PmergeMe &pme);

		/* ------------------- METHODS --------------------- */
		void	printResult();
		void	printDeque() const;
		void	printVector() const;
		//void	startTimerDeque();
		//void	startTimerVector();
		void	sortDeque();
		void	sortVector();

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
		int					_dequeTime;
		int					_vectorTime;
};

std::ostream	&operator<<(std::ostream &stream, PmergeMe const &pme);

#endif // PMERGEME_HPP
