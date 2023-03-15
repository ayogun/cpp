/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:24:12 by yogun             #+#    #+#             */
/*   Updated: 2023/03/15 14:28:21 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _rawBits(0) {
    std::cout << "Default constructor called" << std::endl; // Print message when default constructor is called
}

Fixed::Fixed(const Fixed& fixtance) {
    std::cout << "Copy constructor called" << std::endl; // Print message when copy constructor is called
    *this = fixtance; // Copy the value of the passed fixed-point number to the current object
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl; // Print message when destructor is called
}

Fixed& Fixed::operator=(const Fixed& fixtance) {
    std::cout << "Copy assignment operator called" << std::endl; // Print message when copy assignment operator overload is called
    if (this != &fixtance) { // Check if the current object is not the same as the passed object
        this->_rawBits = fixtance.getRawBits(); // Copy the raw value of the passed fixed-point number to the current object
    }
    return *this; // Return the current object
}

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl; // Print message when member function is called
    return this->_rawBits; // Return the raw value of the fixed-point number
}

void Fixed::setRawBits(int const raw) {
    this->_rawBits = raw; // Set the raw value of the fixed-point number
}
