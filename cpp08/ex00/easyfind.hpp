/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 01:14:07 by yogun             #+#    #+#             */
/*   Updated: 2023/03/22 22:17:32 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <algorithm>
# include <list>

template< typename T>
typename T::iterator easyfind(T &in, int i)
{
	typename T::iterator	it;
	
	// find() returns an iterator to the first element in the range [first,last) that compares equal to val. If no such element is found, the function returns last.
	it = find(in.begin(), in.end(), i);
	
	// if the iterator is at the end of the container, the value was not found and an exception is thrown
	if (it == in.end())
	{
		throw std::out_of_range("Not found!");
	}
	return (it);
}

#endif