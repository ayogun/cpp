/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 21:34:11 by yogun             #+#    #+#             */
/*   Updated: 2023/03/15 21:31:47 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
    std::cout << "Creating a ClapTrap" << std::endl;
    ClapTrap claptrap("CL4P-TP");
    claptrap.attack("a bandit");
    claptrap.takeDamage(15);
    claptrap.beRepaired(10);
	
    std::cout << std::endl;

    std::cout << "Creating a ScavTrap" << std::endl;
    ScavTrap scavtrap("SC4V-TP");
    scavtrap.attack("a thief");
    scavtrap.takeDamage(20);
    scavtrap.beRepaired(5);
    scavtrap.guardGate();
	
    std::cout << std::endl;

    return 0;
}
