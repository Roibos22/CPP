/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 19:35:57 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/05/03 20:21:06 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

/* ------------------- CONSTRUCTORS & DECONSTRUCORS -------------------- */

RPN::RPN()
{

}

RPN::RPN(std::string input)
{
	this->_input = input;
}

RPN::~RPN()
{

}

RPN::RPN(const RPN &rpn) { *this = rpn; }

/* ----------------------------- METHODS ------------------------------- */

void	RPN::calculate()
{
	if (this->validate_input() == -1)
	{
		std::cerr << "Error" << std::endl;
		return ;
	}
	
	std::stack<int>	stack;

	for (size_t i = 0; i < _input.size(); i++)
	{
		// if is digit
			// push to stack

		// if is operator
			// pop 2 elements from stack
			// apply operator
			// push result to stack

		// if is space
			// do nothing

		if (std::isdigit(_input[i]))
			stack.push(_input[i] - '0');
		else if (isOperator(_input[i]))
		{
			int a = stack.top();
			stack.pop();
			int b = stack.top();
			stack.pop();
			switch (_input[i])
			{
				case '+':
					stack.push(a + b);
					break;
				case '-':
					stack.push(b - a);
					break;
				case '*':
					stack.push(a * b);
					break;
				case '/':
					stack.push(b / a);
					break;
			}
		}
	}
	std::cout << stack.top() << std::endl;
}


bool	RPN::isOperator(char c) 
{
	return c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '^';
}

int	RPN::validate_input()
{
	// check every second char is space
	for (size_t i = 1; i < _input.size(); i += 2) 
	{
		if (!std::isspace(_input[i]))
			return (-1);
	}

	// every other second must be a digit or operator
	for (size_t i = 0; i < _input.size(); i += 2) 
	{
		if (!std::isdigit(_input[i]) && !isOperator(_input[i]))
			return (-1);
	}
	return (0);
}


/* ------------------------ SETTERS & GETTERS -------------------------- */

std::string	RPN::getInput() const
{
	return (this->_input);
}

/* --------------------------- EXCEPTIONS ------------------------------ */

/* ---------------------------- OVERLOADS ------------------------------ */


RPN		&RPN::operator=(const RPN &origin)
{
	if (this != &origin)
	{
		this->_input = origin.getInput();
	}
	return (*this);
}

std::ostream	&operator<<(std::ostream &stream, RPN const &rpn)
{
	(void)rpn;
	stream << "Input: " << rpn.getInput() << std::endl;
	//stream << "Stack: " << rpn.getStack() << std::endl;
	return (stream);
}

