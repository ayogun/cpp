/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 01:15:06 by yogun             #+#    #+#             */
/*   Updated: 2023/04/11 16:47:31 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

// It will be used as a function for the iter function.
// The function will change the char to uppercase.
// Any other function could be used here as well.
// I choose this one because it is easy to see the result.
// And easy to implement lol.
void ft_toupper(char &array)
{
	array = std::toupper(array);
}

int main()
{
	char arr[3] = {'a', 'b', 'c'};

	std::cout << "Original:" << std::endl;
	std::cout << "a[0]: " << arr[0] << std::endl;
	std::cout << "a[1]: " << arr[1] << std::endl;
	std::cout << "a[2]: " << arr[2] << std::endl;
	std::cout << std::endl;
	
	/*********************************/
	iter(arr, 3, ft_toupper);
	/*********************************/

	std::cout << "Changed:" << std::endl;
	std::cout << "a[0]: " << arr[0] << std::endl;
	std::cout << "a[1]: " << arr[1] << std::endl;
	std::cout << "a[2]: " << arr[2] <<std::endl; 
	std::cout << std::endl;

	return 0;
}