/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 18:23:16 by yogun             #+#    #+#             */
/*   Updated: 2023/03/06 19:12:23 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/*
	We declare the number of zombies in the horde (N) and the name of the zombies (name). We then call the zombieHorde() function to create a horde of N zombies with the same name. We store the pointer to the first zombie in the horde variable.

	We use a for loop to announce each zombie in the horde by calling the announce() function of the Zombie class. Finally, we delete the zombies using the delete[] operator to avoid memory leaks.
*/

int main() {
    int N = 5; // Number of zombies in the horde
    std::string name = "Walker"; // Name of the zombies

    Zombie* horde = zombieHorde(N, name); // Create a horde of zombies with the same name
    for (int i = 0; i < N; i++) {
        horde[i].announce(); // Announce each zombie in the horde
    }

    delete[] horde; // Delete the zombies to avoid memory leaks

    return 0;
}
