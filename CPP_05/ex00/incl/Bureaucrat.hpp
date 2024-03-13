/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 20:01:28 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/02/28 23:16:56 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

class	Bureaucrat
{
	public:
		/* --------- CONSTRUCTORS & DECONSTRUCORS ---------- */
		Bureaucrat();
		~Bureaucrat();
		Bureaucrat(const Bureaucrat &bureaucrat);
		Bureaucrat(std::string name, int grade);

		/* ------------------- METHODS --------------------- */
		void		incrementGrade();
		void		decrementGrade();

		/* -------------- SETTERS & GETTERS ---------------- */
		std::string	getName() const;
		int			getGrade() const;

		/* ----------------- EXCEPTIONS -------------------- */
		class	GradeTooHighException: public std::exception
		{
			// Overrides what() from exception class while not able to throw
			virtual const char	*what() const throw();
		};
		class	GradeTooLowException: public std::exception
		{
			virtual const char	*what() const throw();
		};

		/* ------------------ OVERLOADS -------------------- */
		Bureaucrat	&operator=(const Bureaucrat &);

	protected:
	
	private:
		const std::string	_name;
		int					_grade;

};

std::ostream	&operator<<(std::ostream &stream, Bureaucrat const &bureaucrat);

#endif // Bureaucrat_HPP
