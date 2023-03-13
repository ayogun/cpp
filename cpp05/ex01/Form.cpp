/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 21:56:06 by yogun             #+#    #+#             */
/*   Updated: 2023/03/13 23:31:44 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

// default constructor
Form::Form() : _name("Default Form"), _isSigned(false), _signGrade(150), _executeGrade(150) {
	
}

// parameterized constructor
Form::Form(const std::string& name, int sign, int execute)
    : _name(name), _isSigned(false), _signGrade(sign), _executeGrade(execute) {
    // check if grades are valid
    if (sign < 1 || execute < 1)
        throw GradeTooHighException();
    else if (sign > 150 || execute > 150)
        throw GradeTooLowException();
}

// copy constructor
Form::Form(const Form& other)
    : _name(other.getName()), _isSigned(other.getIsSigned()), 
    _signGrade(other.getSignGrade()), _executeGrade(other.getExecuteGrade()) {}

// destructor
Form::~Form() {}

// assignment operator overload
Form& Form::operator=(const Form& other) {
    if (this != &other) {
        _isSigned = other._isSigned;
    }
    return *this;
}

// getter methods
std::string Form::getName() const {
    return _name;
}

bool Form::getIsSigned() const {
    return _isSigned;
}

int Form::getSignGrade() const {
    return _signGrade;
}

int Form::getExecuteGrade() const {
    return _executeGrade;
}

// sign method that takes a bureaucrat object and signs the form if grade is high enough
void Form::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() <= _signGrade) {
        _isSigned = true;
    }
    else {
        throw GradeTooLowException();
    }
}

// overloaded operator for printing form details
std::ostream& operator<<(std::ostream& os, const Form& form) {
os << "Form name: " << form.getName() << std::endl;
os << "Sign grade required: " << form.getSignGrade() << std::endl;
os << "Execute grade required: " << form.getExecuteGrade() << std::endl;
os << "Is signed: ";
if (form.getIsSigned()) {
os << "yes" << std::endl;
}
else {
os << "no" << std::endl;
}
return os;
}