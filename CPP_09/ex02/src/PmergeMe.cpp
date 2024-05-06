/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 14:01:31 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/05/06 15:31:54 by lgrimmei         ###   ########.fr       */
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

void	PmergeMe::sortVector()
{
	clock_t start_time = clock();
	usleep(5);

	clock_t end_time = clock();
	_vectorTime = end_time - start_time;
}

void	PmergeMe::sortDeque()
{
	clock_t start_time = clock();
	usleep(5);

	clock_t end_time = clock();
	_dequeTime = end_time - start_time;
}

void	PmergeMe::printResult()
{
	std::cout << << std::endl;
}

void	PmergeMe::printDeque() const
{
	std::deque<int>	dq = this->getDeque();
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

void	PmergeMe::printVector() const
{
	std::vector<int>	vec = this->getVector();
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

int					PmergeMe::getVectorTime() const
{
	return (this->_vectorTime);
}

int					PmergeMe::getDequeTime() const
{
	return (this->_dequeTime);
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
	pme.printDeque();
	pme.printVector();
	return (stream);
}

