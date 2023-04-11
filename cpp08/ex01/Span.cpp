/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 01:15:06 by yogun             #+#    #+#             */
/*   Updated: 2023/04/11 18:11:01 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Span.hpp"

// Default Constructor
Span::Span( void ) : _n(0)
{	
	//std::cout << "Default Constructor invoked" << std::endl;
	return ;
}

// Constructor
Span::Span( unsigned int n ) : _n(n)
{
	//std::cout << "Constructor invoked" << std::endl;
	this->_array.reserve(n);	// reserve() function is used to allocate memory for the vector. 
	return ;
}

// Copy Constructor
Span::Span( const Span & other )
{
	*this = other;
	return ;
}

// Destructor
Span::~Span( void )
{
	//std::cout << "Destructor invoked" << std::endl;
	return ;
}

// Assignation Operator
Span & Span::operator=(const Span & other) 
{
	if (this == &other)
		return (*this);
	this->_n = other._n;
	this->_array = other._array;
	return (*this);
}



// -------------------------  Member Functions  ------------------------- //

// Here in this function, we add a number to the vector.
void	Span::addNumber(int num)
{
	if (this->_array.size() >= this->_n)
		throw std::out_of_range("Not enough space!");

	// add the number to the end of the vector. Such as: [5, 7 , 8] -> [5, 7, 8, 9]
	this->_array.push_back(num);
}

// In this function, with the help of the insert function, we add a vector of numbers to the vector.
void	Span::addNumber(std::vector<int> vector)
{
	if (this->_n - this->_array.size() < vector.size())	// For instance we have space for 6 elements.Our vector is [5, 7, 9]. It has 3 members. So, 6-3=3. We can still add 3 members. If we try to append a vector more than that, we will get an error.
		throw std::out_of_range("Not enough space!");

	this->_array.insert( this->_array.end(), vector.begin(), vector.end() );// [2,5,7] + [8,4] = [2,5,7,8,4]
}

// Here we find the shortest span between two numbers in the vector. But how we do it?
// We sort the vector, and then we iterate through it, and compare the difference between two numbers.
// If the difference is smaller than the previous one, we save it in the variable res.
// At the end, we return the res variable.
int	Span::shortestSpan(void) 
{
	std::vector<int>::iterator	it1;
	std::vector<int>::iterator	it2;
	int							res;
	
	/******************* CHECK **************************/
	if (this->_array.size() == 0)
		throw std::length_error("List is empty!");
	else if (this->_array.size() == 1)
		throw std::length_error("Only one number has been found in the array!");
	/********************* CHECK ************************/

	std::sort(this->_array.begin(), this->_array.end());	// We sort the vector.
	it1 = this->_array.begin();					// We set the iterator1 to the beginning of the vector.
	it2 = it1 + 1;		// We set the iterator2 to the second element of the vector.

	// We iterate through the vector, and compare the difference between two numbers. 
	for (res = *it2 - *it1; it2 != this->_array.end(); it1++, it2++)
		// If the difference is smaller than the previous one, we save it in the variable res. 
		if (*it2 - *it1 < res)
			res = *it2 - *it1;
	return (res);
}

// Here we find the longest span between two numbers in the vector. But how we do it?
// We sort the vector, and then we return the difference between the first and the last element.
// And that's it.
int	Span::longestSpan(void)
{
	if (this->_array.size() == 0)
		throw std::length_error("No numbers was found!");
	else if (this->_array.size() == 1)
		throw std::length_error("Only one number is in array!");

	std::sort(this->_array.begin(), this->_array.end());
	return (this->_array.back() - this->_array.front());
}