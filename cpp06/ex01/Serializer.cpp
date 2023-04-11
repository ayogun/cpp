/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 01:14:17 by yogun             #+#    #+#             */
/*   Updated: 2023/04/11 15:33:49 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

/*
	reinterpret_cast is a type of C++ type casting operator 
	that allows you to reinterpret the binary representation 
	of an object of one type as an object of another type without 
	changing the actual bits of the object. It is the most powerful 
	and dangerous type casting operator in C++, as it allows you 
	to bypass type safety checks and can result in undefined behavior 
	if used improperly.
*/

// Default constructor
Serializer::Serializer(void)
{
	//std::cout << "Default Constructor" << std::endl;
	return ;
}

// Copy constructor
Serializer::Serializer(const Serializer &src)
{
	//std::cout << "Copy Constructor" << std::endl;
	*this = src;
	return ;
}

// Deconstructor
Serializer::~Serializer(void)
{
	//std::cout << "Serializer Deconstructor" << std::endl;
	return ;
}

// Overloaded Operator
Serializer &Serializer::operator=(const Serializer &src)
{
	//std::cout << "Serializer Assignation operator" << std::endl;
	if (this == &src)
		return *this;

	return *this;
}

// Member functions
// Here we cast the uintptr_t to a pointer to Data
Data	*Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));		// reinterpret_cast is used because we are casting a pointer to a different type
}

// Here we cast the pointer to a uintptr_t
uintptr_t	Serializer::serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}