/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 14:01:31 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/05/07 00:04:26 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

template<typename T>
std::string vectorToString(const std::vector<T>& vec, const std::string& delimiter = "")
{
	std::string result;
	for (typename std::vector<T>::const_iterator it = vec.begin(); it != vec.end(); ++it)
	{
		std::stringstream ss;
		ss << *it;
		result += ss.str();
		if (it + 1 != vec.end()) {
			result += delimiter;
		}
	}
	return result;
}

/* ------------------- CONSTRUCTORS & DECONSTRUCORS -------------------- */

PmergeMe::PmergeMe()
{

}

PmergeMe::PmergeMe(int argc, char **argv)
{
	// validate input and read into containers
	// TODO Duplicates
	for (int i = 1; i < argc; i++)
	{
		int	tmp = atoi(argv[i]);
		//std::cout << tmp << std::endl;
		if (tmp >= 0 && tmp <= 2147483647)
		{
			this->_deque.push_back(tmp);
			this->_vector.push_back(tmp);
		}
		else
			std::cerr << "Error" << std::endl;
	}
	this->_beforeString = vectorToString(this->_vector, " ");
	this->generateSortingSequence(this->_vector.size());
	std::cerr << std::endl;
}

PmergeMe::~PmergeMe()
{

}

PmergeMe::PmergeMe(const PmergeMe &pme) { *this = pme; }

/* ----------------------------- METHODS ------------------------------- */

int findMinIndexVector(const std::vector<std::pair<int, int> > &pairs, int low, int high)
{
	int minIndex = low;
	for (int i = low + 1; i < high; i++)
	{
		if (pairs[i].first < pairs[minIndex].first)
			minIndex = i;
	}
	return (minIndex);
}

void	PmergeMe::recursiveSelectionSortVector(std::vector<std::pair<int, int> > &pairs, int low, int high)
{
	if (low < high)
	{
		int minIndex = findMinIndexVector(pairs, low, high);
		if (pairs[minIndex].first != -1)
			std::swap(pairs[low], pairs[minIndex]);
		recursiveSelectionSortVector(pairs, low + 1, high);
	}
}

void	PmergeMe::generateSortingSequence(int size)
{
	if (size % 2 == 0)
		size = size / 2;
	else
		size = (size / 2) + 1;
	//std::cout << "Goal numbers: " << size << std::endl;
	int currJacobsthal = 1;
	int lastJacobsthal = 1;
	_jacobsthalSequence.push_back(1);
	_jacobsthalSequence.push_back(1);

	while (currJacobsthal < size)
	{
		int nextJacobsthal = currJacobsthal + (2 * lastJacobsthal);
		if (nextJacobsthal >= size)
			nextJacobsthal = size;
		lastJacobsthal = currJacobsthal;
		currJacobsthal = nextJacobsthal;
		for (int i = nextJacobsthal; i > lastJacobsthal; i--)
			_jacobsthalSequence.push_back(i);
	}

/* 	for (unsigned long i = 0; i < _jacobsthalSequence.size(); ++i)
		std::cout << _jacobsthalSequence[i] << " ";
	std::cout << std::endl; */
	_jacobsthalSequence.erase(_jacobsthalSequence.begin());
	for (unsigned long i = 0; i < _jacobsthalSequence.size(); i++)
	{
		_jacobsthalSequence[i] = _jacobsthalSequence[i] - 1;
		std::cout << _jacobsthalSequence[i] << " ";
	}
}

void	PmergeMe::sortVector()
{
	clock_t start_time = clock();

	// create pairs
	std::vector<std::pair<int, int> >	pairs;
	std::vector<int>::iterator			it;
	for (it = this->_vector.begin(); it != this->_vector.end() && it != this->_vector.end() + 1; it += 2)
	{
		if (it + 1 != this->_vector.end())
		{
			std::pair<int, int>	p(*it, *(it + 1));
			pairs.push_back(p);
			std::cout << p.first << " & " << p.second << " | ";
		}
		if (it + 1 == this->_vector.end())
		{
			std::pair<int, int>	p(-1, *(it));
			pairs.push_back(p);
			std::cout << p.first << " & " << p.second << " | ";
		}
	}
	std::cout << std::endl;

	// sort pairs in itself;
	std::cout << "Sorted Pairs in itself: " << std::endl;
	std::vector<std::pair<int, int> >::iterator	it2;
	for (it2 = pairs.begin(); it2 != pairs.end(); it2++)
	{
		if ((*it2).first < (*it2).second && (*it2).first != -1)
			std::swap((*it2).first, (*it2).second);
		std::cout << it2->first << " & " << it2->second << " | ";
	}
	std::cout << std::endl;

	// sort pairs (recursively) with bubble sort
	std::cout << "Sorted Pairs: " << std::endl;

	recursiveSelectionSortVector(pairs, 0, pairs.size());
	std::vector<std::pair<int, int> >::iterator	it22;
	for (it22 = pairs.begin(); it22 != pairs.end(); it22++)
	{
		/* if ((*it22).first < (*it22).second)
			std::swap((*it22).first, (*it22).second); */
		std::cout << it22->first << " & " << it22->second << " | ";
	}
	std::cout << std::endl;

	// read pairs into res vector
	std::vector<int>	res;
	for (size_t i = 0; i < pairs.size(); i++)
	{
		if (pairs[i].first != -1)
			res.push_back(pairs[i].first);
	}
	this->_vector = res;
	//this->_vector.insert(this->_vector.begin(), pairs[0].second);

	// loop through pairs by jacobsthal number index and binary sort them into vector
	// sort b row with binary (lower_bound)
	std::cout << std::endl;

	std::vector<int>::iterator	itJt = this->_jacobsthalSequence.begin();
	std::vector<int>::iterator	insertLocation;
	int							valueToSortIn;
	for (itJt = this->_jacobsthalSequence.begin(); itJt != this->_jacobsthalSequence.end(); itJt++)
	{
		valueToSortIn = pairs[*itJt].second;
		std::cout << " sorting in" << valueToSortIn << std::endl;
		insertLocation = std::lower_bound(this->_vector.begin(), this->_vector.end(), valueToSortIn);
		//std::cout << " |" << *insertLocation << "| ";
		this->_vector.insert(insertLocation, valueToSortIn);
	}
	std::cout << std::endl;

	//std::lower_bound(this->_vector.begin(), this->_vector.end(), );
	

	clock_t end_time = clock();
	_vectorTime = end_time - start_time;

	this->_afterString = vectorToString(this->_vector, " ");
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
	 // TODO set width of strings
	std::cout << "Before: " << this->_beforeString << std::endl;
	std::cout << "After: " << this->_afterString << std::endl;
	std::cout << "Time to process a range of " << this->_vector.size() << " elements with std::vector: " << this->getVectorTime() << " us" << std::endl;
	std::cout << "Time to process a range of " << this->_deque.size() << " elements with std::deque: " << this->getDequeTime() << " us" << std::endl;
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

