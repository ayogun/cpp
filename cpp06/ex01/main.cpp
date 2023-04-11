/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 01:15:06 by yogun             #+#    #+#             */
/*   Updated: 2023/04/11 15:31:07 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

	int main( void )
{
	uintptr_t address;

	Data human;
	human.name = "Ali Yigit Ogun";
	human.age = 29;

	Data human2;
	human2.name = "Linus Torvalds";
	human2.age = 62;

	
	/*********************** sample *********************************/
	std::cout << "Original structs:" << std::endl;
	std::cout << "\taddress human: " << &human << std::endl;
	std::cout << "\tname: " << human.name << std::endl;
	std::cout << "\tage: " << human.age << std::endl << std::endl;

	
	std::cout << std::endl; 

	
	std::cout << "\taddress human2: " << &human2 << std::endl;
	std::cout << "\tname: " << human2.name << std::endl;
	std::cout << "\tage: " << human2.age << std::endl;
	std::cout << std::endl ;

	/*********************** sample *********************************/



	/********************** SERIALIZER *************************/
	Serializer object;

	address = object.serialize(&human);

	std::cout << "Serialized pointer:" << &address << std::endl;
	/************************ SERIALIZER ***************************/



	
	/************************* REVERSE **************************/
	Data *reserialized = object.deserialize(object.serialize(&human));
	Data *reserialized2 = object.deserialize(object.serialize(&human2));

	std::cout << "Reserialized structs:" << std::endl;
	std::cout << "\taddress human: " << reserialized << std::endl;
	std::cout << "\tname: " << reserialized->name << std::endl;
	std::cout << "\tage: " << reserialized->age << std::endl;

	std::cout << std::endl; 
	
	std::cout << "\taddress human2: " << &reserialized2 << std::endl;
	std::cout << "\tname: " << reserialized2->name << std::endl;
	std::cout << "\tage: " << reserialized2->age << std::endl;
	std::cout << std::endl; std::cout << std::endl;
	/************************* REVERSE **************************/

	return (0);

}