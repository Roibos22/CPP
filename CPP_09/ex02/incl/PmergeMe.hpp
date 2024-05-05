#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>

class	PmergeMe
{
	public:
		/* --------- CONSTRUCTORS & DECONSTRUCORS ---------- */
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe &pme);


		/* -------------- SETTERS & GETTERS ---------------- */

		/* ------------------ EXCEPTIONS ------------------- */

		/* ------------------ OVERLOADS -------------------- */
		PmergeMe	&operator=(const pme &);

	protected:
	
	private:

};

std::ostream	&operator<<(std::ostream &stream, PmergeMe const &pme);

#endif // PMERGEME_HPP
