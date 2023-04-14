/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 01:14:07 by yogun             #+#    #+#             */
/*   Updated: 2023/04/13 23:56:44 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include <stack>

class RPN {
public:
	RPN(void); // default constructor
	RPN(RPN const &src);	// copy constructor
	~RPN(void);	// Destructure
	RPN &operator=(RPN const &rpn); // Copy assignment operator

	// ****************** Member functions *********************
	
	void	ft_calculate(char *argv);
	void	ft_multiply(int *i, float *old_top, float *result);
	void	ft_divide(int *i, float *old_top, float *result);
	void	ft_add(int *i, float *old_top, float *result);
	void	ft_subtract(int *i, float *old_top, float *result);


// ********************************************************************
private:
	std::stack<float>  _numbers;

};

#endif