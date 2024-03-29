/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 01:14:07 by yogun             #+#    #+#             */
/*   Updated: 2023/04/12 16:37:21 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

// We define a template T for the function iter. This template will be used for the array and the function.
template< typename T >

/**********************************************************************************************************
	The template function iter takes an array and a function as arguments, 								  *
	and applies that function to each element of the array. 											  *
	
		> *foo is a "pointer to a function" that takes a reference to a T and returns nothing.				  *
		> len parameter is the length of the array.														  *
		> The arr parameter is a pointer to the first element of the array.					 			   *
 ***********************************************************************************************************/
// This is a template function.
void	iter(T *arr, int len, void (*foo)(T &))
{
	// We check if the array is empty or the function is empty.
	if (arr == NULL || foo == NULL)
	{
		std::cout << "Error: Array or function is empty." << std::endl;
		return ;
	}
	for (int i = 0; i < len; i++)
		foo(arr[i]);
}

#endif