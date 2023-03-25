/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 01:14:07 by yogun             #+#    #+#             */
/*   Updated: 2023/03/26 00:52:30 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// Default constructor
PmergeMe::PmergeMe(void) 
{
	std::cout << "Default constructor called" << std::endl;
	return ;
}

//	Copy constructor
PmergeMe::PmergeMe(const PmergeMe & origin)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = origin; 
}

// Copy assignment operator
PmergeMe & PmergeMe::operator=(const PmergeMe & origin)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_vector = origin._vector;
	this->_list = origin._list;
	return *this;
}

// destructor
PmergeMe::~PmergeMe(void) 
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

/************************************************************************************/
/************************************************************************************/
/************************************************************************************/
/************************************************************************************/


// ****************** Member functions *********************

void	PmergeMe::vectorPrint()
{
	int i = 0;
	// From the beginning to the end of the vector we are iterating through the vector with an iterator it
	for (std::vector<int>::iterator it = _vector.begin(); it < _vector.end(); it++)
	{
		// If we have more than 5 elements we print [...] and break the loop
		if(++i > 6)
		{
			std::cout << " [...]";
			break;
		}
		std::cout << " " << *it;
	}
	std::cout << std::endl;
}

void	PmergeMe::listPrint()
{
	int i = 0;
	// From the beginning to the end of the list we are iterating through the list with an iterator it
	for (std::list<int>::iterator it = _list.begin(); it != _list.end(); it++)
	{
		// If we have more than 5 elements we print [...] and break the loop
		if(++i > 6)
		{
			std::cout << " [...]";
			break;
		}
		std::cout << " " << *it;
	}
	std::cout << std::endl;
}

// we check if the input is a number and if it is not negative or too big
void	isNumOk(char *argv)
{
	std::string s = argv;
	if (s[0] == '-')
		throw "Error: negative number is not allowed.";
	if (!s.empty() && s.find_first_not_of("0123456789") != std::string::npos)
		throw "Error: input is not a number.";
	if (s.size() > 10 || (s.size() == 10 && s > "2147483647"))
		throw "Error: input is too big.";
	if (s.empty())
		throw "Error: input is empty.";
}

void	PmergeMe::ft_sort(char *argv[]) //int max
{
	double vectorTime, listTime;
	int i = 1;
	int num = 0;

	while (argv[i]) // while argument is not null
	{
		isNumOk(argv[i]);
		std::istringstream(argv[i++]) >> num;  // std::istringstream is used to convert a string to a number and we increment i
		_vector.push_back(num);				// we push the number in the vector
		_list.push_back(num);				// we push the number in the list
	}

	
	std::cout << "Before :";
	vectorPrint(); // Here I print vector
	vectorTime = sortVector();
	listTime = sortList();
	std::cout << "After :";
	listPrint();	// Although here I print list. There is no reason for that, I just wanted to practice the difference between the two containers.
	std::cout << std::fixed << std::setprecision(3); // I set the precision to 3
	std::cout << "Time to process a range of "<< _vector.size() <<  " elements with std::vector : " << vectorTime << " ms" << std::endl;	// I print the time it took to sort the vector
	std::cout << "Time to process a range of "<< _list.size() <<  " elements with std::list : " << listTime << " ms" << std::endl; 		// I print the time it took to sort the list 
}

// I use the bubble sort algorithm to sort the vector
double PmergeMe::sortVector() 
{
	std::clock_t start, end;		// std::clock_t is a type that represents the clock ticks
	int	k, tmp;
	double res;

	start = clock();			// I start the clock
	k = _vector.size();			// I get the size of the vector

	// I use two for loops to iterate through the vector as the bubble sort algorithm requires
	for (int x = 0; x < k - 1; x++) 	
	{
		for (int y = 0; y < k - x - 1; y++) 
		{
			// If the current element is bigger than the next one, then we swap.
			if (_vector[y] > _vector[y + 1]) 
			{
				tmp = _vector[y];
				_vector[y] = _vector[y + 1];
				_vector[y + 1] = tmp;
			}
		}
	}
	end = clock();															// I stop the clock
	res = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000;			// I calculate the time it took to sort the vector. I multiply by 1000 to get the time in milliseconds. Result ia a clock_t so I cast it to double. CLOCK_PER_SEC is a constant that represents the number of clock ticks per second.
	return res;
}

// I use the insertion sort algorithm to sort the list
double PmergeMe::sortList() 
{
	std::clock_t start, end;
	double res;

	start = clock();
	// From begining to the end of the list we are iterating through the list with an iterator it
	for (std::list<int>::iterator it = ++_list.begin(); it != _list.end(); ++it)
	{
		int tmp = *it;
		std::list<int>::iterator i = it;			// I create a new iterator i and assign it to it
		while (i != _list.begin() && *(--i) > tmp)	// I iterate through the list until i is not equal to the beginning of the list and the element before i is bigger than tmp
		{
			*(++i) = *i;					// I assign the element before i to i
			i--;							// I decrement i
		}
		*(++i) = tmp;				// I assign tmp to i	
		i--;					// I decrement i
	}
	end = clock();
	res = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000;
	return res;
}