/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:49:21 by yogun             #+#    #+#             */
/*   Updated: 2023/03/14 13:54:16 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal() {
    std::cout << "Cat constructor called" << std::endl;
	this->_type = "Cat";
	this->_brain = new Brain();
	this->_brain->setIdea("Cat's idea.",0);
}

Cat::Cat(const Cat& other) : Animal(other) {
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat::~Cat() {
    std::cout << "Cat destructor called" << std::endl;
	delete this->_brain;
}

Cat& Cat::operator=(const Cat& other) {
	if (this == &other)
		return (*this);
	this->_type = other.getType();
	delete this->_brain;
	this->_brain = new Brain(*other._brain);
	return (*this);
}

void Cat::makeSound() const {
    std::cout << "Meowed the Cat!" << std::endl;
}

const std::string & Cat::getIdea(int i) const
{
	return (this->_brain->getIdea(i));
}
