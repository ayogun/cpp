/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 21:18:01 by yogun             #+#    #+#             */
/*   Updated: 2023/03/07 10:31:49 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <string>
#include "Weapon.hpp"

class HumanB {
private:
    std::string _name; // private member variable for the name of the human
    Weapon* _weapon; // pointer to a Weapon object for the weapon of the human

public:
    HumanB(const std::string name); // constructor that initializes the name
	~HumanB(void); // destructor
	
    void setWeapon(Weapon& weapon); // member function that sets the weapon
    void attack(void) const; // member function that displays an attack message
};

#endif
