/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 20:03:34 by yogun             #+#    #+#             */
/*   Updated: 2023/03/21 21:08:35 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void)
{
	std::cout << "Intern created with default constructor" << std::endl;
	return ;
}

Intern::Intern(const Intern &src)
{
	std::cout << "Intern created with copy constructor" << std::endl;
	*this = src;
}

Intern::~Intern(void)
{
	std::cout << "Intern destroyed" << std::endl;
	return ;
}

Intern &Intern::operator=(const Intern &src)
{
	if (this != &src)
	{
		std::cout << "Intern couldn't assigned" << std::endl;
	}
	return (*this);
}

AForm *Intern::makeForm(std::string form, std::string name) {
    std::string formNames[3] = {"RobotomyRequestForm", "PresidentialPardonForm", "ShrubberyCreationForm"};
	    AForm*    forms[] = {
								new RobotomyRequestForm(name), 
								new PresidentialPardonForm(name), 
								new ShrubberyCreationForm(name)
							};
    int i = 0;
    while (i < 3 && form.compare(formNames[i]))
        i++;
    switch (i) {
        case 0:
            return forms[0];
        case 1:
            return forms[1];
        case 2:
            return forms[2];
        default:
            std::cout << "Intern couldn't create form" << std::endl;
			return NULL;
    }
}