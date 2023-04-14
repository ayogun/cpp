/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 01:14:07 by yogun             #+#    #+#             */
/*   Updated: 2023/04/14 15:06:01 by yogun            ###   ########.fr       */
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
/************************************************************************************************/
	PmergeMe(void);			// default constructor
	PmergeMe(const PmergeMe & origin);		// copy constructor
	PmergeMe & operator=(const PmergeMe & origin);		// Copy assignment operator
	~PmergeMe(void);		// Destructure
/************************************************************************************************/


	// ****************** Member functions *********************
	void	ft_sort(char **tab);

	double	sort_Vector();
	void 	mergeSort_Vector(std::vector<int>& arr, int left, int mid, int right);
	void 	insertionSort_Vector(std::vector<int>& arr, int left, int right);
	void 	mergeInsertion_Vector(std::vector<int>& arr, int left, int right);
	void	print_Vector();
	
	double	sort_List();
	void 	mergeSort_List(std::list<int>& arr, int left, int mid, int right);
	void 	insertionSort_List(std::list<int>& arr, int left, int right);
	void 	mergeInsertion_List(std::list<int>& arr, int left, int right);
	void	print_List();
	// ****************** Member functions *********************


private:
	std::vector<int> _vector;	// I used vector container because it is a dynamic array and it is easy to sort.
	std::list<int>	_list;
};

#endif