/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 12:08:23 by yogun             #+#    #+#             */
/*   Updated: 2023/03/06 15:28:21 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

// Constructor
Zombie::Zombie(std::string name) : _name(name) {
    std::cout << "Zombie " << _name << " created!" << std::endl;
}

// Destructor
Zombie::~Zombie() {
    std::cout << "Zombie " << _name << " destroyed!" << std::endl;
}

// Announce function
void Zombie::announce() {
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
