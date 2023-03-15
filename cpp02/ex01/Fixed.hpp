/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:31:14 by yogun             #+#    #+#             */
/*   Updated: 2023/03/15 15:14:06 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
    private:
        int _rawBits;
        static const int _fractionalBits = 8;
    public:
        Fixed();  // default constructor
        Fixed(const int value);  // constructor with int parameter
        Fixed(const float value);  // constructor with float parameter
        ~Fixed();  // destructor

        Fixed(const Fixed& other);  // copy constructor
        Fixed& operator=(const Fixed& other);  // assignment operator

        int getRawBits(void) const;
        void setRawBits(int const raw);
        float toFloat(void) const;
        int toInt(void) const;

};

        // overload the insertion operator to output a float representation of the fixed point number. It is a non-member function.
        std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif
