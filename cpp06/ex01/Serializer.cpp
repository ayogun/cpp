/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 01:14:17 by yogun             #+#    #+#             */
/*   Updated: 2023/03/22 19:27:30 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

// Default constructor
Serializer::Serializer(void)
{
	std::cout << "Default Constructor" << std::endl;
	return ;
}

// Copy constructor
Serializer::Serializer(const Serializer &src)
{
	std::cout << "Copy Constructor" << std::endl;
	*this = src;
	return ;
}

// Deconstructor
Serializer::~Serializer(void)
{
	std::cout << "Serializer Deconstructor" << std::endl;
	return ;
}

// Overloaded Operator
Serializer &Serializer::operator=(const Serializer &src)
{
	std::cout << "Serializer Assignation operator" << std::endl;
	if (this == &src)
		return *this;

	return *this;
}

// Member functions
// Here we cast the uintptr_t to a pointer to Data
Data	*Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}

// Here we cast the pointer to a uintptr_t
uintptr_t	Serializer::serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}