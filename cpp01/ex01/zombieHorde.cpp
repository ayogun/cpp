/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 18:23:03 by yogun             #+#    #+#             */
/*   Updated: 2023/03/07 08:32:54 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/*
 	The function takes two parameters: N, which is the number of zombies to create, and name, which is the name to give to each zombie in the horde.

	The function allocates N Zombie objects in a single allocation using the new operator. It then initializes each zombie with the same name using the setName() function of the Zombie class. Finally, the function returns a pointer to the first zombie in the horde.
*/
Zombie* zombieHorde(int N, std::string name) {

    Zombie* horde = new Zombie[N]; // Allocate N Zombie objects in a single allocation
    for (int i = 0; i < N; i++) {
        horde[i].setName(name + "-number-" + std::to_string(i)); // Initialize each zombie with the same name
    }
    return horde; // Return a pointer to the first zombie in the horde
}
