/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 18:22:02 by yogun             #+#    #+#             */
/*   Updated: 2023/03/06 19:26:20 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// Default constructor
Zombie::Zombie() {
    this->_name = "Zombie";
}

// Constructor that takes a name
Zombie::Zombie(std::string name) {
    this->_name = name;
}

// Destructor
Zombie::~Zombie() {
    std::cout << this->_name << " zombie has been destroyed" << std::endl;
}

// Setter for the name
void Zombie::setName(std::string name) {
    this->_name = name;
}

// Prints a message to the console announcing the zombie
void Zombie::announce() {
    std::cout << this->_name << " says: Braiiiiiiinnnzzz..." << std::endl;
}
