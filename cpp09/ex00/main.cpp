/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 01:15:06 by yogun             #+#    #+#             */
/*   Updated: 2023/03/25 16:38:14 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc , char **argv)
{
	(void)argv;
	if (argc != 2)
	{
		std::cerr << "File path is missing." << std::endl;
		return (0);
	}
	Bitcoin bitcoin;
	
	// argv[1] is the file path.
	bitcoin.checkInputFile(argv[1]);
	
	
	// // Get the data from the map.
	// std::map<std::string, float> data = bitcoin.getData();

	// // Print the data.
	// for (std::map<std::string, float>::iterator it = data.begin(); it != data.end(); it++)
	// {
	// 	std::cout << it -> first << " " << it -> second << std::endl;
	// }
}