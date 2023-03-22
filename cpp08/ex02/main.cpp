/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 01:15:06 by yogun             #+#    #+#             */
/*   Updated: 2023/03/22 22:56:50 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main()
{
	// creation of a string stack
	MutantStack<std::string> mstack_string;
	mstack_string.push("One");
	mstack_string.push("Two");
	mstack_string.pop();
	mstack_string.push("Four");
	mstack_string.push("Five");

	// creation of a int stack
	MutantStack<int> mstack;
	mstack.push(1);		// addding 1
	mstack.push(2);	// adding 2
	mstack.pop();		// deleting 2
	mstack.push(4);		// adding 4
	mstack.push(5);	// adding 5

	std::cout << std::endl;

	// ******************************** start working with string stack ********************************
	MutantStack<std::string>::iterator s_it = mstack_string.begin();
	MutantStack<std::string>::iterator e_it = mstack_string.end();
	
	
	++s_it;
	--s_it;
	std::cout << "String Iterator: ";
	// print the stack
	while (s_it != e_it)
	{
		std::cout << *s_it << ", ";
		++s_it;
	}

	std::cout << std::endl << std::endl << "↓↓↓ String Stack Information ↓↓↓\nSize: " << mstack_string.size() << "\nEmpty: " << (mstack_string.empty() ? "true" : "false") << std::endl;
	mstack_string.pop();
	mstack_string.pop();
	mstack_string.pop();
	std::cout << std::endl << std::endl << "↓↓↓ String Stack Information ↓↓↓\nSize: " << mstack_string.size() << "\nEmpty: " << (mstack_string.empty() ? "true" : "false") << std::endl;
	// ******************************** end working with string stack ********************************

	std::cout << std::endl << "-------------------------------------------------------------------" << std::endl << std::endl;

	// ******************************** start working with int stack ********************************
	MutantStack<int>::iterator it_s = mstack.begin();
	MutantStack<int>::iterator it_e = mstack.end();

	++it_s;
	--it_s;

	std::cout << "Int Iterator: ";
	while (it_s != it_e)
	{
		std::cout << *it_s << "` ";
		++it_s;
	}

	// 
	std::cout << std::endl << std::endl << "******************************** Int Stack Information ********************************\nSize: " << mstack.size() << "\nEmpty: " << (mstack.empty() ? "true" : "false") << std::endl << std::endl;
	// ******************************** end working with int stack ********************************

	return 0;
}