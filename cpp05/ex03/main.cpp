/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 21:47:44 by yogun             #+#    #+#             */
/*   Updated: 2023/04/11 14:23:20 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main(void)
{
	{
		Bureaucrat burokrat ("Last Year Student", 1); //We create a bureaucrat with the highest grade possible and the name `Last Year Student`
		Intern stajyer;									// We create an intern called `stajyer`

		std::cout << std::endl;

		// makeForm function take two strings. The first one is the name of a form and the second one is the name of the object.
		// We tell to our intern to create a form called 
		AForm *formx = stajyer.makeForm("ShrubberyCreationForm", "SomeRandomTarget1");	
		formx = stajyer.makeForm("PresidentialPardonForm", "SomeRandomTarget2");

		std::cout << std::endl;
		std::cout << burokrat;
		std::cout << std::endl;

		std::cout << "_________" << std::endl;

		try
		{
			formx->beSigned(burokrat);
			formx->execute(burokrat);
		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << burokrat.getName() << " couldn't be signed " << formx->getName() << ": " << e.what() << std::endl;
		}


		std::cout << std::endl << std::endl;
		delete formx;
		std::cout << std::endl;
	}

	{
		std::cout << "_________" << std::endl;
		std::cout << "_________" << std::endl<< std::endl;
		Bureaucrat burokrat ("Last Year Student", 1);
		
		Intern someRandomIntern;
		AForm* rrf;
		

		rrf = someRandomIntern.makeForm("RobotomyRequestForm", "Bender");

		try
		{
			rrf->beSigned(burokrat);
			rrf->execute(burokrat);
		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << burokrat.getName() << " couldn't be signed " << rrf->getName() << ": " << e.what() << std::endl;
		}
		
	}

	return (0);
}