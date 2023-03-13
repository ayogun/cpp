/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 21:27:13 by yogun             #+#    #+#             */
/*   Updated: 2023/03/13 12:10:31 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() {
  ClapTrap clapTrap1("Bob");
  ClapTrap clapTrap2("Enemy");
  clapTrap1.attack("Enemy");
  clapTrap1.beRepaired(5);
  clapTrap1.takeDamage(3);
  clapTrap2.attack("Bob");
  clapTrap2.beRepaired(7);
  clapTrap2.takeDamage(11);
  return 0;
}
