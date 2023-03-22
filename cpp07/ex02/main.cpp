/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 01:15:06 by yogun             #+#    #+#             */
/*   Updated: 2023/03/22 21:22:39 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
	// seed the random number generator. It provides a different sequence of numbers each time the program is run.
    srand(time(NULL));						
	
	// fill the array with random numbers
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp;
        try
        {
            for (int i = 0; i < MAX_VAL + 1; i++)
                std::cout << "tmp[" << i << "]:\t" << tmp[i] << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\t';
            std::cerr << "You tried to access past the last element of the array" << std::endl;
        }
        tmp = numbers;	//copy constructor
        Array<int> test(tmp);	//assignation operator

        try
        {
			// check if the values are the same
            for (int i = 0; i < MAX_VAL + 1; i++)
        {
            if (tmp[i] != test[i])
            {
                std::cerr << "didn't save the same value!!" << std::endl;
                return 1;
            }
            // std::cout << "tmp[" << i << "]:\t" << tmp[i] << std::endl; //uncomment these two lines to see the arrays have the same values
            // std::cout << "test[" << i << "]:\t" << test[i] << std::endl;
        }
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\t';
            std::cerr << "You tried to access past the last element of the array" << std::endl;
        }

		// Compare those two values to see if they are the same. You will see that they are same.
        std::cout << std::endl << "test[1]:\t" << test[1] << std::endl;
        std::cout << "tmp[1]:\t\t" << tmp[1] << std::endl << std::endl;

        test[1] = 123456789;

		// Now they should be different.
        std::cout << "test[1]:\t" << test[1] << std::endl;
        std::cout << "tmp[1]:\t\t" << tmp[1] << std::endl << std::endl;
    }

	// check if the values are the same
    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }

	// here we will try to access an element that is out of the array's bounds. It should throw an exception.
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        std::cout << "index was -2" << std::endl;
    }
	
	// Here we try to access the one element more than range. It should throw an error.
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        std::cout << "tried to access past the last element of the array" << std::endl;
    }

	// Here we populate the array with random numbers again.
    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;
	
	// Here we print the array. Uncomment this to see the array.
    // for (int i = 0; i < MAX_VAL; i++)
    // {
    //     std::cout << numbers[i] << std::endl;
    // }
    return 0;
}