/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 21:18:12 by yogun             #+#    #+#             */
/*   Updated: 2023/03/07 10:32:38 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(const std::string name) : _name(name), _weapon(nullptr) {
	return ;
} // constructor that initializes the name and sets the weapon pointer to null

HumanB::~HumanB(void) {
	return ;
} // destructor

void HumanB::setWeapon(Weapon& weapon) {
    this->_weapon = &weapon; // set the weapon pointer to the address of the input parameter
}

void HumanB::attack(void) const {
    if (_weapon) {
        std::cout << _name << " attacks with their " << _weapon->getType() << std::endl; // display an attack message using the name and type of the weapon (if the weapon pointer is not null)
    } else {
        std::cout << _name << " attacks with their bare hands" << std::endl; // display an attack message using the name and a default weapon type (if the weapon pointer is null)
    }
}
