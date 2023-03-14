/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:49:21 by yogun             #+#    #+#             */
/*   Updated: 2023/03/14 13:52:00 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

// Default constructor
Cat::Cat() : Animal("Cat") {
    std::cout << "Cat constructor called" << std::endl;
}

// Constructor with type
Cat::Cat(const Cat& other) : Animal(other) {
    std::cout << "Cat copy constructor called" << std::endl;
}

// Destructor
Cat::~Cat() {
    std::cout << "Cat destructor called" << std::endl;
}

// Assignment operator
Cat& Cat::operator=(const Cat& other) {
    std::cout << "Cat assignment operator called" << std::endl;
    if (this != &other) {
        Animal::operator=(other);
    }
    return *this;
}

// Membwer function
void Cat::makeSound() const {
    std::cout << "Meowed the Cat!" << std::endl;
}
