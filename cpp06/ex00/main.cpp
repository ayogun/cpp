/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 01:15:06 by yogun             #+#    #+#             */
/*   Updated: 2023/03/14 01:41:01 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Conversion.hpp"
#include <iostream>
#include <limits>
#include <cmath>

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Error: Invalid number of arguments\n";
        return 1;
    }

    std::string input = argv[1];

    std::cout << "char: ";
    try {
        char c = ScalarConverter::toChar(input);
        if (std::isprint(c))
            std::cout << "'" << c << "'\n";
        else
            std::cout << "Non displayable\n";
    } catch (std::exception const &e) {
        std::cout << e.what() << '\n';
    }

    std::cout << "int: ";
    try {
        int i = ScalarConverter::toInt(input);
        std::cout << i << '\n';
    } catch (std::exception const &e) {
        std::cout << e.what() << '\n';
    }

    std::cout << "float: ";
    try {
        float f = ScalarConverter::toChar(input);
        if (std::isnan(f))
            std::cout << "nanf\n";
        else if (f == std::numeric_limits<float>::infinity())
            std::cout << "+inff\n";
        else if (f == -std::numeric_limits<float>::infinity())
            std::cout << "-inff\n";
        else
            std::cout << f << "f\n";
    } catch (std::exception const &e) {
        std::cout << e.what() << '\n';
    }

    std::cout << "double: ";
    try {
        double d = ScalarConverter::toDouble(input);
        if (std::isnan(d))
            std::cout << "nan\n";
        else if (d == std::numeric_limits<double>::infinity())
            std::cout << "+inf\n";
        else if (d == -std::numeric_limits<double>::infinity())
            std::cout << "-inf\n";
        else
            std::cout << d << '\n';
    } catch (std::exception const &e) {
        std::cout << e.what() << '\n';
    }

    return 0;
}
