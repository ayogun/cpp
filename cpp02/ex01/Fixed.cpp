/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:31:25 by yogun             #+#    #+#             */
/*   Updated: 2023/03/12 21:14:17 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cmath>
#include "Fixed.hpp"

// Default constructor
Fixed::Fixed() {
    std::cout << "Default constructor called" << std::endl;
    fixed_point_value = 0;
}

// Constructor with int parameter
Fixed::Fixed(const int value) {
    std::cout << "Int constructor called" << std::endl;
    fixed_point_value = value << fractional_bits; // shift left to get the fixed point value
}

// Constructor with float parameter
Fixed::Fixed(const float value) {
    std::cout << "Float constructor called" << std::endl;
    fixed_point_value = roundf(value * (1 << fractional_bits)); // shift left to get the fixed point value and round it to the nearest integer value using roundf from cmath library 
}

// Destructor
Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

// Copy constructor
Fixed::Fixed(const Fixed& other) {
    std::cout << "Copy constructor called" << std::endl;
    fixed_point_value = other.fixed_point_value;
}

// Assignment operator
Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    fixed_point_value = other.fixed_point_value;
    return *this;
}

int Fixed::getRawBits(void) const {
    return fixed_point_value;
}

void Fixed::setRawBits(int const raw) {
    fixed_point_value = raw;
}

float Fixed::toFloat(void) const {
    return static_cast<float>(fixed_point_value) / (1 << fractional_bits); // shift right to get the float value from the fixed point value
}

int Fixed::toInt(void) const {
    return fixed_point_value >> fractional_bits; // shift right to get the int value from the fixed point value
}

// overload the insertion operator to output a float representation of the fixed point number to the console using the toFloat() method
std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
    return os;
}
