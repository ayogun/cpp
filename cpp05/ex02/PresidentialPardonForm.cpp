/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 00:07:07 by yogun             #+#    #+#             */
/*   Updated: 2023/03/14 00:51:24 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

// Constructors
PresidentialPardonForm::PresidentialPardonForm(void) : AForm("PresidentialPardonForm", 25, 5), _target("nothing")
{
	//std::cout << "PresidentialPardonForm Default Constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	//std::cout << "PresidentialPardonForm Default Constructor called" << std::endl;
}

// Destructor. This is called when you delete an object.
PresidentialPardonForm::~PresidentialPardonForm(void)
{
	// std::cout << "PresidentialPardonForm Destructor called" << std::endl;
}

// Copy constructor. This is called when you pass by value.
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm & other)
{
	// std::cout << "PresidentialPardonForm Copy constructor called" << std::endl;
	*this = other;
}

// Copy assignment operator. This is called when you assign by value.
PresidentialPardonForm & PresidentialPardonForm::operator=(const PresidentialPardonForm & other)
{
	// std::cout << "PresidentialPardonForm Copy assignment operator called" << std::endl;
	if (this == &other)
		return (*this);
	this->_target = other.getTarget();
	AForm::operator=(other);	// copy base class
	return (*this);
}

// Getters
std::string	PresidentialPardonForm::getTarget(void) const
{
	return(this->_target);
}

// Here is the function that will be called when the form is executed.
bool	PresidentialPardonForm:: execute(Bureaucrat const & executor) const
{
	if (this->getIsSigned() == false)
		throw GradeNotSignedException();
	else if (executor.getGrade() > this->getExecuteGrade())
		throw GradeTooLowException();
	else
		std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox!" << std::endl;
	return(true);
}
