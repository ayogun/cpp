/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 21:34:13 by yogun             #+#    #+#             */
/*   Updated: 2023/03/14 13:40:33 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv)
{
	Harl		Harl;

	if (argc == 2)
		Harl.complain(argv[1]);
	else if (argc < 2)
		std::cerr << "Error! No input has given" << std::endl;
	else
		std::cerr << "Please one input(complain level) at a time!" << std::endl;
	return (0);
}
