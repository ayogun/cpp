/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 21:34:33 by yogun             #+#    #+#             */
/*   Updated: 2023/03/14 13:41:41 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

// Default constructor
Harl::Harl(void)
{
	ptr[0] = &Harl::debug;
	ptr[1] = &Harl::info;
	ptr[2] = &Harl::warning;
	ptr[3] = &Harl::error;
	return ;
}

// Destructor
Harl::~Harl(void)
{
	return ;
}

// **********************  Member functions  ****************************
void Harl::debug(void) {
    std::cout << "[ DEBUG]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger.\nI really do!\n\n";
}

void Harl::info(void) {
    std::cout << "[ INFO ] \nI cannot believe adding extra bacon costs more money.\nYou didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n\n";
}

void Harl::warning(void) {
    std::cout << "[ WARNING ]\nI think I deserve to have some extra bacon for free.\nI’ve been coming for years whereas you started working here since last month.\n\n";
}

void Harl::error(void) {
    std::cout << "[ ERROR ]\nThis is unacceptable!\nI want to speak to the manager now.\n\n";
}

void Harl::complain(std::string level) {
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    
    int i = 0;
    while (i < 4 && level.compare(levels[i])) {
        i++;
    }
    
    if (i < 4) {
		while(i > -1){
			(this->*ptr[i])();
			i--;
		}
    } else {
        std::cout << "Invalid level!\n";
    }
}