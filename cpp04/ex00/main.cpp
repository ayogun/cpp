/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:42:12 by yogun             #+#    #+#             */
/*   Updated: 2023/03/13 17:17:23 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

/*
	This code creates three pointers to Animal objects, pointing to instances of Animal, Dog, and Cat respectively. 
	It then calls the getType() and makeSound() member functions on each of these objects, and prints the results to the console.
*/
int main() {
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;

    i->makeSound(); // Output: Meow!
    j->makeSound(); // Output: Woof!
    meta->makeSound(); // Output: Animal sound

    delete meta;
    delete j;
    delete i;

    return 0;
}
