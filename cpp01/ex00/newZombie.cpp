/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 12:11:28 by yogun             #+#    #+#             */
/*   Updated: 2023/03/06 15:31:22 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// Function to create a new zombie on the heap
Zombie* newZombie(std::string name) {
    // Allocate a new zombie object on the heap
    Zombie* zombie = new Zombie(name);

    // Return a pointer to the new zombie object
    return zombie;
}
