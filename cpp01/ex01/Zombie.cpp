/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 18:22:02 by yogun             #+#    #+#             */
/*   Updated: 2023/03/07 08:30:05 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// Default constructor
Zombie::Zombie(void) {
	return;
}

// Destructor
Zombie::~Zombie(void) {
    std::cout << this->_name << " zombie has been destroyed" << std::endl;
}

// Setter for the name
void Zombie::setName(std::string name) {
    this->_name = name;
}

// Prints a message to the console announcing the zombie
void Zombie::announce(void) {
    std::cout << this->_name << " says: Braiiiiiiinnnzzz..." << std::endl;
}
