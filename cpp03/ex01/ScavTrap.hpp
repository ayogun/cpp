/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 21:30:27 by yogun             #+#    #+#             */
/*   Updated: 2023/03/12 21:49:56 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:
    ScavTrap(); // Default constructor
    ScavTrap(const std::string& name); // Parameterized constructor
    ScavTrap(const ScavTrap& other); // Copy constructor
    ~ScavTrap(); // Destructor
	unsigned int getAttackDamage() const;

    // Override attack function to add ScavTrap specific message
    void attack(const std::string& target);
    void guardGate(); // Special function
};

#endif // SCAVTRAP_HPP
