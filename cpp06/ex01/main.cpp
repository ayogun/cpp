/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 01:15:06 by yogun             #+#    #+#             */
/*   Updated: 2023/03/22 19:45:52 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

	int main( void )
{
    Data *data = new Data;

    delete data;


	Data ptr2;
	ptr2.name = "Ali Yigit Ogun";
	ptr2.age = 29;

	Data ptr;
	ptr.name = "Linus Torvalds";
	ptr.age = 62;

	
	std::cout << "Original structs:" << std::endl;
	std::cout << "\taddress: " << &ptr << std::endl;
	std::cout << "\tname: " << ptr.name << std::endl;
	std::cout << "\tage: " << ptr.age << std::endl << std::endl;

	
	std::cout << std::endl; 

	
	std::cout << "\taddress ptr2: " << &ptr2 << std::endl;
	std::cout << "\tname: " << ptr2.name << std::endl;
	std::cout << "\tage: " << ptr2.age << std::endl;
	std::cout << std::endl ;

	Serializer object;

	Data *reserialized = object.deserialize(object.serialize(&ptr));

	std::cout << "Reserialized structs:" << std::endl;
	std::cout << "\taddress: " << reserialized << std::endl;
	std::cout << "\tname: " << reserialized->name << std::endl;
	std::cout << "\tage: " << reserialized->age << std::endl;

	std::cout << std::endl; 
	
	std::cout << "\taddress ptr2: " << &ptr2 << std::endl;
	std::cout << "\tname: " << ptr2.name << std::endl;
	std::cout << "\tage: " << ptr2.age << std::endl;
	std::cout << std::endl; std::cout << std::endl;

	return (0);

}