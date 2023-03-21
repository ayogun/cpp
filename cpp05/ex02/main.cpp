/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 21:47:44 by yogun             #+#    #+#             */
/*   Updated: 2023/03/21 20:01:14 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	
		try
		{
			Bureaucrat					Student("Last Year Student", 1);
			PresidentialPardonForm		pre_form("Presidential");
			RobotomyRequestForm			rob_form("robotomy");
			ShrubberyCreationForm		shr_form("Shrubbery");

			std::cout<< std::endl << "______________________________________________________" << std::endl << std::endl;

			std::cout << pre_form << std::endl;
			std::cout << rob_form << std::endl;
			std::cout << shr_form << std::endl;
			std::cout << Student << std::endl;

			std::cout<< std::endl << "______________________________________________________" << std::endl << std::endl;

			Student.signForm(pre_form);
			Student.executeForm(pre_form);

			Student.signForm(rob_form);
			Student.executeForm(rob_form);

			Student.signForm(shr_form);
			Student.executeForm(shr_form);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	

	// std::cout << std::endl << "__________________________________________________________________" << std::endl << std::endl;
	
	// {
	// 	try
	// 	{
	// 		Bureaucrat					Student("Last Year Student", 1);
	// 		PresidentialPardonForm		pre_form("Presidential");

	// 		std::cout << pre_form;
	// 		std::cout << Student;

	// 		std::cout << std::endl;

	// 		Student.executeForm(pre_form);
	// 	}
	// 	catch(const std::exception& e)
	// 	{
	// 		std::cerr << e.what() << '\n';
	// 	}
	// }

	// std::cout << std::endl << "__________________________________________________________________" << std::endl << std::endl;
	
	// {
	// 	try
	// 	{
	// 		Bureaucrat					Student("First Year Student", 150);
	// 		RobotomyRequestForm			rob_form("Robotomy");

	// 		std::cout << rob_form;
	// 		std::cout << Student;

	// 		std::cout << std::endl;

	// 		Student.signForm(rob_form);
	// 	}
	// 	catch(const std::exception& e)
	// 	{
	// 		std::cerr << e.what() << '\n';
	// 	}
	// }

	// std::cout << std::endl << "__________________________________________________________________" << std::endl << std::endl;

	// {
	// 	try
	// 	{
	// 		Bureaucrat					Student("Second Year Student", 72);
	// 		RobotomyRequestForm			rob_form("Robotomy");

	// 		std::cout << rob_form;
	// 		std::cout << Student;

	// 		std::cout << std::endl;

	// 		Student.signForm(rob_form);
			
	// 		//std::cout << "calistim" << std::endl;
	// 		Student.executeForm(rob_form);
	// 	}
	// 	catch(const std::exception& e)
	// 	{
	// 		std::cerr << e.what() << '\n';
	// 	}
	// }
	return (0);
}