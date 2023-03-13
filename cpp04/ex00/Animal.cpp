/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:47:37 by yogun             #+#    #+#             */
/*   Updated: 2023/03/13 17:17:07 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>

Animal::Animal() : type_("Animal") {
    std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const std::string& type) : type_(type) {
    std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const Animal& other) : type_(other.type_) {
    std::cout << "Animal copy constructor called" << std::endl;
}

Animal::~Animal() {
    std::cout << "Animal destructor called" << std::endl;
}

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