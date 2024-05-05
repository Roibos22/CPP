
#include "PmergeMe.hpp"

/* ------------------- CONSTRUCTORS & DECONSTRUCORS -------------------- */

PmergeMe::PmergeMe()
{

}

PmergeMe::PmergeMe(std::string input)
{

}

PmergeMe::~PmergeMe()
{

}

PmergeMe::PmergeMe(const PmergeMe &pme) { *this = pme; }

/* ----------------------------- METHODS ------------------------------- */


/* ------------------------ SETTERS & GETTERS -------------------------- */


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
	stream << std::endl;
	return (stream);
}

