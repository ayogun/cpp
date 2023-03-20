/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 21:56:06 by yogun             #+#    #+#             */
/*   Updated: 2023/03/13 23:31:44 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

// default constructor
AForm::AForm() : _name("Default AForm"), _isSigned(false), _signGrade(1), _executeGrade(1) {
	return ;
}

// parameterized constructor
AForm::AForm(const std::string& name, int sign, int execute)
    : _name(name), _isSigned(false), _signGrade(sign), _executeGrade(execute) {
    // check if grades are valid. If not, throw exception. 
    if (sign < 1 || execute < 1)
        throw GradeTooHighException();
    else if (sign > 150)
        throw GradeTooLowException();
	else if (execute > 150)
		throw GradeTooLowException();
	else
		std::cout << "AForm " << name << " created" << std::endl;
	return ;
}

// copy constructor
AForm::AForm(const AForm& other)
    : _name(other.getName()),
	_isSigned(other.getIsSigned()), 
    _signGrade(other.getSignGrade()),
	_executeGrade(other.getExecuteGrade()) 
	{
		return ;
	}

// destructor
AForm::~AForm(void) {
	return ;
}

// assignment operator overload
AForm& AForm::operator=(const AForm& other) {
    if (this != &other) {
        _isSigned = other._isSigned;
    }
    return *this;
}

// getter method for _name
std::string AForm::getName() const {
    return _name;
}

// getter method for _isSigned
bool AForm::getIsSigned() const {
    return _isSigned;
}

// getter methods for _signGrade and _executeGrade
int AForm::getSignGrade() const {
    return _signGrade;
}

int AForm::getExecuteGrade() const {
    return _executeGrade;
}

// sign method that takes a bureaucrat object and signs the AForm if grade is high enough
void AForm::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() <= _signGrade) {
        _isSigned = true;
    }
    else {
        throw GradeTooLowException();
    }
}

// overloaded operator for printing AForm details
std::ostream& operator<<(std::ostream& os, const AForm& AForm) {
os << "AForm name: " << AForm.getName() << std::endl;
os << "Sign grade required: " << AForm.getSignGrade() << std::endl;
os << "Execute grade required: " << AForm.getExecuteGrade() << std::endl;
os << "Is signed: ";
if (AForm.getIsSigned()) {
os << "yes" << std::endl;
}
else {
os << "no" << std::endl;
}
return os;
}