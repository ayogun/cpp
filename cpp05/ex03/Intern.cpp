/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 20:03:34 by yogun             #+#    #+#             */
/*   Updated: 2023/04/11 14:17:10 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

// Default Constructor	
Intern::Intern(void)
{
	std::cout << "Intern created with default constructor" << std::endl;
	return ;
}

// Copy Constructor
Intern::Intern(const Intern &src)
{
	std::cout << "Intern created with copy constructor" << std::endl;
	*this = src;
}

// Deconstructor	
Intern::~Intern(void)
{
	std::cout << "Intern destroyed" << std::endl;
	return ;
}

// Overloaded Operator
Intern &Intern::operator=(const Intern &src)
{
	if (this != &src)
	{
		std::cout << "Intern couldn't assigned" << std::endl;
	}
	return (*this);
}


/*
pdf requierement:
	The intern has one important capacity: the makeForm() function. 
	It takes two strings. 
	The first one is the name of a form and the second one is the target of the form. 
	It return a pointer to a Form object (whose name is the one passed as parameter) 
	whose target will be initialized to the second parameter.
	It will print something like:
   	Intern creates <form>
	If the form name passed as parameter doesn’t exist, print an explicit error message.
*/
AForm *Intern::makeForm(std::string form, std::string name)
{
	// We create an array of strings with the names of the forms
    std::string formNames[3] = {
									"RobotomyRequestForm", 
									"PresidentialPardonForm", 
									"ShrubberyCreationForm"
									};
	// We create an array of pointers to AForm objects
	AForm*    forms[3] = {
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