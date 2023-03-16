/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:47:37 by yogun             #+#    #+#             */
/*   Updated: 2023/03/16 16:44:06 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() {
    std::cout << "Animal constructor called" << std::endl;
    _type = "Animal";
}

Animal::Animal(const Animal& other) {
    std::cout << "Animal copy constructor called" << std::endl;
    _type = other._type;
}

Animal::~Animal(void) {
    std::cout << "Animal destructor called" << std::endl;
}

// Assignment operator
Animal& Animal::operator=(const Animal& other) {
    std::cout << "Animal assignment operator called" << std::endl;
    if (this != &other) {
        _type = other._type;
    }
    return *this;
}

void Animal::makeSound() const {
    std::cout << "Animal sound" << std::endl;
}

std::string Animal::getType() const {
    return ("My type? I am a " + _type + ".");
}
