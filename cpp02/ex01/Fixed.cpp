/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:31:25 by yogun             #+#    #+#             */
/*   Updated: 2023/03/15 15:07:30 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Default constructor
Fixed::Fixed() {
    std::cout << "Default constructor called" << std::endl;
    _rawBits = 0;
}

// Constructor with int parameter
Fixed::Fixed(const int value) {
    std::cout << "Int constructor called" << std::endl;
    _rawBits = value << _fractionalBits; // shift left to get the fixed point value
}

// Constructor with float parameter
Fixed::Fixed(const float value) {
    std::cout << "Float constructor called" << std::endl;
    _rawBits = roundf(value * (1 << _fractionalBits)); // shift left to get the fixed point value and round it to the nearest integer value using roundf from cmath library 
}

// Destructor
Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

// Copy constructor
Fixed::Fixed(const Fixed& other) {
    std::cout << "Copy constructor called" << std::endl;
    _rawBits = other._rawBits;
}

// Assignment operator
Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    _rawBits = other._rawBits;
    return *this;
}

// Getter for the fixed point value
int Fixed::getRawBits(void) const {
    return _rawBits;
}

// Setter for the fixed point value
void Fixed::setRawBits(int const raw) {
    _rawBits = raw;
}

// Convert the fixed point value to a float
float Fixed::toFloat(void) const {
    return static_cast<float>(_rawBits) / (1 << _fractionalBits); // shift right to get the float value from the fixed point value
}

// Convert the fixed point value to an int
int Fixed::toInt(void) const {
    return _rawBits >> _fractionalBits; // shift right to get the int value from the fixed point value
}

// overload the insertion operator to output a float representation of the fixed point number to the console using the toFloat() method
std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
    return os;
}
