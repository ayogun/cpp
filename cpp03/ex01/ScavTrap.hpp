/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 21:30:27 by yogun             #+#    #+#             */
/*   Updated: 2023/03/13 14:32:25 by yogun            ###   ########.fr       */
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
    ScavTrap(const std::string name); // Constructor
    ScavTrap(const ScavTrap& other); // Copy constructor
    ~ScavTrap(void); // Destructor

    // Override attack function to add ScavTrap specific message
    void attack(const std::string& target);
    void guardGate(void); // Special function

protected:
	ScavTrap(void); // Default constructor. It is protected because we don't want to create a ScavTrap without a name
};

#endif // SCAVTRAP_HPP
