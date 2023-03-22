/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 01:15:06 by yogun             #+#    #+#             */
/*   Updated: 2023/03/22 22:22:59 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{
	std::list<int> test;
	test.push_back(21);
	test.push_back(42);
	test.push_back(84);

	// Here what we do is we create an iterator to the end of the list
	// and we try to find the value 21 in the list. If we find it, we
	// assign the iterator to the value we found. If we don't find it,
	// we assign the iterator to the end of the list. If the iterator
	// is equal to the end of the list, we know we didn't find the value
	// in the list. If we did find the value, we print it out.
	std::list<int>::const_iterator	it = test.end();

	try		// try to find the value 21 in the list
	{
		it = ::easyfind(test, 21);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	// if the iterator is not equal to the end of the list, we found the value
	if (it != test.end())
		std::cout << *it << " found" << std::endl;

	// Here we restart the iterator and try to find the value 7 in the list.
	it = test.end();

	// We send 7 to the function, but 7 is not in the list, so we should
	// get an exception.
	try
	{
		it = ::easyfind(test, 7);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	// if the iterator is not equal to the end of the list, we found the value
	//But we didn't find the value, so the iterator is still at the end of the list
	if (it != test.end())
		std::cout << *it << " found" << std::endl;

	return 0;
}