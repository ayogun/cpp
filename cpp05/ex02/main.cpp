/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 21:47:44 by yogun             #+#    #+#             */
/*   Updated: 2023/03/14 00:58:09 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	{
		try
		{
			Bureaucrat					Student("Last Year Student", 1);
			PresidentialPardonForm		p_form("Cat");
			RobotomyRequestForm			r_form("Dog");
			ShrubberyCreationForm		s_form("Diamond");

			std::cout << p_form;
			std::cout << r_form;
			std::cout << s_form;
			std::cout << Student;

			Student.signForm(p_form);
			Student.executeForm(p_form);

			Student.signForm(r_form);
			Student.executeForm(r_form);

			Student.signForm(s_form);
			Student.executeForm(s_form);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	{
		try
		{
			Bureaucrat					Student("Last Year Student", 1);
			PresidentialPardonForm		p_form("Cat");

			std::cout << p_form;
			std::cout << Student;

			Student.executeForm(p_form);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	{
		try
		{
			Bureaucrat					Student("First Year Student", 150);
			RobotomyRequestForm			r_form("Dog");

			std::cout << r_form;
			std::cout << Student;

			Student.signForm(r_form);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	{
		try
		{
			Bureaucrat					Student("Second Year Student", 72);
			RobotomyRequestForm			r_form("Dog");

			std::cout << r_form;
			std::cout << Student;

			Student.signForm(r_form);
			Student.executeForm(r_form);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	return (0);
}