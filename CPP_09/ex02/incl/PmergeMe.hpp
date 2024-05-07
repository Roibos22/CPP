/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 14:01:33 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/05/07 16:00:29 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <cstdlib>
#include <deque>
#include <vector>
#include <ctime>
#include <sstream>
#include <string>
#include <algorithm>

class	PmergeMe
{
	public:
		/* --------- CONSTRUCTORS & DECONSTRUCORS ---------- */
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe &pme);

		/* ------------------- METHODS --------------------- */
		void				sortDeque(int argc, char **argv);
		void				sortVector(int argc, char **argv);
		void				prepareDataVector(int argc, char **argv);
		void				prepareDataDeque(int argc, char **argv);
		void				generateSortingSequence(int size);
		void				printDeque() const;
		void				printVector() const;
		void				recursiveSelectionSortVector(std::vector<std::pair<int, int> > &pairs, int low, int high);
		int					findMinIndexVector(const std::vector<std::pair<int, int> > &pairs, int low, int high);
		void				recursiveSelectionSortDeque(std::deque<std::pair<int, int> > &pairs, int low, int high);
		int					findMinIndexDeque(const std::deque<std::pair<int, int> > &pairs, int low, int high);
		bool				hasDuplicatesVector(const std::vector<int>& data);
		bool				hasDuplicatesDeque(const std::deque<int>& data);
		double				getElapsedMicroseconds(clock_t start_time, clock_t end_time);
		void				printResult();
		std::string			vectorToString(const std::vector<int>& vec, const std::string& delimiter);
		std::string			dequeToString(const std::deque<int>& deq, const std::string& delimiter);

		/* -------------- SETTERS & GETTERS ---------------- */
		std::vector<int>	getVector() const;
		std::deque<int>		getDeque() const;
		double				getDequeTime() const;
		double				getVectorTime() const;
		std::string			getBeforeString() const;
		std::string			getAfterString() const;
		std::vector<int>	getJacobsthalSequence() const;

		/* ------------------ EXCEPTIONS ------------------- */

		/* ------------------ OVERLOADS -------------------- */
		PmergeMe	&operator=(const PmergeMe &);

	protected:
	
	private:
		std::deque<int>		_deque;
		std::vector<int>	_vector;
		double				_dequeTime;
		double				_vectorTime;
		std::string			_beforeString;
		std::string			_afterString;
		std::vector<int>	_jacobsthalSequence;
};

std::ostream	&operator<<(std::ostream &stream, PmergeMe const &pme);

#endif // PMERGEME_HPP
