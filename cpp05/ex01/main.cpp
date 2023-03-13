/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 21:47:44 by yogun             #+#    #+#             */
/*   Updated: 2023/03/13 23:45:03 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	{
		try
		{
			Form		SampleForm("SampleForm", 0, 10);
			Form		SampleForm2("SampleForm2", 1, 151);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
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