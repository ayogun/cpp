/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 21:17:26 by yogun             #+#    #+#             */
/*   Updated: 2023/03/07 08:54:36 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const std::string& type) : _type(type) {
	return ;
} // constructor that initializes the type using the input parameter

Weapon::~Weapon(void) {
	return ;
} // destructor

const std::string& Weapon::getType(void) const {
    return _type; // return the type by reference (const)
}

void Weapon::setType(const std::string& type) {
    this->_type = type; // set the type using the input parameter
}
