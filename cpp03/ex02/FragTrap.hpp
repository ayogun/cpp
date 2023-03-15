/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:40:08 by yogun             #+#    #+#             */
/*   Updated: 2023/03/15 22:15:13 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>

class FragTrap : public ClapTrap {
public:
    // Constructors
    FragTrap(const std::string name); 
    FragTrap(const FragTrap& other); // Copy constructor
    ~FragTrap(void); // Destructor

	FragTrap & operator=(const FragTrap & other); // Copy assignment operator

    // Member functions
    void highFivesGuys(void);

private:
	FragTrap(void); // Default constructor.
};

#endif 
