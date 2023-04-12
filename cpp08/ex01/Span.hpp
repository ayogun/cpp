/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 01:14:07 by yogun             #+#    #+#             */
/*   Updated: 2023/04/12 22:25:32 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <algorithm>

class	Span {
	public:
		Span(void);					// default constructor
		Span(unsigned int n);		// constructor
		Span(const Span & other); 	// copy constructor
		~Span(void);				// destructor
		Span & operator=(const Span & other);	// assignation operator

		/************************************************************/

		// member functions
		void		addNumber(int num);
		void		addNumber(std::vector<int> vector);	// here we 
		int			shortestSpan(void);
		int			longestSpan(void);

	private:
		unsigned int		_n;
		std::vector<int>	_array;

};

#endif