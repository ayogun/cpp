/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 21:34:11 by yogun             #+#    #+#             */
/*   Updated: 2023/03/15 22:21:35 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main() {
	FragTrap fragtrap("miniFragTrap");
	fragtrap.highFivesGuys();
	
	std::cout << std::endl;
	
	FragTrap fragtrap2("bigFragTrap");
	fragtrap2.highFivesGuys();

	std::cout << std::endl;
	
	std::cout << "High fives are over." << std::endl;
	
    return 0;
}
