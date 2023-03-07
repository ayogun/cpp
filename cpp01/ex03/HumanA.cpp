/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 21:17:50 by yogun             #+#    #+#             */
/*   Updated: 2023/03/07 10:32:25 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include <iostream>

// constructor that initializes the name and weapon using input parameters
HumanA::HumanA(const std::string name, Weapon& weapon) : _name(name), _weapon(weapon) {
	return ;
}

// destructor
HumanA::~HumanA(void){
	return ;
}

// display an attack message using the name and type of the weapon
void HumanA::attack(void) const {
    std::cout << _name << " attacks with their " << _weapon.getType() << std::endl; 
}
