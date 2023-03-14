/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:23:55 by yogun             #+#    #+#             */
/*   Updated: 2023/03/14 13:42:45 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void)
{
    Fixed a; // Create a default fixed-point number with value 0
    Fixed b(a); // Create a copy of fixed-point number a
    Fixed c; // Create a default fixed-point number with value 0

    c = b; // Assign fixed-point number b to fixed-point number c

    std::cout << a.getRawBits() << std::endl; // Print the raw value of fixed-point number a
    std::cout << b.getRawBits() << std::endl; // Print the raw value of fixed-point number b
    std::cout << c.getRawBits() << std::endl; // Print the raw value of fixed-point number c

    return 0;
}
