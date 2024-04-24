#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <exception>
#include <vector>
#include <cstdlib>

#include <vector>
#include <stdexcept>
#include <climits>

#include <stdexcept>
#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>
#include <climits>
#include <algorithm>
#include <functional>

class	Span
{
	public:
		/* --------- CONSTRUCTORS & DECONSTRUCORS ---------- */
		Span();
		Span(unsigned int n);
		~Span();
		Span(const Span &span);

		/* ------------------- METHODS --------------------- */
		void	addNumber(int num);
		int		shortestSpan(void) const ;
		int		longestSpan(void) const ;
		void	fillRandom(std::vector<int>::iterator start, std::vector<int>::iterator end);

		/* -------------- SETTERS & GETTERS ---------------- */
		unsigned int	getElementsStored( void ) const;
		unsigned int	getN( void ) const;
		int				getElementAtPos(int pos) const;
		std::vector<int>::iterator getStartVector( void );
		std::vector<int>::iterator getEndVector( void );

		/* ------------------ OVERLOADS -------------------- */
		class	ExceptionSpanFull: public std::exception
		{
			virtual const char	*what() const throw();
		};

		class	ExceptionNotEnoughValues: public std::exception
		{
			virtual const char	*what() const throw();
		};

		/* ------------------ OVERLOADS -------------------- */
		//Span	&operator=(const Span &);

	protected:
	
	private:
		unsigned int		_N;
		unsigned int		_elementsAdded;
		std::vector<int>	_vector;
};

std::ostream	&operator<<(std::ostream &stream, Span const &span);

#endif // Span_HPP
