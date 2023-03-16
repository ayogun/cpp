/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:57:32 by yogun             #+#    #+#             */
/*   Updated: 2023/03/16 15:37:51 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "WrongCat.hpp"

// Constructor
WrongCat::WrongCat(void) : WrongAnimal("WrongCat") {
    std::cout << "WrongCat constructor called" << std::endl;
    return ;
}

// Destructor
WrongCat::~WrongCat(void) {
    std::cout << "WrongCat destructor called" << std::endl;
    return ;
}

// Copy constructor overload
WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {
    std::cout << "WrongCat copy constructor called" << std::endl;
    return ;
}

// Assignment operator overload
WrongCat& WrongCat::operator=(const WrongCat& other) {
    std::cout << "WrongCat assignment operator called" << std::endl;
    if (this != &other) {
        WrongAnimal::operator=(other);
    }
    return *this;
}

// Member function
void WrongCat::makeSound() const {
    std::cout << "Wrong Meow!" << std::endl;
}
