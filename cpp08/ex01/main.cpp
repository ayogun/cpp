/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 01:15:06 by yogun             #+#    #+#             */
/*   Updated: 2023/03/22 22:27:17 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main() {
  	Span sp = Span(5);
  	sp.addNumber(6);
  	sp.addNumber(3);
  	sp.addNumber(17);
  	sp.addNumber(9);
  	sp.addNumber(11);
  	std::cout << sp.shortestSpan() << std::endl;
  	std::cout << sp.longestSpan() << std::endl;

	return 0; 
}