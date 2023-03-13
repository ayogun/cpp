/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:47:37 by yogun             #+#    #+#             */
/*   Updated: 2023/03/13 17:17:39 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _brain(new Brain()) {}

Animal::Animal(const Animal& other) {
    _type = other._type;
    _brain = new Brain(*other._brain);
}

Animal::~Animal() {
    delete _brain;
}

Animal& Animal::operator=(const Animal& other) {
    if (this != &other) {
        _type = other._type;
        *_brain = *other._brain;
    }
    return *this;
}

void Animal::makeSound() const {
    std::cout << "Animal sound" << std::endl;
}

std::string Animal::getType() const {
    return ("My type? I am a " + _type + ".");
}
