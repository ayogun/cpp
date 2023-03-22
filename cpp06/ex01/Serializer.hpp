/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 01:14:17 by yogun             #+#    #+#             */
/*   Updated: 2023/03/22 19:22:03 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <string>
#include <iostream>
#include <stdint.h> // with this lib uintptr_t will compile with c++98 standard


// Data structure that has been mentioned in the pdf
typedef struct Data
{
	std::string	name;
	size_t		age;
}				Data;

class Serializer
{
	public:
	// Default constructor
		Serializer(void);
		Serializer(const Serializer &src);	// Copy constructor

	// Deconstructor
		~Serializer(void);

	// Overloaded Operator
		Serializer &operator=(const Serializer &src);

/*******************************************************************/

	// MEMBER Methods
		uintptr_t serialize(Data *ptr);
		Data *deserialize(uintptr_t raw);

};

#endif