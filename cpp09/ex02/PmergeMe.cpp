/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 01:14:07 by yogun             #+#    #+#             */
/*   Updated: 2023/04/14 02:02:24 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/************************************************************************************/
/************************************************************************************/
/************************************************************************************/
/************************************************************************************/
// Default constructor
PmergeMe::PmergeMe(void) 
{
	//std::cout << "Default constructor called" << std::endl;
	return ;
}

//	Copy constructor
PmergeMe::PmergeMe(const PmergeMe & origin)
{
	//std::cout << "Copy constructor called" << std::endl;
	*this = origin; 
}

// Copy assignment operator
PmergeMe & PmergeMe::operator=(const PmergeMe & origin)
{
	//std::cout << "Copy assignment operator called" << std::endl;
	this->_vector = origin._vector;
	this->_list = origin._list;
	return *this;
}

// destructor
PmergeMe::~PmergeMe(void) 
{
	//std::cout << "Destructor called" << std::endl;
	return ;
}

/************************************************************************************/
/************************************************************************************/
/************************************************************************************/
/************************************************************************************/




// ****************** Member functions *********************

// We are printing the vector members
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

// We are printing the list members
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



void PmergeMe::merge(std::vector<int>& arr, int left, int mid, int right) {
    int leftSize = mid - left + 1;
    int rightSize = right - mid;

    std::vector<int> leftArr(leftSize);
    std::vector<int> rightArr(rightSize);

    for (int i = 0; i < leftSize; ++i) {
        leftArr[i] = arr[left + i];
    }

    for (int j = 0; j < rightSize; ++j) {
        rightArr[j] = arr[mid + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = left;
    while (i < leftSize && j < rightSize) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k++] = leftArr[i++];
        } else {
            arr[k++] = rightArr[j++];
        }
    }

    while (i < leftSize) {
        arr[k++] = leftArr[i++];
    }

    while (j < rightSize) {
        arr[k++] = rightArr[j++];
    }
}

void PmergeMe::insertionSort(std::vector<int>& arr, int left, int right) {
    for (int i = left + 1; i <= right; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

void PmergeMe::mergeInsertionSort(std::vector<int>& arr, int left, int right) {
    if (left < right) {
        if (right - left <= 4) { // Use insertion sort for small subarrays
            insertionSort(arr, left, right);
        } else {
            int mid = left + (right - left) / 2;
            mergeInsertionSort(arr, left, mid);
            mergeInsertionSort(arr, mid + 1, right);
            merge(arr, left, mid, right);
        }
    }
}



void PmergeMe::insertionSortList(std::list<int>& A, int p, int q) {
    for (int i = p; i < q; i++) {
        // Get the value at index (i+1)
        int tempVal = *std::next(A.begin(), i + 1);
        int j = i + 1;
        // Shift elements to the right to make space for the current element
        while (j > p && *std::next(A.begin(), j - 1) > tempVal) {
            *std::next(A.begin(), j) = *std::next(A.begin(), j - 1);
            j--;
        }
        // Insert the current element at its correct position
        *std::next(A.begin(), j) = tempVal;
    }
}

// Merge two sorted sublists
void PmergeMe::mergeList(std::list<int>& A, int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;
    std::list<int> LA, RA;
    // Copy elements from the left sublist to LA
    for (int i = 0; i < n1; i++) {
        LA.push_back(*std::next(A.begin(), p + i));
    }
    // Copy elements from the right sublist to RA
    for (int i = 0; i < n2; i++) {
        RA.push_back(*std::next(A.begin(), q + 1 + i));
    }
    int RIDX = 0;
    int LIDX = 0;
    // Merge LA and RA into A
    for (int i = p; i <= r; i++) {
        if (RIDX == n2) {
            *std::next(A.begin(), i) = LA.front();
            LA.pop_front();
            LIDX++;
        } else if (LIDX == n1) {
            *std::next(A.begin(), i) = RA.front();
            RA.pop_front();
            RIDX++;
        } else if (RA.front() > LA.front()) {
            *std::next(A.begin(), i) = LA.front();
            LA.pop_front();
            LIDX++;
        } else {
            *std::next(A.begin(), i) = RA.front();
            RA.pop_front();
            RIDX++;
        }
    }
}

// Recursive function to merge and sort the list
void PmergeMe::mergeInsertList(std::list<int>& A, int p, int r) {
    if (r - p > 5) {
        int q = (p + r) / 2;
        mergeInsertList(A, p, q);
        mergeInsertList(A, q + 1, r);
        mergeList(A, p, q, r);
    } else { // If list size is smaller than or equal to K, use insertion sort
        insertionSortList(A, p, r);
    }
}







double PmergeMe::sortVector() 
{
	std::clock_t start, end;		// std::clock_t is a type that represents the clock ticks
	double res;

	start = clock();			// I start the clock
	mergeInsertionSort(_vector, 0, _vector.size() - 1);	// I sort the vector
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
	mergeInsertList(_list, 0, _list.size() - 1);
	end = clock();
	res = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000;
	return res;
}

// Sorting function
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
