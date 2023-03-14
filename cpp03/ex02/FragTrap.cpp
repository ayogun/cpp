/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:40:19 by yogun             #+#    #+#             */
/*   Updated: 2023/03/14 13:49:27 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

// Default constructor, sets attributes to default values
FragTrap::FragTrap(void) 
{
    std::cout << "FragTrap default constructor called " << std::endl;
}

// Constructor with name parameter, sets attributes to default values and custom name. Call base class constructor with name parameter
FragTrap::FragTrap(const std::string name) : ClapTrap(name)
{
    std::cout << "FragTrap constructor called " << std::endl;
}

// Copy constructor, copies all attributes from other object
// Call base class copy constructor
FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) 
{
    std::cout << "FragTrap copy constructor called " << std::endl;
}

// Destructor, prints message
FragTrap::~FragTrap() {
    std::cout << "FragTrap destructor called for " << std::endl;
}

// Member function, displays a positive high fives request
void FragTrap::highFivesGuys() {
    std::cout << "Hey guys, let's high five!" << std::endl;
}
