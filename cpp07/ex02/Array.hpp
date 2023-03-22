/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 01:14:07 by yogun             #+#    #+#             */
/*   Updated: 2023/03/22 21:08:22 by yogun            ###   ########.fr       */
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
			this->_num = 0;
			this->_arr = NULL;
			std::cout << "Default Constructor invoked" << std::endl;
			return ;
		}
		
		Array< T >( unsigned int n ) 					// Constructor	
		{
			this->_num = n;
			this->_arr = new T[n];
			std::cout << "Constructor invoked" << std::endl;
			return ;
		}
		
		Array< T >( const Array & other )			// Copy constructor
		{
			*this = other;
			return ;
		}
		
		~Array< T >( void )						// Destructor
		{
			if (this->_num > 0)
				delete[] this->_arr;
		};

		Array & operator=(const Array & other)			// Assignation operator
		{
			if (this == &other)
				return (*this);
			this->_num = other.size();
			
			// If the array is not empty, delete it.
			if (this->_num > 0)
				this->_arr = new T[this->_num];

			// Copy the array.
			for (unsigned int i = 0; i < this->_num; i++)
				this->_arr[i] = other._arr[i];
			return (*this);
		}

		T & operator[](unsigned int num)
		{
			if (num >= size())
				throw std::out_of_range("Out of the array's range!");
			return (this->_arr[num]);			// Return the element at index num.
		}

		unsigned int	size(void) const {
			return (this->_num);
		}

	// Those attributes are protected rather than private, so that they can be accessed by the derived classes. Remember! This is only and only a template.
	protected:
		unsigned int	_num;
		T*				_arr;
};

#endif