/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 19:36:00 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/05/03 20:07:08 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <cctype>

class	RPN
{
	public:
		/* --------- CONSTRUCTORS & DECONSTRUCORS ---------- */
		RPN();
		RPN(std::string input);
		~RPN();
		RPN(const RPN &rpn);

		/* ------------------- METHODS --------------------- */
		void	calculate();
		int		validate_input();
		bool	isOperator(char c);

		/* -------------- SETTERS & GETTERS ---------------- */
		std::string		getInput() const;

		/* ------------------ EXCEPTIONS ------------------- */

		/* ------------------ OVERLOADS -------------------- */
		RPN	&operator=(const RPN &);

	protected:
	
	private:
		std::string		_input;
};

std::ostream	&operator<<(std::ostream &stream, RPN const &rpn);

#endif // RPN_HPP
