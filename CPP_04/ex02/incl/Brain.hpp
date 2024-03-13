#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class	Brain
{
	public:
		/* --------- CONSTRUCTORS & DECONSTRUCORS ---------- */
		Brain();
		~Brain();
		Brain(const Brain &brain);

		/* ------------------- METHODS --------------------- */

		/* ------------------- SETTERS --------------------- */
		void		setIdea(int i, std::string idea);

		/* ------------------- GETTERS --------------------- */
		std::string	getIdea(int i) const;

		/* ------------------ OVERLOADS -------------------- */
		Brain	&operator=(const Brain &);

	protected:
	
	private:
		std::string	_ideas[100];
};

std::ostream	&operator<<(std::ostream &stream, Brain const &brain);

#endif // Brain_HPP
