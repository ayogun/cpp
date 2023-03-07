/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 21:05:59 by yogun             #+#    #+#             */
/*   Updated: 2023/03/07 08:33:27 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(void) {
    // Define a string variable and initialize it to "HI THIS IS BRAIN"
    std::string myString = "HI THIS IS BRAIN";
    
    // Define a pointer to the string and initialize it to the address of myString
    std::string* stringPTR = &myString;
    
    // Define a reference to the string and initialize it to myString
    std::string& stringREF = myString;
    
    // Print the memory addresses of the string variable, pointer, and reference
    std::cout << "Memory address of the string variable: " << &myString << std::endl;
    std::cout << "Memory address held by stringPTR: " << stringPTR << std::endl;
    std::cout << "Memory address held by stringREF: " << &stringREF << std::endl;
    
	std::cout << std::endl;
	
    // Print the values of the string variable, pointer, and reference
    std::cout << "Value of the string variable: " << myString << std::endl;
    std::cout << "Value pointed to by stringPTR: " << *stringPTR << std::endl;
    std::cout << "Value pointed to by stringREF: " << stringREF << std::endl;
    
    return 0;
}
