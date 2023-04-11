/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 21:56:06 by yogun             #+#    #+#             */
/*   Updated: 2023/04/11 13:38:40 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

// default constructor
Form::Form(void) : 
    _name("Default Form"), 
    _isSigned(false), 
    _signGrade(75), 
    _executeGrade(75) {
	std::cout << "Form default constructor called" << std::endl;
}

// parameterized constructor
Form::Form(const std::string& name, int sign, int execute)
    : _name(name), _isSigned(false), _signGrade(sign), _executeGrade(execute) {
    // check if grades are valid
    if (sign < 1 || execute < 1)
        throw GradeTooHighException();
    else if (sign > 150 || execute > 150)
        throw GradeTooLowException();
    else
        std::cout << "Form " << name << " constructed with constructer with " << sign << " sign grade and " << execute << " execute grade" << std::endl;
}

// copy constructor
Form::Form(const Form& other)
    : _name(other.getName()), _isSigned(other.getIsSigned()), 
    _signGrade(other.getSignGrade()), _executeGrade(other.getExecuteGrade()) {
    std::cout << "Form copy constructor called" << std::endl;
    }

// destructor
Form::~Form(void) {
    std::cout << "Form destructor called" << std::endl;
}

// assignment operator overload
Form& Form::operator=(const Form& other) {
    std::cout << "Form assignation operator called" << std::endl;
    if (this != &other)
    {
        _isSigned = other._isSigned;
    }
    return *this;
}

// getter methods
std::string Form::getName() const {
    return _name;
}

// Getter method to check whether form is signed
bool Form::getIsSigned() const {
    return _isSigned;
}

// Getter method for sign grade
int Form::getSignGrade() const {
    return _signGrade;
}

int Form::getExecuteGrade() const {
    return _executeGrade;
}

// sign method that takes a bureaucrat object and signs the form if grade is high enough
void Form::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() <= _signGrade && !_isSigned)
    {
        std::cout << "Form " << _name << " signed by " << bureaucrat.getName() << std::endl;
        _isSigned = true;
    }
    else
    {
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

// Exception message 
char const* Form::GradeTooHighException::what() const throw() {
	return "Grade is too high!";
}

// Exception messgae
char const* Form::GradeTooLowException::what() const throw() {
	return "Grade is too low!";
}