/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 14:01:31 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/05/06 14:22:19 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/* ------------------- CONSTRUCTORS & DECONSTRUCORS -------------------- */

PmergeMe::PmergeMe()
{

}

PmergeMe::PmergeMe(int argc, char **argv)
{
	// validate input and read into containers
	for (int i = 1; i < argc; i++)
	{
		int	tmp = atoi(argv[i]);
		//std::cout << tmp << std::endl;
		if (tmp > 0 && tmp <= 2147483647)
		{
			this->_deque.push_back(tmp);
			this->_vector.push_back(tmp);
		}
		else
			std::cerr << "Error" << std::endl;
	}
}

PmergeMe::~PmergeMe()
{

}

PmergeMe::PmergeMe(const PmergeMe &pme) { *this = pme; }

/* ----------------------------- METHODS ------------------------------- */

void printDeque(const std::deque<int>& dq) {
	std::cout << "Deque: ";
	if (dq.empty())
	{
		std::cout << "(empty)" << std::endl;
		return;
	}
	for (std::deque<int>::const_iterator it = dq.begin(); it != dq.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void printVector(const std::vector<int>& vec)
{
	std::cout << "Vector: ";
	if (vec.empty())
	{
		std::cout << "(empty)" << std::endl;
		return;
	}
	for (std::vector<int>::const_iterator it = vec.begin(); it != vec.end(); ++it)		
		std::cout << *it << " ";
	std::cout << std::endl;
}
/* ------------------------ SETTERS & GETTERS -------------------------- */

std::vector<int>	PmergeMe::getVector() const
{
	return (this->_vector);
}

std::deque<int>		PmergeMe::getDeque() const
{
	return (this->_deque);
}
/* --------------------------- EXCEPTIONS ------------------------------ */

/* ---------------------------- OVERLOADS ------------------------------ */


PmergeMe		&PmergeMe::operator=(const PmergeMe &origin)
{
	if (this != &origin)
	{
		
	}
	return (*this);
}

std::ostream	&operator<<(std::ostream &stream, PmergeMe const &pme)
{
	(void)pme;
	printDeque(pme.getDeque());
	printVector(pme.getVector());
	return (stream);
}

