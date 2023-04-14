/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 01:14:07 by yogun             #+#    #+#             */
/*   Updated: 2023/04/14 01:57:22 by yogun            ###   ########.fr       */
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
	void	vectorPrint();
	void	listPrint();
	double	sortVector();
	double	sortList();
	void merge(std::vector<int>& arr, int left, int mid, int right);
	void insertionSort(std::vector<int>& arr, int left, int right);
	void mergeInsertionSort(std::vector<int>& arr, int left, int right);

	void insertionSortList(std::list<int>& A, int p, int q);
	void mergeList(std::list<int>& A, int p, int q, int r);
	void mergeInsertList(std::list<int>& A, int p, int r);


	// ****************** Member functions *********************


private:
	std::vector<int> _vector;	// I used vector container because it is a dynamic array and it is easy to sort.
	std::list<int>	_list;
};

#endif