/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 01:14:07 by yogun             #+#    #+#             */
/*   Updated: 2023/04/14 16:41:44 by yogun            ###   ########.fr       */
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




// ~ https://iq.opengenus.org/merge-insertion-sort/



// *********************** VECTOR FUNCTIONS ***********************

// We are printing the vector members
void	PmergeMe::print_Vector()
{
	int i = 0;
	// From the beginning to the end of the vector we are iterating through the vector with an iterator it
	for (std::vector<int>::iterator it = _vector.begin(); it < _vector.end(); it++)
	{
		// If we have more than 5 elements we print [...] and break the loop
		if(++i > 5)
		{
			std::cout << " [...]";
			break;
		}
		std::cout << " " << *it;
	}
	std::cout << std::endl;
}

// We are sorting the vector with merge sort
void PmergeMe::mergeSort_Vector(std::vector<int>& arr, int left, int mid, int right)
{
    // Take array and split it into two subarrays as leftArr and rightArr.
    int leftSize = mid - left + 1;
    int rightSize = right - mid;

    // Created them as dynamic arrays(vector)
    std::vector<int> leftArr(leftSize);
    std::vector<int> rightArr(rightSize);

    // Copy data to temp arrays leftArr[] from arr[]
    for (int i = 0; i < leftSize; ++i)
    {
        leftArr[i] = arr[left + i];
    }

    // Copy data to temp arrays rightArr[] from arr[]
    for (int j = 0; j < rightSize; ++j)
    {
        rightArr[j] = arr[mid + 1 + j];
    }

    int i = 0;
    int j = 0;
    int q = left;
    // Loop through both arrays and copy the smallest element to the original array
    while (i < leftSize && j < rightSize)
    {
        if (leftArr[i] <= rightArr[j])
        {
            arr[q++] = leftArr[i++];
        }
        else if (leftArr[i] > rightArr[j])
        {
            arr[q++] = rightArr[j++];
        }
    }

    // Copy the remaining elements of leftArr[], if there are any. It is for the case when the left array has more element than the right array.
    while (i < leftSize)
    {
        arr[q++] = leftArr[i++];
    }

    // Copy the remaining elements of rightArr[], if there are any. It is for the case when the right array has more element than the left array.
    while (j < rightSize)
    {
        arr[q++] = rightArr[j++];
    }
}

// We are sorting the vector with insertion sort
void PmergeMe::insertionSort_Vector(std::vector<int>& arr, int left, int right)
{
    // Loop from the second element of the array until the last element
    for (int i = left + 1; i <= right; ++i)
    {
        int key = arr[i];   // Store the current element as key
        int j = i - 1;      // Store the index of the previous element
        // Loop from the current element to the left of the array
        while (j >= left && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

// We are sorting the vector with merge sort and insertion sort
void PmergeMe::mergeInsertion_Vector(std::vector<int>& arr, int left, int right)
{
    if (left < right)   // If the array has more than one element
    {
        if (right - left <= 5)
        { 
            // Use insertion sort for small subarrays
            insertionSort_Vector(arr, left, right);
        } 
        else if (right - left > 5)
        {
            int mid = left + (right - left) / 2;
            mergeInsertion_Vector(arr, left, mid);
            mergeInsertion_Vector(arr, mid + 1, right);
            mergeSort_Vector(arr, left, mid, right);
        }
    }
}

// We are sorting the vector with merge sort and insertion sort and we are returning the time it took to sort the vector
double PmergeMe::sort_Vector() 
{
	std::clock_t start, end;		// std::clock_t is a type that represents the clock ticks
	double res;

	start = clock();			// I start the clock
	mergeInsertion_Vector(_vector, 0, _vector.size() - 1);	// I sort the vector
	end = clock();															// I stop the clock
	res = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000;			// I calculate the time it took to sort the vector. I multiply by 1000 to get the time in milliseconds. Result ia a clock_t so I cast it to double. CLOCK_PER_SEC is a constant that represents the number of clock ticks per second.
	return res;
}

// *********************** VECTOR FUNCTIONS ***********************




// ~




// *********************** LIST FUNCTIONS ***********************

// We are printing the list members
void	PmergeMe::print_List()
{
	int i = 0;
	// From the beginning to the end of the list we are iterating through the list with an iterator it
	for (std::list<int>::iterator it = _list.begin(); it != _list.end(); it++)
	{
		// If we have more than 5 elements we print [...] and break the loop
		if(++i > 5)
		{
			std::cout << " [...]";
			break;
		}
		std::cout << " " << *it;
	}
	std::cout << std::endl;
}

// We are sorting the list with merge sort
void PmergeMe::insertionSort_List(std::list<int>& arr, int left, int right)
{
    // Iterate through the list from left to right
    for (int i = left; i < right; i++)
    {
        int j = i + 1;
        int tmp = *std::next(arr.begin(), j); // *std::next(arr.begin(), i + 1) is the same as arr[i + 1]. The next function returns an iterator to the element at the specified position. so it returns the value of the element at position i + 1
       
        // Loop thorogh from right to left if the current element is smaller than the previous one. Then we need to swap them.
        while (j > left && *std::next(arr.begin(), j - 1) > tmp)
        {
            // Swap the current element with the previous one. [1,2,5,3,4] -> [1,2,5,5,4] 
            *std::next(arr.begin(), j) = *std::next(arr.begin(), j - 1);
            j--;
        }
        // We swapped and now we have two big values in the arraay. We put the tmp value which is small value in the right place. [1,2,5,5,4] -> [1,2,3,5,4]
        *std::next(arr.begin(), j) = tmp;
    }
}

// Merge two sorted sublists
void PmergeMe::mergeSort_List(std::list<int>& arr, int left, int mid, int right)
{                                                                       //  [1,2,3,4,5,6]  
    int num1 = mid - left + 1;  // Number of elements in the left sublist   [1,2,3]
    int num2 = right - mid;     // Number of elements in the right sublist  [4,5,6]
    std::list<int> leftArr, rightArr;      // Left and right sublists
    
    // Copy elements from the big list to small left sublist. From left to mid. [1,2,3]
    for (int i = 0; i < num1; i++)
    {
        leftArr.push_back(*std::next(arr.begin(), left + i));
    }
    
    // Copy elements from the big list to small right sublist. From mid + 1 to right. [4,5,6]
    for (int i = 0; i < num2; i++)
    {
        rightArr.push_back(*std::next(arr.begin(), mid + 1 + i));
    }
    
    
    int RIDX = 0;
    int LIDX = 0;
    // Merge LEFT ARRAY and RIGHT ARRAY into one chunk ARRAY
    for (int i = left; i <= right; i++)
    {
        if (RIDX == num2)  // If we reached the end of the right array
        {
            *std::next(arr.begin(), i) = leftArr.front(); // Assign the first element of the left array to the current position of the big array
            leftArr.pop_front(); // Then we remove the first element of the left array
            LIDX++;
        }
        else if (LIDX == num1) // If we reached the end of the left array
        {
            *std::next(arr.begin(), i) = rightArr.front();  // Assign the first element of the right array to the current position of the big array
            rightArr.pop_front(); // Then we remove the first element of the right array
            RIDX++;
        } 
        else if (rightArr.front() > leftArr.front()) // If the first element of the right array is bigger than the first element of the left array
        {
            *std::next(arr.begin(), i) = leftArr.front(); // Assign the first element of the left array to the current position of the big array
            leftArr.pop_front();    // Then we remove the first element of the left array
            LIDX++;
        } 
        else // If the first element of the right array is smaller than the first element of the left array
        {
            *std::next(arr.begin(), i) = rightArr.front(); // Assign the first element of the right array to the current position of the big array
            rightArr.pop_front();   // Then we remove the first element of the right array
            RIDX++;
        }
    }
}

// Recursive function to merge and sort the list. 
void PmergeMe::mergeInsertion_List(std::list<int>& arr, int left, int right)
{
    if (right - left > 5) // If the size is greater than 5, we don't do recursion. The reason we use 5 is,
    {
        int mid = (left + right) / 2;
        mergeInsertion_List(arr, left, mid);
        mergeInsertion_List(arr, mid + 1, right);
        mergeSort_List(arr, left, mid, right);
    } 
    else
    {
        // Sort lists smaller than 5 elements
        insertionSort_List(arr, left, right);
    }
}

// I use the insertion sort algorithm to sort the list
double PmergeMe::sort_List() 
{
	std::clock_t start, end;
	double res;

	start = clock();
	mergeInsertion_List(_list, 0, _list.size() - 1);
	end = clock();
	res = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000; 
	return res;
}

// *********************** LIST FUNCTIONS ***********************




// ~




// ************************** PRIMARY FUNCTIONS ************************************

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


// Sorting function
void	PmergeMe::ft_sort(char *argv[])
{   
    //*** DECLARE VARAIBLES ***//
	double vectorTime, listTime;
	int i = 1;
	int num = 0;
    //*** DECLARE VARAIBLES ***//
    
    
    // One by one convert each argument to number and push it in the vector and the list
	while (argv[i]) 
	{
		isNumOk(argv[i]);       // Input validation.
		std::istringstream(argv[i]) >> num;  // std::istringstream is used to convert a string to a number and we increment i
		_vector.push_back(num);				// we push the number in the vector
		_list.push_back(num);				// we push the number in the list
        i++;
	}

    // Console print messages and also the sorting functions are called here
    {
	    std::cout << "Before :";
	    print_Vector(); // Here I print vector
	    vectorTime = sort_Vector();
	    listTime = sort_List();
	    std::cout << "After :";
	    print_List(); // Here I print list
	    std::cout << std::fixed << std::setprecision(3); // I set the precision to 3
	    std::cout << "Time to process a range of "<< _vector.size() <<  " elements with std::vector : " << vectorTime << " ms" << std::endl;	// I print the time it took to sort the vector
	    std::cout << "Time to process a range of "<< _list.size() <<  " elements with std::list : " << listTime << " ms" << std::endl; 		// I print the time it took to sort the list 
    }
}

// **************************** PRIAMRY FUNCTIONS ************************************