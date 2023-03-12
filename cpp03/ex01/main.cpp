/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 21:34:11 by yogun             #+#    #+#             */
/*   Updated: 2023/03/12 21:39:23 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
    // Create a ClapTrap object
    ClapTrap claptrap("CL4P-TP");

    // Demonstrate ClapTrap's member functions
    claptrap.attack("an enemy");
    claptrap.takeDamage(5);
    claptrap.beRepaired(2);

    std::cout << std::endl;

    // Create a ScavTrap object
    ScavTrap scavtrap("SCAV-TP");

    // Demonstrate ScavTrap's member functions
    scavtrap.attack("an enemy");
    scavtrap.guardGate();
    scavtrap.takeDamage(10);
    scavtrap.beRepaired(5);

    return 0;
}
