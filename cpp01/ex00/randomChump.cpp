/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 12:11:42 by yogun             #+#    #+#             */
/*   Updated: 2023/03/06 15:32:12 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// Function to create a new zombie on the stack and make it announce itself
void randomChump(std::string name) {
    // Create a new zombie object on the stack
    Zombie zombie(name);

    // Have the zombie announce itself
    zombie.announce();
}