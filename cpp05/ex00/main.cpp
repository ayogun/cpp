/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 21:47:44 by yogun             #+#    #+#             */
/*   Updated: 2023/03/13 21:50:28 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    try {
        Bureaucrat b("John", 1);
        std::cout << b << std::endl;
        b.incrementGrade();
        std::cout << b << std::endl;
        b.incrementGrade(); // should throw exception
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    try {
        Bureaucrat b("Bob", 150);
        std::cout << b << std::endl;
        b.decrementGrade();
        std::cout << b << std::endl;
		    b.decrementGrade(); // should throw exception
	} catch (std::exception& e) {
    std::cout << e.what() << std::endl;
	}

	try {
    	Bureaucrat b("Alice", 200); // should throw exception
	} catch (std::exception& e) {
    std::cout << e.what() << std::endl;
	}
	
	try {
	    Bureaucrat b("Charlie", 0); // should throw exception
	} catch (std::exception& e) {
	    std::cout << e.what() << std::endl;
	}
	
	return (0);
}

