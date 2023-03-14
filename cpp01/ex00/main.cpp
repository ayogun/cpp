/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 12:08:01 by yogun             #+#    #+#             */
/*   Updated: 2023/03/14 13:34:40 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// Function to test the newZombie() function
void testNewZombie() {
    // Create a new zombie on the heap
    Zombie* zombie = newZombie("TestZombie");

    // Have the zombie announce itself
    zombie->announce();

    // Deallocate the zombie object from the heap
    delete zombie;
}

// Function to test the randomChump() function
void testRandomChump() {
    // Create a new zombie on the stack and have it announce itself
    randomChump("RandomZombie");
}

int main() {
    // Test the newZombie() function
    testNewZombie();

    // Test the randomChump() function
    testRandomChump();

    return 0;
}
