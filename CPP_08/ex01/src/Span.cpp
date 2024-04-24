/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 02:09:04 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/04/24 18:37:12 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

/* ------------------- CONSTRUCTORS & DECONSTRUCORS -------------------- */

Span::Span(): _N(0), _elementsAdded(0)
{
	//std::cout << "Span Default Constructor called" << std::endl;
}

Span::Span(unsigned int n): _N(n), _elementsAdded(0)
{
	//std::cout << "Span Default Constructor called" << std::endl;
	//this->_vector = new int[n];
	this->_vector = std::vector<int>(n);
}

Span::~Span()
{
	//std::cout << "Span Deconstructor called" << std::endl;
	/* if (this->_N != 0)
		delete [] this->_vector; */
}

Span::Span(const Span &span) { *this = span; }

/* ----------------------------- METHODS ------------------------------- */

void		Span::addNumber(int num)
{
	if (this->_elementsAdded >= this->_N)
		throw ExceptionSpanFull();
	else
	{
		this->_vector[this->getElementsStored()] = num; 
		this->_elementsAdded++;
	}
}

int		Span::shortestSpan(void) const
{
	int	span;
	if (this->getElementsStored() <= 1)
		throw ExceptionNotEnoughValues();
	else
	{
		span = abs((this->getElementAtPos(1) - this->getElementAtPos(0)));
		for (unsigned int i = 1; i < this->getElementsStored(); i++)
		{
			int	newSpan = abs((this->getElementAtPos(i) - this->getElementAtPos(i - 1)));
			if (newSpan < span)
				span = newSpan;
		}
	}
	return (span);
}

int		Span::longestSpan(void) const
{
	int	span = 0;
	if (this->getElementsStored() <= 1)
		throw ExceptionNotEnoughValues();
	else
	{
		for (unsigned int i = 1; i < this->getElementsStored(); i++)
		{
			int	newSpan = abs((this->getElementAtPos(i) - this->getElementAtPos(i - 1)));
			if (newSpan > span)
				span = newSpan;
		}
	}
	return (span);
}

void	Span::fillRandom(std::vector<int>::iterator start, std::vector<int>::iterator end)
{
	srand(time(NULL));
	while (start != end)
	{
		int num = rand();
		this->addNumber(num);
		start++;
	}
}

/* ------------------------ GETTERS & SETTERS -------------------------- */

unsigned int	Span::getElementsStored( void ) const
{
	return (this->_elementsAdded);
}

unsigned int	Span::getN( void ) const
{
	return (this->_N);
}

int				Span::getElementAtPos(int pos) const
{
	// add try cath?
	return (this->_vector[pos]);
}

std::vector<int>::iterator Span::getStartVector( void )
{
	return this->_vector.begin();
}

std::vector<int>::iterator Span::getEndVector( void )
{
	return this->_vector.end();
}

/* --------------------------- EXCEPTIONS ------------------------------ */

const char*	Span::ExceptionSpanFull::what() const throw()
{
	return ("Can not add new Element as Span is full.");
}

const char*	Span::ExceptionNotEnoughValues::what() const throw()
{
	return ("Not enough values to calculate span.");
}

/* ---------------------------- OVERLOADS ------------------------------ */


/* Span		&Span::operator=(const Span &origin)
{
	return (*this);
} */

std::ostream	&operator<<(std::ostream &stream, Span const &span)
{
	stream << "Span: [ ";
	for (unsigned int i = 0; i < span.getElementsStored(); i++)
	{
		stream << span.getElementAtPos(i) << " ";
	}
	stream << "] (" << span.getElementsStored() << "/" << span.getN() << ")";
	return (stream);
}
