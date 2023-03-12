/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 21:30:37 by yogun             #+#    #+#             */
/*   Updated: 2023/03/12 21:48:10 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

// Constructors
ScavTrap::ScavTrap(std::string name)
    : ClapTrap(name, 100, 50, 20) {
    std::cout << "SC4V-TP " << getName() << " constructed!\n";
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

unsigned int ScavTrap::getAttackDamage() const {
    return attackDamage_;
}

