/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:31:25 by yogun             #+#    #+#             */
/*   Updated: 2023/03/08 13:53:02 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fractionalBits = 8;

// Constructor without parameters
Fixed::Fixed() : _rawBits(0) {
	return;
}

// Constructor with a constant integer parameter
Fixed::Fixed(const int intNumber) {
	this->_rawBits = intNumber << _fractionalBits;
}

// Constructor with a constant floating-point parameter
Fixed::Fixed(const float floatNumber) {
	this->_rawBits = roundf(floatNumber * (1 << _fractionalBits));
}

// Copy constructor
Fixed::Fixed(const Fixed& other) {
	*this = other;
}

// Destructor
Fixed::~Fixed() {
	return;
}

// Copy assignment operator
Fixed& Fixed::operator=(const Fixed& other) {
    if (this != &other) {
        _rawBits = other.getRawBits();
    }
    return *this;
}

// Overload of the << operator for output stream
std::ostream& operator<<(std::ostream& out, const Fixed& fixedNumber) {
    out << fixedNumber.toFloat();
    return out;
}

// Member function that returns the raw value of the fixed-point number
int Fixed::getRawBits() const {
    return _rawBits;
}

// Member function that sets the raw value of the fixed-point number
void Fixed::setRawBits(const int raw) {
    _rawBits = raw;
}

// Member function that converts the fixed-point number to a floating-point number
float Fixed::toFloat() const {
    return static_cast<float>(_rawBits) / (1 << _fractionalBits);
}

// Member function that converts the fixed-point number to an integer
int Fixed::toInt() const {
    return _rawBits >> _fractionalBits;
}

// Overload of the comparison operator <
bool Fixed::operator<(const Fixed& other) const {
    return _rawBits < other.getRawBits();
}

// Overload of the comparison operator >
bool Fixed::operator>(const Fixed& other) const {
    return _rawBits > other.getRawBits();
}

// Overload of the comparison operator <=
bool Fixed::operator<=(const Fixed& other) const {
    return _rawBits <= other.getRawBits();
}

// Overload of the comparison operator >=
bool Fixed::operator>=(const Fixed& other) const {
    return _rawBits >= other.getRawBits();
}

// Overload of the comparison operator ==
bool Fixed::operator==(const Fixed& other) const {
    return _rawBits == other.getRawBits();
}

// Overload of the comparison operator !=
bool Fixed::operator!=(const Fixed& other) const {
    return _rawBits != other.getRawBits();
}

// Overload of the arithmetic operator +
Fixed Fixed::operator+(const Fixed& other) const {
    return Fixed(toFloat() + other.toFloat());
}

// Overload of the arithmetic operator -
Fixed Fixed::operator-(const Fixed& other) const {
    return Fixed(toFloat() - other.toFloat());
}

// Overload of the arithmetic operator *
Fixed Fixed::operator*(const Fixed& other) const {
    return Fixed(toFloat() * other.toFloat());
}

// Overload of the arithmetic operator /
Fixed Fixed::operator/(const Fixed& other) const {
    return Fixed(toFloat() / other.toFloat());
}

// Overload of the pre-increment operator ++
Fixed& Fixed::operator++() {
    _rawBits += 1;
    return *this;
}

// Overload of the post-increment operator ++
Fixed Fixed::operator++(int) {
    Fixed temp(*this);
    operator++();
    return temp;
}

// Overload of the pre-decrement operator --
Fixed& Fixed::operator--() {
    _rawBits -= 1;
    return *this;
}

// Overload of the post-decrement operator --
Fixed Fixed::operator--(int) {
	Fixed temp(*this);
	operator--();
	return temp;
}

// Class member functions

// Static member function that returns the smallest fixed-point number
Fixed& Fixed::min(Fixed& a, Fixed& b) {
	return a < b ? a : b;
}

// Static member function that returns the smallest fixed-point number
const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
	return a < b ? a : b;
}

// Static member function that returns the largest fixed-point number
Fixed& Fixed::max(Fixed& a, Fixed& b) {
	return a > b ? a : b;
}

//	Static member function that returns the largest fixed-point number
const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
	return a > b ? a : b;
}
