/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 01:15:06 by yogun             #+#    #+#             */
/*   Updated: 2023/04/12 22:42:47 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main() {

		std::cout << "______________________ TEST - 1 _____________________________" << std::endl << std::endl;

	{
  		Span sp = Span(5);
  		sp.addNumber(6);
  		sp.addNumber(3);
  		sp.addNumber(17);
  		sp.addNumber(9);
  		sp.addNumber(11);
  		std::cout << sp.shortestSpan() << std::endl;
  		std::cout << sp.longestSpan() << std::endl;
	}

		std::cout << "______________________ TEST - 2 _____________________________" << std::endl << std::endl;


	{
		Span sp = Span(20000);
		for (int i = 0; i < 20000; i++)
			sp.addNumber(i);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
		
	}

			std::cout << "______________________TEST - 3_____________________________" << std::endl << std::endl;

	{
		Span sp = Span(10);
		std::vector<int> sp2(5, 10);
		
		sp.addNumber(1);
  		sp.addNumber(2);
  		sp.addNumber(3);
  		sp.addNumber(4);
  		sp.addNumber(5);

		sp.addNumber(sp2);

		std::cout << sp.shortestSpan() << std::endl;
  		std::cout << sp.longestSpan() << std::endl;
		
	}

			std::cout << "______________________TEST - 4_____________________________" << std::endl << std::endl;

	{
		Span sp = Span(5);
		std::vector<int> sp2(5, 10);
		
		sp.addNumber(1);
  		sp.addNumber(2);
  		sp.addNumber(3);
  		sp.addNumber(4);
  		sp.addNumber(5);

		sp.addNumber(sp2);

		std::cout << sp.shortestSpan() << std::endl;
  		std::cout << sp.longestSpan() << std::endl;
		
	}
	
	return 0; 
}