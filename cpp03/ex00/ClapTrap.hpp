/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 21:26:50 by yogun             #+#    #+#             */
/*   Updated: 2023/03/15 20:12:40 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>

class ClapTrap {
  public:
    // Constructor that initializes the object with the given name and default values for hit points, energy points, and attack damage.
    ClapTrap(const std::string& name);
    // Copy constructor that initializes the object with the same values as another object.
    ClapTrap(const ClapTrap& other);
    // Destructor that displays a message to indicate that the object has been destroyed.
    ~ClapTrap();
	// Copy assignment operator that assigns the values of one object to another.
	ClapTrap & operator=(const ClapTrap & other);
	
    // Member function that causes the object to attack the given target, causing damage equal to the object's attack damage. 
    // This function also consumes 1 energy point.
    void attack(const std::string& target);
    // Member function that causes the object to take damage equal to the given amount of hit points.
    void takeDamage(unsigned int amount);
    // Member function that causes the object to be repaired for the given amount of hit points. 
    // This function also consumes 1 energy point.
    void beRepaired(unsigned int amount);


  private:
  	ClapTrap(); // Default constructor. It is private because we don't want to allow creating objects without a name.
    std::string name_;
    int hitPoints_;
    int energyPoints_;
    int attackDamage_;
};

#endif
