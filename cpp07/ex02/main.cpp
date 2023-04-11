/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 01:15:06 by yogun             #+#    #+#             */
/*   Updated: 2023/04/11 17:21:55 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main()
{
    // Create an array of 100 integers
    Array<int> numbers(100);
    int* ptrARR = new int[100]; // Create an array of 100 integers with pointert
	
    // seed the random number generator. It provides a different sequence of numbers each time the program is run.
    srand(time(NULL));						
	
	// fill the array with random numbers
    for (int i = 0; i < 100; i++)
    {
        const int value = rand();
        numbers[i] = value;
        ptrARR[i] = value;
    }
    
    //SCOPE 1
    {
        Array<int> tmp(100);    // Create an array of 100 integers
        try
        {
            for (int i = 0; i < 100; i++)
                tmp[i] = 7;
            for (int i = 0; i < 100; i++)
                std::cout << "tmp[" << i << "]:" << tmp[i] << std::endl;
            std::cout << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what();
        }
        
        tmp = numbers;	//copy constructor
        Array<int> test(tmp);	//assignation operator

        try
        {
			// check if the values are the same
            for (int i = 0; i < 100; i++)
        {
            if (tmp[i] != test[i])
            {
                std::cerr << "didn't save the same value!!" << std::endl;
                return 1;
            }
            std::cout << "tmp[" << i << "]:" << tmp[i] << "  -  " <<
             "test[" << i << "]:" << test[i] << std::endl;
        }
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what();
        }

		// Compare those two values to see if they are the same. You will see that they are same.
        std::cout << std::endl << "test[1]:\t" << test[1] << std::endl;
        std::cout << "tmp[1]:\t\t" << tmp[1] << std::endl << std::endl;

        test[1] = 123456789;

		// Now they should be different.
        std::cout << "test[1]:\t" << test[1] << std::endl;
        std::cout << "tmp[1]:\t\t" << tmp[1] << std::endl << std::endl;
    }

    //SCOPE 2
    {
	// Here we try to access the one element more than range. It should throw an error.
    try
    {
        numbers[100] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        std::cout << "You are trying to access out of range. WTF?" << std::endl;
    }
    }

    delete [] ptrARR; // free the memory if you don't want to have a memory leak :'(

    return 0;
}