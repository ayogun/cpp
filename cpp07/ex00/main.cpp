/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 01:15:06 by yogun             #+#    #+#             */
/*   Updated: 2023/04/11 16:36:48 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

int main( void ) {
	int a = 2;
	int b = 3;
	
	/********* SWAP ********/
	swap( a, b );
	/********* SWAP ********/
	
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << max( a, b ) << std::endl;
	std::string c = "string1";
	std::string d = "string2";

	std::cout << std::endl;
	std::cout << "c = " << c << ", d = " << d << std::endl;

	/********* SWAP ********/
	::swap(c, d);	std::cout << "c and d are swapped." << std::endl;
	/********* SWAP ********/

	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << std::endl;
	
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;	// ::min is the same as min. But we can use ::min to be sure that we are using the global function. Without this we will get an error. 
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	
	return 0;
	}