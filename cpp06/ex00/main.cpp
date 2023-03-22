/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 01:15:06 by yogun             #+#    #+#             */
/*   Updated: 2023/03/22 15:34:39 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		if (argv[1] == NULL)
			return 0;

		// Input is taken as a string with the object constructor
		Converter object(argv[1]);
		
		if (object.NanMessage() != false)
			return 0;

		std::cout << std::endl;std::cout << std::endl;

		try { std::cout << "char: " << object.toChar() << std::endl; }
		catch(const std::exception& e) { std::cerr << e.what() << std::endl; }
		
		try
		{
			std::cout << "int: " << object.toInt() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		try
		{
			std::cout << "Float: " << object.toFloat();
			if (object.getType() == INT)
				std::cout << ".0";
			std::cout << 'f' << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		try
		{
			std::cout << "double: " << object.toDouble();
			if (object.getType() == INT)
				std::cout << ".0";
			std::cout << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}		
	}
	else
		std::cerr << "One argument required!" << std::endl;
	return (0);
}