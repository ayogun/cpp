/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:42:12 by yogun             #+#    #+#             */
/*   Updated: 2023/03/16 15:22:25 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

/*
	This code creates three pointers to Animal objects, pointing to instances of Animal, Dog, and Cat respectively. 
	It then calls the getType() and makeSound() member functions on each of these objects, and prints the results to the console.
*/
int main() {
    {
    const Animal* meta = new Animal();      std::cout << std::endl;
    const Animal* j = new Dog();            std::cout << std::endl;
    const Animal* i = new Cat();            std::cout << std::endl;

    std::cout << j->getType() << std::endl;
    std::cout << i->getType() << std::endl;

    i->makeSound(); // Output: Meowed the Cat!
    j->makeSound(); // Output: Barked the Dog!
    meta->makeSound(); // Output: Animal sound

    std::cout << std::endl;

    delete meta;    // Animal destructor called
    delete j;       // Dog destructor called
    delete i;       // Cat destructor called

    // We use <delete> to free the memory allocated to heap by <new>
    // If we don't do this, we will have a memory leak
    // The memory allocated by <new> will not be freed until the program ends
    }

    {
        const WrongAnimal* meta = new WrongAnimal();      std::cout << std::endl;
        const WrongAnimal* i = new WrongCat();            std::cout << std::endl;

        std::cout << i->getType() << std::endl;

        i->makeSound(); // Output: Meowed the Cat!
        meta->makeSound(); // Output: Animal sound

        std::cout << std::endl;

        delete meta;    // Animal destructor called
        delete i;       // Cat destructor called
    }

    
    
    return 0;
}
