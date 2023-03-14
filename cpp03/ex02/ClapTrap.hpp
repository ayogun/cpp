/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 21:26:50 by yogun             #+#    #+#             */
/*   Updated: 2023/03/14 13:49:12 by yogun            ###   ########.fr       */
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

    // Member function that causes the object to attack the given target, causing damage equal to the object's attack damage. 
    // This function also consumes 1 energy point.
    void attack(const std::string& target);
    // Member function that causes the object to take damage equal to the given amount of hit points.
    void takeDamage(unsigned int amount);
    // Member function that causes the object to be repaired for the given amount of hit points. 
    // This function also consumes 1 energy point.
    void beRepaired(unsigned int amount);
	
	// Getters
	std::string		getName( void ) const;
	unsigned int 	getAttackDamage() const;
	unsigned int 	getHitPoints() const;
	unsigned int 	getEnergyPoints() const;
	
	// Setters
	void			setName( const std::string name );
	void			setAttackDamage( unsigned int attackDamage );
	void			setHitPoints( unsigned int hitPoints );
	void			setEnergyPoints( unsigned int energyPoints );

	

  private:
    std::string name_;
    int hitPoints_;
    int energyPoints_;
    int attackDamage_;

	protected:
		ClapTrap(void); // Default constructor. It is protected because we don't want to create a ClapTrap without a name. This means that it can only be accessed by the class itself and its derived classes, but not by other classes or functions outside of the class hierarchy. For example, the ClapTrap constructor that takes a name parameter is used to set the name member variable, which is required for the ClapTrap object to function correctly. By making the default constructor protected, the class designer can ensure that all ClapTrap objects are initialized with a valid name.
};

#endif
