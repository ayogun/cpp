/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 18:18:33 by yogun             #+#    #+#             */
/*   Updated: 2023/03/06 19:20:59 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP // Include guard to prevent multiple inclusions
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie {
public:
    Zombie(); // Default constructor
    Zombie(std::string name); // Constructor that takes a name
    ~Zombie(); // Deconstructor

    void setName(std::string name); // Setter for the name
    void announce(); // Prints a message to the console announcing the zombie

private:
    std::string _name; // Name of the zombie
};

Zombie* zombieHorde( int N, std::string name );

#endif // End of the include guard for Zombie.hpp