/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 01:14:07 by yogun             #+#    #+#             */
/*   Updated: 2023/04/11 16:43:20 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

// We define a template T for the function iter. This template will be used for the array and the function.
template< typename T >

/*
	The template function iter takes an array and a function as arguments, 
	and applies that function to each element of the array.
	*foo is a "pointer to a function" that takes a reference to a T and returns nothing.
	len parameter is the length of the array.
	The arr parameter is a pointer to the first element of the array.
 */
// This is a template function. It will be used for any type of array.
void	iter(T *arr, int len, void (*foo)(T &))
{
	if (arr == NULL || foo == NULL)
		return ;
	for (int i = 0; i < len; i++)
		foo(arr[i]);
}

#endif