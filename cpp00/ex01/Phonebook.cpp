/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 17:29:00 by yogun             #+#    #+#             */
/*   Updated: 2023/03/14 13:32:22 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

// Default Constructor
Phonebook::Phonebook(void)
{
	std::cout << "Welcome to Phonebook"<<std::endl;
	std::cout << "You can use three commands" << std::endl;
	std::cout << "<ADD> <SEARCH> <EXIT>" << std::endl;
	std::cout << "--------------------" << std::endl;
	this->index = 0;
	return ;
}

// Destructor 
Phonebook::~Phonebook(void)
{
	return ;
}

// *****************  Member Functions  *****************

void	Phonebook::add(void)
{
	int		index;

	index = this->index;
	if (index > 7)
		index = this->index % 8;
	this->contact[index].set_contact(index);
	this->index++;
	std::cout << std::endl << "Contact added !" << std::endl << std::endl;
	return ;
}

void	Phonebook::search(void)
{
	std::string line;
	int			i;

	if (this->index == 0)
	{
		std::cout << "No Contacts Found!\n";
		return ;
	}
	this->display_contacts();
	std::cout << "SEARCH: ";
	std::getline(std::cin, line);
	if (std::isdigit(line[0]) && line.length() == 1)
	{
		i = std::atoi(line.c_str());
		if (i >= this->index || i > 7)
			std::cout << "Error! ID is out of range!\n";
		else
		{
			std::cout << "First Name: " << this->contact[i].get_firstname() << std::endl;
			std::cout << "Last Name: " << this->contact[i].get_lastname() << std::endl;
			std::cout << "Nickname: " << this->contact[i].get_nickname() << std::endl;
			std::cout << "Phone Number: " << this->contact[i].get_phone() << std::endl;
			std::cout << "Darkest Secret: " << this->contact[i].get_secret() << std::endl;
		}
	}
	else
		std::cout << "Error! ID is not valid.\n";
}

// This is a helper function to print the contacts
static void print_contacts(std::string str)
{
	int	i;
	int	j;

	std::cout << "|";
	i = str.length();
	if (i > 10) // Truncate string if it is longer than 10
	{
		for(j = 0; j < 9; j++)
			std::cout << str[j];
		std::cout << ".";
	}
	else
	{
		std::cout << str;
		while (i < 10)
		{
			std::cout << " ";
			i++;
		}
	}
}

void	Phonebook::display_contacts(void)
{
	int	j;

	std::cout << "|Index     |First Name|Last Name |Nickname  |\n";
	j = 0;
	while(j < this->index && j < 8)
	{
		print_contacts(this->contact[j].get_id());
		print_contacts(this->contact[j].get_firstname());
		print_contacts(this->contact[j].get_lastname());
		print_contacts(this->contact[j].get_nickname());
		std::cout << "|" << std::endl;
		j++;
	}
}
