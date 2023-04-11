/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 20:03:27 by yogun             #+#    #+#             */
/*   Updated: 2023/04/11 14:06:25 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include <string>
#include <iostream>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
	public:
	// Constructor methods
		Intern(void);	// Default Constructor
		Intern(const Intern &src); // Copy Constructor

		~Intern(void); // Deconstructor

		Intern &operator=(const Intern &src); 	// Overloaded Operator

		// pdf requierement
		AForm *makeForm(const std::string form, const std::string target);

};

#endif