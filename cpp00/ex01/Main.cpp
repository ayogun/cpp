/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 17:38:27 by yogun             #+#    #+#             */
/*   Updated: 2023/02/02 11:57:18 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

 int main(void)
 {
	Phonebook	phonebook;
	std::string	line;
	bool		is_loop;

	is_loop = true;
	std::cout << "PHONEBOOK: ";
	while (is_loop == true && std::getline(std::cin, line))
	{
		if (line.compare("ADD") == 0)
			phonebook.add();
		else if (line.compare("SEARCH") == 0)
			phonebook.search();
		else if (line.compare("EXIT") == 0)
			is_loop = false;
	}
	return 0;
 }