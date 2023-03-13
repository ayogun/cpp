#include "ClapTrap.hpp"
#include <iostream>

// Default constructor
ClapTrap::ClapTrap(void) {
	std::cout << "ClapTrap default constructed with default constructor" << std::endl;
}

// Constructor that initializes the object with the given name and default values for hit points, energy points, and attack damage.
ClapTrap::ClapTrap(const std::string& name) :
  name_(name),
  hitPoints_(10),
  energyPoints_(10),
  attackDamage_(0) {
    std::cout << "ClapTrap " << name_ << " constructed with constructor" << std::endl;
}

// Copy constructor that initializes the object with the same values as another object.
ClapTrap::ClapTrap(const ClapTrap& other) :
  name_(other.name_),
  hitPoints_(other.hitPoints_),
  energyPoints_(other.energyPoints_),
  attackDamage_(other.attackDamage_) {
    std::cout << "ClapTrap " << name_ << " constructed by copy" << std::endl;
}

// Destructor that displays a message to indicate that the object has been destroyed.
ClapTrap::~ClapTrap() {
  std::cout << "ClapTrap " << name_ << " destructed" << std::endl;
}

// Member function that causes the object to attack the given target, causing damage equal to the object's attack damage. 
// This function also consumes 1 energy point.
void ClapTrap::attack(const std::string& target) {
  if (energyPoints_ >= 1) { // If the object has at least 1 energy point
    energyPoints_ -= 1; // Consume 1 energy point
    std::cout << "ClapTrap " << name_ << " attacks " << target << ", causing " << attackDamage_ << " points of damage!" << std::endl;
  } else { // If the object has no energy points
    std::cout << "ClapTrap " << name_ << " is out of energy and cannot attack!" << std::endl;
  }
}

// Member function that causes the object to take damage equal to the given amount of hit points.
void ClapTrap::takeDamage(unsigned int amount) {
  if (hitPoints_ >= static_cast<int>(amount)) { // If the object has enough hit points to take the given amount of damage
    hitPoints_ -= amount; // Take the damage
    std::cout << "ClapTrap " << name_ << " takes " << amount << " points of damage!" << std::endl;
  } else { // If the object doesn't have enough hit points to take the given amount of damage
    hitPoints_ = 0; // Set hit points to 0
    std::cout << "ClapTrap " << name_ << " takes " << amount << " points of damage and is destroyed!" << std::endl;
  }
}

// Member function that causes the object to be repaired for the given amount of hit points. 
// This function also consumes 1 energy point.
void ClapTrap::beRepaired(unsigned int amount) {
  if (energyPoints_ >= 1) { // If the object has at least 1 energy point
    energyPoints_ -= 1; // Consume 1 energy point
    hitPoints_ += amount; // Heal the object
    std::cout << "ClapTrap " << name_ << " is repaired for " << amount << " hit points!" << std::endl;
  } else { // If the object has no energy points
    std::cout << "ClapTrap " << name_ << " is out of energy and cannot be repaired!" << std::endl;
  }
}

// Getter for name
std::string ClapTrap::getName() const {
    return name_;
}

// Getter for attackDamage
unsigned int ClapTrap::getAttackDamage() const {
    return attackDamage_;
}

// Getter for hitPoints
unsigned int ClapTrap::getHitPoints() const {
	return hitPoints_;
}

// Getter for energyPoints
unsigned int ClapTrap::getEnergyPoints() const {
	return energyPoints_;
}

// Setter for name
void ClapTrap::setName(const std::string name) {
	name_ = name;
}

// Setter for attackDamage
void ClapTrap::setAttackDamage(unsigned int attackDamage) {
	attackDamage_ = attackDamage;
}

// Setter for hitPoints
void ClapTrap::setHitPoints(unsigned int hitPoints) {
	hitPoints_ = hitPoints;
}

// Setter for energyPoints
void ClapTrap::setEnergyPoints(unsigned int energyPoints) {
	energyPoints_ = energyPoints;
}

