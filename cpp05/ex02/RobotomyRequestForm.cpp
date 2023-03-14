/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 00:04:15 by yogun             #+#    #+#             */
/*   Updated: 2023/03/14 00:52:28 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

// Constructors
RobotomyRequestForm::RobotomyRequestForm(void) : AForm("RobotomyRequestForm", 72, 45), _target("nothing")
{
	// std::cout << "RobotomyRequestForm Default Constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	// std::cout << "RobotomyRequestForm Default Constructor called" << std::endl;
}

// Destructor. This is called when you delete an object.
RobotomyRequestForm::~RobotomyRequestForm(void)
{
	// std::cout << "RobotomyRequestForm Destructor called" << std::endl;
}

// Copy constructor. This is called when you pass by value.
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm & other)
{
	// std::cout << "RobotomyRequestForm Copy constructor called" << std::endl;
	*this = other;
}

// Copy assignment operator. This is called when you assign by value.
RobotomyRequestForm & RobotomyRequestForm::operator=(const RobotomyRequestForm & other)
{
	// std::cout << "RobotomyRequestForm Copy assignment operator called" << std::endl;
	if (this == &other)
		return (*this);
	this->_target = other.getTarget();
	AForm::operator=(other);
	return (*this);
}

// Getters
std::string	RobotomyRequestForm::getTarget(void) const
{
	return(this->_target);
}

// Here is the function that will be called when the form is executed.
bool	RobotomyRequestForm:: execute(Bureaucrat const & executor) const
{
	if (this->getIsSigned() == false)
		throw GradeNotSignedException();
	else if (executor.getGrade() > this->getExecuteGrade())
		throw GradeTooLowException();
	else
	{
		std::cout << "RobotomyRequestForm: * Some drilling noises... *   ";
		if (std::rand() % 2 == 0)
			std::cout << this->getTarget() << " has been robotomized successfully!" << std::endl;
		else
			std::cout << "Lucky " << this->getTarget() << "! Robotomy was failed..." << std::endl;
	}
	return(true);
}
