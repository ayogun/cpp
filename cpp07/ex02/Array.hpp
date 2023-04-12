/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 01:14:07 by yogun             #+#    #+#             */
/*   Updated: 2023/04/12 17:16:32 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

// This is a template class, so it can be used with any type.
template<typename T>

class	Array {
	public:
		Array< T >( void ) 									// Default constructor
		{
			this->_size = 0;
			this->_arr = NULL;
			//std::cout << "Default Constructor invoked" << std::endl;
			return ;
		}
		
		Array< T >( unsigned int n ) 					// Constructor. It is unsigned int because it is the size of the array and size can't be negative value.
		{
			this->_size = n;
			this->_arr = new T[n];	// We must use new operator to create an array as pdf dictates. Because preventive allocation is forbidden. Preventive allocation is allocating memory for an array before we know how many elements we need.
			//std::cout << "Constructor invoked" << std::endl;
			return ;
		}
		
		Array< T >( const Array & other )			// Copy constructor
		{
			*this = other;
			return ;
		}
		
		~Array< T >( void )						// Destructor
		{
			if (this->_size > 0)
				delete[] this->_arr;
		};

		Array & operator=(const Array & other)			// Assignation operator
		{
			if (this == &other)			// If the object is assigned to itself, return the object.
				return (*this);
			this->_size = other.getSize();
			
			// If the array size is valid, create a new array.
			if (this->_size > 0)
				this->_arr = new T[this->_size];

			// Copy the array. One by one. Each element we copy it to the new array.
			for (unsigned int i = 0; i < this->_size; i++)
				this->_arr[i] = other._arr[i];
			return (*this);
		}
	
		T & operator[](unsigned int index)		// Operator overloading. Its' used to access the elements of the array.
		{
			if (index >= getSize())
				throw std::out_of_range("Out of the range!");
			return (this->_arr[index]);			// Return the element at index.
		}

		unsigned int	getSize(void) const {
			return (this->_size);
		}

	private:
		unsigned int	_size;
		T*				_arr;
};

#endif