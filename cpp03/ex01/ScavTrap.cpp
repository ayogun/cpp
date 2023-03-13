/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 21:30:37 by yogun             #+#    #+#             */
/*   Updated: 2023/03/13 14:23:09 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

// Default constructor
ScavTrap::ScavTrap(void) {
	std::cout << "SC4V-TP called default constructor!" << std::endl;
}

// Constructors
ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    std::cout << "SC4V-TP " << getName() << " constructed with constructor!\n";
	setAttackDamage(20);
	setEnergyPoints(50);
	setHitPoints(100);
	
}

ScavTrap::ScavTrap(const ScavTrap& other)
    : ClapTrap(other) {
    std::cout << "SC4V-TP " << getName() << " copied!\n";
}

// Destructor
ScavTrap::~ScavTrap() {
    std::cout << "SC4V-TP " << getName() << " destructed!\n";
}

// ScavTrap specific function
void ScavTrap::guardGate() {
    std::cout << "SC4V-TP " << getName() << " enters Gate keeper mode.\n";
}

// Override attack function to add ScavTrap specific message
void ScavTrap::attack(const std::string& target) {
    std::cout << "SC4V-TP " << getName() << " attacks " << target
              << ", causing " << getAttackDamage() << " points of damage!\n";
}

