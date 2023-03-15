/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:24:04 by yogun             #+#    #+#             */
/*   Updated: 2023/03/15 14:17:46 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
    private:
        int _rawBits; // Integer to store the fixed-point number value
        static const int _fractionalBits = 8; // Static constant integer to store the number of fractional bits
		
    public:
        Fixed(); // Default constructor
        Fixed(const Fixed& fixed); // Copy constructor
		Fixed& operator=(const Fixed& fixed); // Copy assignment operator overload
        ~Fixed(); // Destructor

        int getRawBits(void) const; // Member function that returns the raw value of the fixed-point value
        void setRawBits(int const raw); // Member function that sets the raw value of the fixed-point number
		// It takes a const int as parameter, because it doesn't modify the value of the parameter
};

#endif
