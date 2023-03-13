/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:40:08 by yogun             #+#    #+#             */
/*   Updated: 2023/03/13 14:46:26 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

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
