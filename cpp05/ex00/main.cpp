/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 21:47:44 by yogun             #+#    #+#             */
/*   Updated: 2023/04/10 12:29:42 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat b("John", 1);	// Construct a Bureaucrat with name "John" and grade 1
        std::cout << b << std::endl; std::cout << std::endl;	// Print the Bureaucrat
        b.incrementGrade(); // Try to increase his grade. It should throw exception since he has maximum grade already.
    } 
    catch (std::exception& e) 
    {
        std::cout << e.what() << std::endl;	// Print the exception
    }

    std::cout << "---------------------------------------" << std::endl;std::cout << std::endl;

    try 
    {
        Bureaucrat b("Bob", 150);	// Construct a Bureaucrat with name "Bob" and grade 150
        std::cout << b << std::endl;	// Print the Bureaucrat
		b.decrementGrade(); // should throw exception
	} 
    catch (std::exception& e)
    {
    std::cout << e.what() << std::endl;	// Print the exception
	}

   std::cout << "---------------------------------------" << std::endl;std::cout << std::endl;

	try 
    {
    	Bureaucrat b("Alice", 200); // Construct a Bureaucrat with name "Alice" and grade 200. Should throw exception. Because Bureaucrat's grade can't be higher than 150.
	} 
    catch (std::exception& e) 
    {
    std::cout << e.what() << std::endl;
	}

    std::cout << "---------------------------------------" << std::endl;std::cout << std::endl;
	
	try 
    {
	    Bureaucrat b("Charlie", 0); // Construct a Bureaucrat with name "Charlie" and grade 0. Should throw exception. Because Bureaucrat's grade can't be lower than 1.
	} 
    catch (std::exception& e) 
    {
	    std::cout << e.what() << std::endl;
	}
	
	return (0);
}

