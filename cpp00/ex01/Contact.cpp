/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 17:29:07 by yogun             #+#    #+#             */
/*   Updated: 2023/02/01 23:20:43 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

// Constructor is called
Contact::Contact(void)
{
	return ;
}

// Deconstructor is called
Contact::~Contact(void)
{
	return ;
}

void	Contact::set_contact(int id)
{
	this->_id = std::to_string(id);
	std::cout << "Enter First Name: ";
	std::getline(std::cin, this->_firstname);
	while (this->_firstname.length() == 0)
	{
		std::cout << "Field Can't Be Empty!\nEnter First Name: ";
		std::getline(std::cin, this->_firstname);
	}
	std::cout << "Enter Last name: ";
	std::getline(std::cin, this->_lastname);
	while (this->_lastname.length() == 0)
	{
		std::cout << "Field Can't Be Empty!\nEnter Last Name: ";
		std::getline(std::cin, this->_lastname);
	}
	std::cout << "Enter Nickname: ";
	std::getline(std::cin, this->_nickname);
	while (this->_nickname.length() == 0)
	{
		std::cout << "Field Can't Be Empty!\nEnter Nickname: ";
		std::getline(std::cin, this->_nickname);
	}
	std::cout << "Enter Phone Number: ";
	std::getline(std::cin, this->_phone);
	while (this->_phone.length() == 0)
	{
		std::cout << "Field Can't Be Empty!\nEnter Phone Number: ";
		std::getline(std::cin, this->_phone);
	}
	std::cout << "Enter Darkest Secret: ";
	std::getline(std::cin, this->_secret);
	while (this->_secret.length() == 0)
	{
		std::cout << "Field Can't Be Empty!\nEnter Darkest Secret: ";
		std::getline(std::cin, this->_secret);
	}
}

std::string	Contact::get_id(void)
{
	return(this->_id);
}

std::string	Contact::get_firstname(void)
{
	return(this->_firstname);
}

std::string	Contact::get_lastname(void)
{
	return(this->_lastname);
}

std::string	Contact::get_nickname(void)
{
	return(this->_nickname);
}

std::string	Contact::get_phone(void)
{
	return(this->_phone);
}

std::string	Contact::get_secret(void)
{
	return(this->_secret);
}