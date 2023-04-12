/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 01:14:07 by yogun             #+#    #+#             */
/*   Updated: 2023/04/12 12:58:32 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>

/**************************** MAX *******************************/
// Here we define, T as a template. 
// Because we don't know what type we will use. 
// Maybe int, maybe float. God knows...
template< typename T > 

const T	&max(const T &x ,const T &y) // more const, more better. Why? Because we don't want to change the value of x and y. So why we bother our memory without using const?
{
	return (x >= y ? x : y);
}
/***************************** MAX **************************/






/****************************** MIN ********************************/
 // defines, U is a template
template< typename U >

const U	&min(const U &x ,const U &y) // more const, more better
{
	return (x <= y ? x : y);
}
/****************************** MIN ********************************/






/****************************** SWAP ********************************/
template< typename V > // defines, V is a template

void swap(V &x, V &y)
{
	V tmp = x;
	x = y;
	y = tmp;
}
/****************************** SWAP ********************************/
#endif