/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:40:08 by yogun             #+#    #+#             */
/*   Updated: 2023/03/14 13:49:32 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>

class FragTrap : public ClapTrap {
public:
    // Constructors and destructor
    FragTrap(void);
    FragTrap(const std::string name);
    FragTrap(const FragTrap& other);
    ~FragTrap(void);

    // Member functions
    void highFivesGuys(void);
};

#endif 
