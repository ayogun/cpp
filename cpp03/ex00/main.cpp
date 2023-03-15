/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 21:27:13 by yogun             #+#    #+#             */
/*   Updated: 2023/03/15 19:54:48 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() {
  ClapTrap clapTrap1("Bob");
  ClapTrap clapTrap2("Enemy");
  
  std::cout << std::endl;
  
  clapTrap1.attack("Enemy");
  clapTrap1.beRepaired(5);
  clapTrap1.takeDamage(3);

  std::cout << std::endl;
  
  clapTrap2.attack("Bob");
  clapTrap2.beRepaired(7);
  clapTrap2.takeDamage(11);

   std::cout << std::endl;
  
  return 0;
}
