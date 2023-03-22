/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 01:14:07 by yogun             #+#    #+#             */
/*   Updated: 2023/03/22 20:56:51 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template< typename T >

/*
	The template function iter takes an array and a function as arguments, and applies that function to each element of the array.
	*foo is a pointer to a function that takes a reference to a T and returns nothing.
	len parameter is the length of the array.
	The arr parameter is a pointer to the first element of the array.
 */
void	iter(T *arr, size_t len, void (*foo)(T &))
{
	if (arr == NULL || foo == NULL)
		return ;
	for (size_t i = 0; i < len; i++)
		foo(arr[i]);
}

#endif