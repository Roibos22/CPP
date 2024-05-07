/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 14:01:31 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/05/07 16:02:44 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/* ------------------- CONSTRUCTORS & DECONSTRUCORS -------------------- */

PmergeMe::PmergeMe()
{

}

PmergeMe::~PmergeMe()
{

}

PmergeMe::PmergeMe(const PmergeMe &pme) { *this = pme; }

/* ----------------------------- METHODS ------------------------------- */

void	PmergeMe::prepareDataVector(int argc, char **argv)
{
	for (int i = 1; i < argc; i++)
	{
		long long	tmp = atoll(argv[i]);
		if (tmp > 0 && tmp <= 2147483647)
			this->_vector.push_back(tmp);
		else
			throw std::runtime_error("Error");
		if (hasDuplicatesVector(this->_vector))
			throw std::runtime_error("Error");
	}
	this->_beforeString = vectorToString(this->_vector, " ");
	this->generateSortingSequence(this->_vector.size());
}

void	PmergeMe::prepareDataDeque(int argc, char **argv)
{
	this->_jacobsthalSequence.clear();
	for (int i = 1; i < argc; i++)
	{
		int	tmp = atoi(argv[i]);
		if (tmp > 0 && tmp <= 2147483647)
			this->_deque.push_back(tmp);
		else
			throw std::runtime_error("Error");
		if (hasDuplicatesDeque(this->_deque))
			throw std::runtime_error("Error");
	}
	this->_beforeString = dequeToString(this->_deque, " ");
	this->generateSortingSequence(this->_deque.size());
}

void	PmergeMe::sortVector(int argc, char **argv)
{
	clock_t start_time = clock();

	prepareDataVector(argc, argv);

	// CREATE PAIRS
	std::vector<std::pair<int, int> >	pairs;
	std::vector<int>::iterator			it;
	for (it = this->_vector.begin(); it != this->_vector.end() && it != this->_vector.end() + 1; it += 2)
	{
		if (it + 1 != this->_vector.end())
		{
			std::pair<int, int>	p(*it, *(it + 1));
			pairs.push_back(p);
		}
		else if (it + 1 == this->_vector.end())
		{
			std::pair<int, int>	p(-1, *(it));
			pairs.push_back(p);
		}
	}

	// SORT PAIRS IN ITSELF
	std::vector<std::pair<int, int> >::iterator	it2;
	for (it2 = pairs.begin(); it2 != pairs.end(); it2++)
	{
		if ((*it2).first < (*it2).second && (*it2).first != -1)
			std::swap((*it2).first, (*it2).second);
	}

	// SORT PAIRS IN RECURSIVE SELECTION SORT
	recursiveSelectionSortVector(pairs, 0, pairs.size());

	// READ FIRST VALUE OF PAIRS INTO RESULT VECTOR
	std::vector<int>	res;
	for (size_t i = 0; i < pairs.size(); i++)
	{
		if (pairs[i].first != -1)
			res.push_back(pairs[i].first);
	}
	this->_vector = res;

	// INSERT SECOND VALUE OF PAIRS INTO RESULT VECTOR BY UTILIZING JACOBSTHAL NUMBERS AND BINARY SEARCH
	std::vector<int>::iterator	itJt = this->_jacobsthalSequence.begin();
	std::vector<int>::iterator	insertLocation;
	int							valueToSortIn;
	for (itJt = this->_jacobsthalSequence.begin(); itJt != this->_jacobsthalSequence.end(); itJt++)
	{
		valueToSortIn = pairs[*itJt].second;
		insertLocation = std::lower_bound(this->_vector.begin(), this->_vector.end(), valueToSortIn);
		this->_vector.insert(insertLocation, valueToSortIn);
	}

	clock_t end_time = clock();
	_vectorTime = getElapsedMicroseconds(start_time, end_time);
	this->_afterString = vectorToString(this->_vector, " ");
}

void	PmergeMe::sortDeque(int argc, char **argv)
{
	clock_t start_time = clock();
	prepareDataDeque(argc, argv);

	// CREATE PAIRS
	std::deque<std::pair<int, int> > pairs;
	std::deque<int>::iterator it;
	for (it = this->_deque.begin(); it != this->_deque.end() && it != this->_deque.end() + 1; it += 2)
	{
		if (it + 1 != this->_deque.end())
		{
			std::pair<int, int> p(*it, *(it + 1));
			pairs.push_back(p);
		} 
		else if (it + 1 == this->_deque.end())
		{
			std::pair<int, int> p(-1, *(it));
			pairs.push_back(p);
		}
	}

	// SORT PAIRS IN ITSELF
	std::deque<std::pair<int, int> >::iterator it2;
	for (it2 = pairs.begin(); it2 != pairs.end(); it2++) {
		if ((*it2).first < (*it2).second && (*it2).first != -1)
			std::swap((*it2).first, (*it2).second);
	}

	// SORT PAIRS IN RECURSIVE SELECTION SORT
	recursiveSelectionSortDeque(pairs, 0, pairs.size());

	// READ FIRST VALUE OF PAIRS INTO RESULT VECTOR
	std::deque<int> res;
	for (size_t i = 0; i < pairs.size(); i++)
	{
		if (pairs[i].first != -1)
			res.push_back(pairs[i].first);
	}
	this->_deque = res;

	// INSERT SECOND VALUE OF PAIRS INTO RESULT VECTOR BY UTILIZING JACOBSTHAL NUMBERS AND BINARY SEARCH
	std::vector<int>::iterator itJt = this->_jacobsthalSequence.begin();
	std::deque<int>::iterator insertLocation;
	int valueToSortIn;
	for (itJt = this->_jacobsthalSequence.begin(); itJt != this->_jacobsthalSequence.end(); itJt++) {
		valueToSortIn = pairs[*itJt].second;
		insertLocation = std::lower_bound(this->_deque.begin(), this->_deque.end(), valueToSortIn);
		this->_deque.insert(insertLocation, valueToSortIn);
	}
	clock_t end_time = clock();
	_dequeTime = getElapsedMicroseconds(start_time, end_time);
	this->_afterString = dequeToString(this->_deque, " "); // Might need to be dequeToString depending on your implementation
}

/* RECURSIVE SELECTION SORT */

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

int		PmergeMe::findMinIndexVector(const std::vector<std::pair<int, int> > &pairs, int low, int high)
{
	int minIndex = low;
	for (int i = low + 1; i < high; i++)
	{
		if (pairs[i].first < pairs[minIndex].first && pairs[i].first != -1)
			minIndex = i;
	}
	return (minIndex);
}

void	PmergeMe::recursiveSelectionSortDeque(std::deque<std::pair<int, int> > &pairs, int low, int high)
{
	if (low < high)
	{
		int minIndex = findMinIndexDeque(pairs, low, high);
		if (pairs[minIndex].first != -1)
			std::swap(pairs[low], pairs[minIndex]);
		recursiveSelectionSortDeque(pairs, low + 1, high);
	}
}

int		PmergeMe::findMinIndexDeque(const std::deque<std::pair<int, int> > &pairs, int low, int high)
{
	int minIndex = low;
	for (int i = low + 1; i < high; i++)
	{
		if (pairs[i].first < pairs[minIndex].first && pairs[i].first != -1)
			minIndex = i;
	}
	return (minIndex);
}

/* HELPER FUNCTIONS */

void	PmergeMe::generateSortingSequence(int size)
{
	if (size % 2 == 0)
		size = size / 2;
	else
		size = (size / 2) + 1;

	this->_jacobsthalSequence.clear();
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

	_jacobsthalSequence.erase(_jacobsthalSequence.begin());
	for (unsigned long i = 0; i < _jacobsthalSequence.size(); i++)
		_jacobsthalSequence[i] = _jacobsthalSequence[i] - 1;
}

void	PmergeMe::printResult()
{
	std::cout << "Before: " << this->_beforeString << std::endl;
	std::cout << "After: " << this->_afterString << std::endl;
	std::cout << "Time to process a range of " << this->_vector.size() << " elements with std::vector: " << this->getVectorTime() << " us" << std::endl;
	std::cout << "Time to process a range of " << this->_deque.size() << " elements with std::deque: " << this->getDequeTime() << " us" << std::endl;
	//std::cout << this->dequeToString(this->_deque, " ") << std::endl;
	//std::cout << this->vectorToString(this->_vector, " ") << std::endl;
}

bool	PmergeMe::hasDuplicatesVector(const std::vector<int>& data)
{
	std::vector<int> sortedData = data; // Create a copy to avoid modifying the original vector
	std::sort(sortedData.begin(), sortedData.end());
	for (unsigned int i = 1; i < sortedData.size(); ++i)
	{
		if (sortedData[i] == sortedData[i - 1])
			return true;
	}
	return false;
}

bool	PmergeMe::hasDuplicatesDeque(const std::deque<int>& data)
{
	std::deque<int> sortedData = data; // Create a copy to avoid modifying the original vector
	std::sort(sortedData.begin(), sortedData.end());
	for (unsigned int i = 1; i < sortedData.size(); ++i)
	{
		if (sortedData[i] == sortedData[i - 1])
			return true;
	}
	return false;
}

double	PmergeMe::getElapsedMicroseconds(clock_t start_time, clock_t end_time)
{
	double	elapsed_seconds = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;
	return (elapsed_seconds * 1000000);
}

std::string PmergeMe::vectorToString(const std::vector<int>& vec, const std::string& delimiter)
{
	std::string result;
	for (std::vector<int>::const_iterator it = vec.begin(); it != vec.end(); ++it)
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

std::string PmergeMe::dequeToString(const std::deque<int>& deq, const std::string& delimiter)
{
	std::string result;
	for (std::deque<int>::const_iterator it = deq.begin(); it != deq.end(); ++it)
	{
		std::stringstream ss;
		ss << *it;
		result += ss.str();
		if (it + 1 != deq.end()) {
			result += delimiter;
		}
	}
	return result;
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

double				PmergeMe::getVectorTime() const
{
	return (this->_vectorTime);
}

double				PmergeMe::getDequeTime() const
{
	return (this->_dequeTime);
}

std::string			PmergeMe::getBeforeString() const
{
	return (this->_beforeString);
}

std::string			PmergeMe::getAfterString() const
{
	return (this->_afterString);
}

std::vector<int>	PmergeMe::getJacobsthalSequence() const
{
	return (this->_jacobsthalSequence);
}

/* --------------------------- EXCEPTIONS ------------------------------ */

/* ---------------------------- OVERLOADS ------------------------------ */


PmergeMe		&PmergeMe::operator=(const PmergeMe &origin)
{
	if (this != &origin)
	{
		this->_deque = origin.getDeque();
		this->_vector = origin.getVector();
		this->_dequeTime = origin.getDequeTime();
		this->_vectorTime = origin.getVectorTime();
		this->_beforeString = origin.getBeforeString();
		this->_afterString = origin.getAfterString();
		this->_jacobsthalSequence = origin.getJacobsthalSequence();
	}
	return (*this);
}

std::ostream	&operator<<(std::ostream &stream, PmergeMe const &pme)
{
	pme.printDeque();
	pme.printVector();
	return (stream);
}

