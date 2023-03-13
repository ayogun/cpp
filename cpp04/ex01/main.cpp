/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:42:12 by yogun             #+#    #+#             */
/*   Updated: 2023/03/13 20:51:32 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	{
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		delete j;
		delete i;
		std::cout << std::endl;
	}

	{
		Animal *k[8];

		int i;
		for (i = 0 ; i < 4; i++)
			k[i] = new Dog();
		for (i = 4; i < 7; i++)
			k[i] = new Cat();
		for (i = 7; i > 0; i--)
		{
			std::cout << "I'm animal number " << i;
			std::cout << "  " << k[i-1]->getType() << std::endl;
			delete k[i-1];
		}
		std::cout << std::endl;
	}

	{
		const Dog *Kapsel = new Dog();
		Kapsel->makeSound();
		std::cout << Kapsel->getType() << std::endl;
		std::cout << "My idea -> " << Kapsel->getIdea(0) << std::endl;
		delete Kapsel;

		const Cat *Lucky = new Cat();
		Lucky->makeSound();
		std::cout << Lucky->getType() << std::endl;
		std::cout << "My idea -> " << Lucky->getIdea(0) << std::endl;
		delete Lucky;
		std::cout << std::endl;
	}
	system("leaks AnimalPlanet");
	return 0;
}

