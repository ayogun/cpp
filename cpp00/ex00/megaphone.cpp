/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 14:27:06 by yogun             #+#    #+#             */
/*   Updated: 2023/03/14 12:45:33 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
/*
	This program takes a string as an argument and prints it in uppercase letters.
	If no argument is given, it prints "* LOUD AND UNBEARABLE FEEDBACK NOISE *".
*/
int	main(int argc, char **argv)
{
	std::string str;
	int counter = 1;
	
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	while (counter < argc)
	{
		str = argv[counter];
		for (size_t i = 0; i < str.size(); i++)
			str[i] = std::toupper(str[i]);
		std::cout << str;
		counter++;
	}
	std::cout << std::endl;
	return 0;
}
