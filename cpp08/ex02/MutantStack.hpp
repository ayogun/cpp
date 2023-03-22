/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 01:14:07 by yogun             #+#    #+#             */
/*   Updated: 2023/03/22 22:55:53 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stack>

template <class T>

class MutantStack : public std::stack<T>
{
public:
/************************* TYPEDEF **********************************/
	typedef std::stack<T> stack;						
	typedef typename stack::container_type container;	
	typedef typename container::iterator iterator; 		
/************************* TYPEDEF **********************************/

	// Default Constructor
	MutantStack(void) : stack()
	{
		std::cout << "Default Constructor invoked" << std::endl;
		return ;
	}

	MutantStack(const stack &src) : stack(src)
	{
		std::cout << "Copy Constructor invoked" << std::endl;
		return ;
	}

	// Deconstuctor
	~MutantStack(void)
	{
		std::cout << "Deconstuctor invoked" << std::endl;
		return ;
	}

	// Overloaded opperators
	stack &operator=(const stack &src)
	{
		if (*this != src)
			*this = src;
		return (*this);
	}

	// Start iterator
	iterator begin(void)
	{
		return (stack::c.begin());
	}

	// finish iterator
	iterator end(void)
	{
		return (stack::c.end());
	}
};