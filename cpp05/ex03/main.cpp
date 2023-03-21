/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 21:47:44 by yogun             #+#    #+#             */
/*   Updated: 2023/03/21 21:15:49 by yogun            ###   ########.fr       */
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
		Bureaucrat burokrat ("Last Year Student", 1);;
		Intern stajyer;

		std::cout << std::endl;
		AForm *formx = stajyer.makeForm("ShrubberyCreationForm", "SomeRandomTarget1");	
		formx = stajyer.makeForm("PresidentialPardonForm", "SomeRandomTarget2");


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

	return (0);
}