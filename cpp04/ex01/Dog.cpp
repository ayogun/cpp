/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:48:02 by yogun             #+#    #+#             */
/*   Updated: 2023/03/13 17:17:53 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal() {
    std::cout << "Dog Default Constructor called" << std::endl;
	this->_type = "Dog";
	this->_brain = new Brain();
	this->_brain->setIdea("Dog's idea.", 0);
}

Dog::Dog(const Dog& other) {
    _type = other._type;
    _brain = new Brain(*other._brain);
}

Dog::~Dog() {
	std::cout << "Dog's Destructor called" << std::endl;
	delete this->_brain;
}

Dog& Dog::operator=(const Dog& other) {
	std::cout << "Dog's Copy assignment operator called" << std::endl;
	if (this == &other)
		return (*this);
	this->_type = other.getType();
	delete this->_brain;
	this->_brain = new Brain(*other._brain);
	return (*this);
}

void Dog::makeSound() const {
    std::cout << "Barked the Dog!" << std::endl;
}

const std::string & Dog::getIdea(int i) const
{
	return (this->_brain->getIdea(i));
}