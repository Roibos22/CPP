/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:46:56 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/05/15 17:57:03 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template <typename T>
class	MutantStack: public std::stack<T>
{
	public:
		/* --------- CONSTRUCTORS & DECONSTRUCORS ---------- */
		MutantStack();
		~MutantStack();
		MutantStack(const MutantStack &mutantstack);

		/* ------------------- METHODS --------------------- */

		typedef typename	std::stack<T>::container_type::iterator iterator;
		iterator	begin() { return this->c.begin(); }
		iterator	end() { return this->c.end(); }

		typedef typename	std::stack<T>::container_type::const_iterator const_iterator;
		const_iterator	begin() const { return this->c.begin(); }
		const_iterator	end() const { return this->c.end(); }

		typedef typename	std::stack<T>::container_type::reverse_iterator reverse_iterator;
		reverse_iterator	rbegin() { return this->c.rbegin(); }
		reverse_iterator	rend() { return this->c.rend(); }
	
		typedef typename	std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;
		const_reverse_iterator	rbegin() const { return this->c.rbegin(); }
		const_reverse_iterator	rend() const { return this->c.rend(); }

		/* -------------- SETTERS & GETTERS ---------------- */

		/* ------------------ EXCEPTIONS ------------------- */

		/* ------------------ OVERLOADS -------------------- */
		MutantStack	&operator=(const MutantStack &);

	protected:
	
	private:
};

//std::ostream	&operator<<(std::ostream &stream, MutantStack const &mutantstack);

#include "MutantStack.tpp"

#endif // MutantStack_HPP
