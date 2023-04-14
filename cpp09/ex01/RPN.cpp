/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 01:14:07 by yogun             #+#    #+#             */
/*   Updated: 2023/04/13 23:58:18 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

/******************************** ORTHODOX CANONICAL *****************************************************/
// Default constructor
RPN::RPN(void)
{
	//std::cout << "Default constructor called" << std::endl;
	return ;
}

// Copy constructor
RPN::RPN(RPN const &src)
{
	*this = src;
	//std::cout << "Copy constructor called" << std::endl;
	return ;
}

// destructor
RPN::~RPN(void)
{
	//std::cout << "Destructor called" << std::endl;
	return ;
}

// Copy assignment operator
RPN	&RPN::operator=(RPN const &rpn)
{
	//std::cout << "Copy assignment operator called\n";
	this->_numbers = rpn._numbers;
	return (*this);
}
/******************************** ORTHODOX CANONICAL *****************************************************/




// ****************** Helper functions *********************
static int isCharValid(char c)
{
	if ( c == 42 || c == 43 || c == 45 || c == 47 || (48 <= c && c < 58) )
		return (1);
	return (0);
}

static void printError(std::string str)
{
	std::cout << "Error: " << str << std::endl;
	std::exit(1);
}





/*************************** MATH FUNCTIONS *********************************************/
/*
				pop() = removes the top element from the stack, effectively reducing its size by one.
				empty() = if stack is empty, returns true, otherwise returns false.
				top() = returns a reference to the top element in the stack.
				push() = adds a new element at the top of the stack, above its current top element.
*/
void RPN::ft_multiply(int *i, float *old_top, float *result)
{
	(*i)++;
	_numbers.pop();
	if ( _numbers.empty() )
		printError("Stack is empty");
	*result = _numbers.top() * *old_top;
	_numbers.pop();
	_numbers.push(*result);
}

void RPN::ft_divide(int *i, float *old_top, float *result)
{
	(*i)++;
	_numbers.pop();
	if ( _numbers.empty() )
		printError("Stack is empty");
	*result = _numbers.top() / *old_top;
	_numbers.pop();
	_numbers.push(*result);
}

void RPN::ft_add(int *i, float *old_top, float *result)
{
	(*i)++;
	_numbers.pop();
	if ( _numbers.empty() )
		printError("Stack is empty");
	*result = _numbers.top() + *old_top;
	_numbers.pop();
	_numbers.push(*result);
}

void RPN::ft_subtract(int *i, float *old_top, float *result)
{
	(*i)++;
	_numbers.pop();
	if ( _numbers.empty() )
		printError("Stack is empty");
	*result = _numbers.top() - *old_top;
	_numbers.pop();
	_numbers.push(*result);
}

/*************************** MATH FUNCTIONS *********************************************/






// ******************************* Member functions ******************************
void	RPN::ft_calculate(char *argv)
{
	int i = 0;
	while (argv[i])
	{
		if ( argv[i] == ' ' )
			i++;
		
		
		if ( !isCharValid(argv[i]) )
		{
			std::cout << "ERROR: My program supports only + - / * operations" << std::endl;
			return ;
		}

		// If it is a number, push it to the stack.
		if ( '0' <= argv[i] && argv[i] <= '9' )
			_numbers.push( (argv[i++] - '0') );	// convert char to int then increment i then push to stack the int value.
		else		// If it is an operator, pop two numbers from the stack, do the operation and push the result back to the stack.
		{
			if ( _numbers.empty() )	// If stack is empty, print error.
				printError("Stack is empty");

			float	old_top = _numbers.top();
			float	result;

			switch(argv[i])
			{
				case '*':
					ft_multiply( &i, &old_top, &result);
					continue ;
					
				case '+':
					ft_add( &i, &old_top, &result);
					continue ;

				case '-':
					ft_subtract( &i, &old_top, &result);
					continue ;

				case '/':
					ft_divide( &i, &old_top, &result);
					continue ;
			}
		}
	}
	
	// Print the result
	std::cout << _numbers.top() << std::endl;  
	
	_numbers.pop();
	if ( !_numbers.empty() )
		printError("Number has not been fully consumed!");
}