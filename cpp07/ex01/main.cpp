/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 01:15:06 by yogun             #+#    #+#             */
/*   Updated: 2023/03/22 21:00:09 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void ft_toupper(char &arr)
{
	arr = std::toupper(static_cast<unsigned char>(arr));
}

int main()
{
	char a[] = {'a', 'b', 'c'};

	std::cout << "Original:" << std::endl;
	std::cout << "\ta[0]: " << a[0] << std::endl;
	std::cout << "\ta[1]: " << a[1] << std::endl;
	std::cout << "\ta[2]: " << a[2] << std::endl;
	std::cout << std::endl;

	::iter(a, sizeof(a) / sizeof(char), ft_toupper);

	std::cout << "Changed:" << std::endl;
	std::cout << "\ta[0]: " << a[0] << std::endl;
	std::cout << "\ta[1]: " << a[1] << std::endl;
	std::cout << "\ta[2]: " << a[2] <<std::endl; 
	std::cout << std::endl;

	return 0;
}