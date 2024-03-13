/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 19:17:55 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/02/25 20:37:02 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include "IMateriaSource.hpp"

int main()
{
	std::cout << "--------- SUBJECT TEST ---------"<< std::endl;

	{
		IMateriaSource*	src = new MateriaSource();
		AMateria*		tmp;
		ICharacter*		me = new Character("me");
		ICharacter*		bob = new Character("bob");

		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);

		me->use(0, *bob);
		me->use(1, *bob);

		delete bob;
		delete me;
		delete src;
	}

	std::cout << std::endl << "------------ TEST 1 ------------"<< std::endl;

	{
		MateriaSource*	materiaMaker = new MateriaSource();
		ICharacter*		bob = new Character("bob");
		Character		ned("Ned");
		MateriaSource	stackMaker;

		materiaMaker->learnMateria(new Ice());
		materiaMaker->learnMateria(new Cure());
		materiaMaker->learnMateria(new Ice());
		materiaMaker->learnMateria(new Cure());
		materiaMaker->learnMateria(new Cure());

		stackMaker.learnMateria(new Ice());
		stackMaker.learnMateria(new Cure());
		stackMaker.learnMateria(new Ice());
		stackMaker.learnMateria(new Cure());
		stackMaker.learnMateria(new Cure());

		//bob->printInventory();
		bob->equip(materiaMaker->createMateria("non"));
		bob->equip(materiaMaker->createMateria("ice"));
		bob->equip(materiaMaker->createMateria("cure"));
		bob->equip(materiaMaker->createMateria("ice"));
		bob->equip(materiaMaker->createMateria("cure"));
		bob->equip(materiaMaker->createMateria("ice"));
		ned.equip(stackMaker.createMateria("non"));
		ned.equip(stackMaker.createMateria("ice"));
		ned.equip(stackMaker.createMateria("cure"));
		ned.equip(stackMaker.createMateria("ice"));
		ned.equip(stackMaker.createMateria("cure"));
		ned.equip(stackMaker.createMateria("ice"));
		bob->use(-1, ned);
		bob->use(0, ned);
		bob->use(1, ned);
		bob->use(2, ned);
		bob->use(3, ned);
		bob->use(4, ned);
		bob->use(5, ned);
		ned.use(-1, *bob);
		ned.use(0, *bob);
		ned.use(1, *bob);
		ned.use(2, *bob);
		ned.use(3, *bob);
		ned.use(4, *bob);
		ned.use(5, *bob);

		bob->unequip(-1);
		bob->unequip(0);
		bob->unequip(1);
		bob->unequip(2);
		bob->unequip(3);
		bob->unequip(4);
		bob->unequip(5);
		ned.unequip(-1);
		ned.unequip(0);
		ned.unequip(1);
		ned.unequip(2);
		ned.unequip(3);
		ned.unequip(4);
		
		delete bob;
		delete materiaMaker;
	}

	return (0);
}