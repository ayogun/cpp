/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 20:03:27 by yogun             #+#    #+#             */
/*   Updated: 2023/03/21 20:32:25 by yogun            ###   ########.fr       */
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
		Intern(void);
		Intern(const Intern &src);

		~Intern(void); // Deconstructor

		Intern &operator=(const Intern &src); 	// Overloaded Operator

		AForm *makeForm(const std::string form, const std::string target);

};

#endif