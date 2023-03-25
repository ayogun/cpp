/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 01:14:07 by yogun             #+#    #+#             */
/*   Updated: 2023/03/26 00:43:25 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_H
# define PMERGEME_H

#include <vector>
#include <list>
#include <iostream>
#include <sstream>
#include <ctime>
#include <iomanip>

class PmergeMe
{
public:
	PmergeMe(void);			// default constructor
	PmergeMe(const PmergeMe & origin);		// copy constructor
	PmergeMe & operator=(const PmergeMe & origin);		// Copy assignment operator
	~PmergeMe(void);		// Destructure

	// ****************** Member functions *********************
	void	ft_sort(char **tab);
	void	vectorPrint();
	void	listPrint();
	double	sortVector();
	double	sortList();

private:
	std::vector<int> _vector;
	std::list<int>	_list;
};

#endif