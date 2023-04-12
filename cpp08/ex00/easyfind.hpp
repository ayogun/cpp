/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 01:14:07 by yogun             #+#    #+#             */
/*   Updated: 2023/04/12 17:51:44 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <algorithm>
# include <list>

// Template
template< typename T>

typename T::iterator easyfind(T &input, int i)
{
	typename T::iterator	iter;	// iterator to the container
	
	// find() returns an iterator to the first element in the range [first,last) that compares equal to val. If no such element is found, the function returns last.
	iter = find(input.begin(), input.end(), i);
	
	// if the iterator is at the end of the container, the value was not found and an exception is thrown
	if (iter == input.end())
	{
		throw std::out_of_range(" hasn't been found in the list!");
	}
	return (iter);
}

#endif