/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 01:14:07 by yogun             #+#    #+#             */
/*   Updated: 2023/03/22 22:40:25 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <algorithm>

class	Span {
	public:
		Span(void);
		Span(unsigned int n);
		Span(const Span & other);
		~Span(void);

		Span & operator=(const Span & other);

		void		addNumber(int num);
		void		addNumber(std::vector<int> vector);
		int			shortestSpan(void);
		int			longestSpan(void);

	protected:
		unsigned int		_n;
		std::vector<int>	_array;

};

#endif