/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:47:37 by yogun             #+#    #+#             */
/*   Updated: 2023/03/16 16:31:48 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

// Default constructor
Animal::Animal() : type_("Animal") {
    std::cout << "Animal constructor called" << std::endl;
}

// Constructor with type
Animal::Animal(const std::string& type) : type_(type) {
    std::cout << "Animal constructor called" << std::endl;
}

// Copy constructor
Animal::Animal(const Animal& other) : type_(other.type_) {
    std::cout << "Animal copy constructor called" << std::endl;
}

// Destructor
Animal::~Animal(void) {
    std::cout << "Animal destructor called" << std::endl;
}

// Assignment operator
Animal& Animal::operator=(const Animal& other) {
    std::cout << "Animal assignment operator called" << std::endl;
    if (this != &other) {
        type_ = other.type_;
    }
    return *this;
}

void Animal::makeSound() const {
    std::cout << "An animal makes a sound" << std::endl;
}

std::string Animal::getType() const {
    return ("My type? I am a " + type_ + ".");
}
