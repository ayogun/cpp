/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 01:15:06 by yogun             #+#    #+#             */
/*   Updated: 2023/04/11 18:09:40 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{
	// We create a list of integers and add some values to it. push_back() adds a new element at the end of the list, effectively increasing the container size by one.
	std::list<int> tmp;
	tmp.push_back(21);	
	tmp.push_back(42);
	tmp.push_back(84);

	// Here what we do is we create an iterator to the end of the list
	// and we try to find the value 21 in the list. If we find it, we
	// assign the iterator to the value we found. If we don't find it,
	// we assign the iterator to the end of the list. If the iterator
	// is equal to the end of the list, we know we didn't find the value
	// in the list. If we did find the value, we print it out.

	// We create an iterator to the end of the list
	std::list<int>::const_iterator	it = tmp.end();
	

	try		// try to find the value 21 in the list
	{
		it = ::easyfind(tmp, 84);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	// if the iterator is not equal to the end of the list, we found the value
	if (it != tmp.end())
		std::cout << *it << " has been found in the list!" << std::endl;

	// Here we restart the iterator and try to find the value 7 in the list.
	it = tmp.end();

	// We send 7 to the function, but 7 is not in the list, so we should
	// get an exception.
	try
	{
		it = ::easyfind(tmp, 7);
	}
	catch(const std::exception& e)
	{
		std::cerr << 7 << e.what() << std::endl;
	}

	// if the iterator is not equal to the end of the list, we found the value
	//But we didn't find the value, so the iterator is still at the end of the list
	if (it != tmp.end())
		std::cout << *it << " has been found in the list!" << std::endl;

	return 0;
}