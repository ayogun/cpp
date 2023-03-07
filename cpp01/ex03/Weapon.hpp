/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 21:17:16 by yogun             #+#    #+#             */
/*   Updated: 2023/03/07 08:51:59 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon {
private:
    std::string _type; 					// private member variable for the type of the weapon

public:
    Weapon(const std::string& type); 	// constructor that initializes the type
	~Weapon(void); 						// destructor
	
    const std::string& getType(void) const; // getter function for the type
    void setType(const std::string& type); // setter function for the type
};

#endif
