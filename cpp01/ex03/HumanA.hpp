/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 21:17:38 by yogun             #+#    #+#             */
/*   Updated: 2023/03/07 10:32:13 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <string>
#include "Weapon.hpp"

class HumanA {
private:
    std::string _name; // private member variable for the name of the human
    Weapon& _weapon; // reference to a Weapon object for the weapon of the human

public:
    HumanA(const std::string name, Weapon& weapon); // constructor that initializes the name and weapon
	~HumanA(void); // destructor
	
    void attack(void) const; // member function that displays an attack message
};

#endif
