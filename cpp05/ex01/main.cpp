/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 21:47:44 by yogun             #+#    #+#             */
/*   Updated: 2023/03/16 17:55:09 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	{
		try
		{
			Form		SampleForm("SampleForm", 0, 10); std::cout << std::endl;
			//Form		SampleForm2("SampleForm2", 1, 151); std::cout << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	std::cout << std::endl; std::cout << "______________________________________________________" << std::endl; std::cout << std::endl;
	
	{
		try
		{
			Bureaucrat	Student("First Year Student", 150);
			Form		Graduate("Graduation", 1, 10);

			std::cout << Graduate;
			std::cout << Student;
			Student.signForm(Graduate);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	std::cout << std::endl; std::cout << "______________________________________________________" << std::endl; std::cout << std::endl;
	
	{
		try
		{
			Bureaucrat	Student("Last Year Student", 1);
			Form		Graduate("Graduation", 1, 10);

			std::cout << Student;
			std::cout << Graduate;

			Student.signForm(Graduate);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	std::cout << std::endl; std::cout << "______________________________________________________" << std::endl; std::cout << std::endl;

	{
		try
		{
			Bureaucrat	Student("Last Year Student", 1);
			Form		Graduate("Graduation", 1, 10);

			std::cout << Student;
			std::cout << Graduate;

			Student.decrementGrade();
			std::cout << Student;

			Student.signForm(Graduate);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	return (0);
}