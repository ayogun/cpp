/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conversion.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 01:14:17 by yogun             #+#    #+#             */
/*   Updated: 2023/03/14 01:38:31 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Conversion.hpp"
#include <limits>
#include <cmath>
#include <iostream>

namespace {
    const std::string nanStr = "nan";
    const std::string posInfStr = "inf";
    const std::string negInfStr = "-inf";
}

char ScalarConverter::toChar(const std::string& str) {
    char c = '\0';
    if (str.length() == 1 && isprint(str[0]))
        c = str[0];
    else
        std::cout << "Conversion from string to char is impossible" << std::endl;
    return c;
}

int ScalarConverter::toInt(const std::string& str) {
    int i = 0;
    try {
        i = std::stoi(str);
    } catch (const std::out_of_range& e) {
        std::cout << "Conversion from string to int is impossible: value out of range" << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cout << "Conversion from string to int is impossible: invalid argument" << std::endl;
    }
    return i;
}

float ScalarConverter::toFloat(const std::string& str) {
    float f = 0.0f;
    if (str == nanStr || str == posInfStr || str == negInfStr) {
        if (str == nanStr)
            f = std::numeric_limits<float>::quiet_NaN();
        else if (str == posInfStr)
            f = std::numeric_limits<float>::infinity();
        else
            f = -std::numeric_limits<float>::infinity();
    } else {
        try {
            f = std::stof(str);
        } catch (const std::out_of_range& e) {
            std::cout << "Conversion from string to float is impossible: value out of range" << std::endl;
        } catch (const std::invalid_argument& e) {
            std::cout << "Conversion from string to float is impossible: invalid argument" << std::endl;
        }
    }
    return f;
}

double ScalarConverter::toDouble(const std::string& str) {
    double d = 0.0;
    if (str == nanStr || str == posInfStr || str == negInfStr) {
        if (str == nanStr)
            d = std::numeric_limits<double>::quiet_NaN();
        else if (str == posInfStr)
            d = std::numeric_limits<double>::infinity();
        else
            d = -std::numeric_limits<double>::infinity();
    } else {
        try {
            d = std::stod(str);
        } catch (const std::out_of_range& e) {
            std::cout << "Conversion from string to double is impossible: value out of range" << std::endl;
        } catch (const std::invalid_argument& e) {
            std::cout << "Conversion from string to double is impossible: invalid argument" << std::endl;
        }
    }
    return d;
}
