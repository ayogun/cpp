/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 01:14:07 by yogun             #+#    #+#             */
/*   Updated: 2023/04/14 02:24:01 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stack>

template <class T>

class MutantStack : public std::stack<T> // MutantStack is a child of std::stack
{
public:

/*
	-> stack: This is an alias for std::stack<T>, where T is a template parameter. std::stack is a container adapter class in the C++ Standard Library that provides a LIFO (Last-In, First-Out) stack data structure. The T is a placeholder for the type of elements that will be stored in the stack, and it will be determined when the stack is used in actual code.
	-> container: This is an alias for typename stack::container_type. stack::container_type is a nested type within std::stack that represents the underlying container used to implement the stack. By default, std::stack uses std::deque as its underlying container, but you can specify a different container type when you instantiate a std::stack object. This alias allows you to access the underlying container type through container for any stack instance.
	-> iterator: This is an alias for typename container::iterator. container::iterator is a nested type within the underlying container type, and it represents an iterator that can be used to iterate over the elements in the container. This alias allows you to access the iterator type for the underlying container through iterator for any stack instance.
*/
/************************* TYPEDEF **********************************/
	typedef std::stack<T> stack;							
	typedef typename stack::container_type container;	
	typedef typename container::iterator iterator; 		// typedef is a keyword that allows you to define an alias for a type. Typename is a keyword that allows you to refer to a type that is nested within another type.
/************************* TYPEDEF **********************************/

	// Default Constructor
	MutantStack(void) : stack()
	{
		//std::cout << "Default Constructor invoked" << std::endl;
		return ;
	}

	MutantStack(const stack &src) : stack(src)
	{
		//std::cout << "Copy Constructor invoked" << std::endl;
		return ;
	}

	// Deconstuctor
	~MutantStack(void)
	{
		//std::cout << "Deconstuctor invoked" << std::endl;
		return ;
	}

	// Overloaded opperators
	stack &operator=(const stack &src)
	{
		if (*this != src)
			*this = src;
		return (*this);
	}

	
/*******************************************************************************************************/
/*******************************************************************************************************/

	// Start iterator
	iterator begin(void)
	{
		return (stack::c.begin()); // Here the c is a container of the stack class. And the begin() function is a member function of the container class. 
	}

	// finish iterator
	iterator end(void)
	{
		return (stack::c.end());
	}
};