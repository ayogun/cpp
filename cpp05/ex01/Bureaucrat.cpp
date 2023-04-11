/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 21:47:04 by yogun             #+#    #+#             */
/*   Updated: 2023/04/11 13:36:18 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// constructor with name and grade
Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name)
{
    std::cout << "Bureaucrat " << name << " constructed with constructer with " << grade << " grade" << std::endl;
    // if grade is less than 1 or greater than 150, throw exception
    if (grade < 1)
    {
        throw GradeTooHighException();
    }
    else if (grade > 150)
    {
        throw GradeTooLowException();
    }
    // else set grade
    _grade = grade;
}

// copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name)
{
    std::cout << "Bureaucrat copy constructor called" << std::endl;
    *this = other;
}

// default constructor
Bureaucrat::Bureaucrat(void)
{
    std::cout << "Bureaucrat default constructor called" << std::endl;
    return ;
}

// destructor
Bureaucrat::~Bureaucrat(void)
{
    std::cout << "Bureaucrat destructor called" << std::endl;
    return ;
}

// assign operator
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    std::cout << "Bureaucrat assignation operator called" << std::endl;
    if (this != &other) {
        _grade = other._grade;
    }
    return *this;
}

// getter for name
const std::string& Bureaucrat::getName() const
{
    return _name;
}

// getter for grade
int Bureaucrat::getGrade() const
{
    return _grade;
}

// The name is pretty self explanatory...
void Bureaucrat::incrementGrade()
{
    // if grade is less than or equal to 1, throw exception. Because grade can't be less than 1.
    if (_grade <= 1)
    {
        throw GradeTooHighException();
    }
    std::cout << "Bureaucrat incrementGrade called" << std::endl;
    _grade--;   // We decrement the grade because the grade is higher the lower the grade is.
}

// Vice versa
void Bureaucrat::decrementGrade()
{
    // if grade is 150 or more, throw exception. Because grade can't be more than 150.
    if (_grade >= 150)
    {
        throw GradeTooLowException();
    }
    std::cout << "Bureaucrat decrementGrade called" << std::endl;
    _grade++;
}

// Overload << operator to print Bureaucrat object
std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj)
{
    os << obj.getName() << ", bureaucrat grade is " << obj.getGrade() << ". ";
    return os;
}

// Exception message
const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Bureaucrat grade is too high!";
}

// Exception msg
const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Bureaucrat grade is too low!";
}

// Form sign function.If the form is already signed, throw exception. We check it with beSigned function.
void Bureaucrat::signForm(Form& form)
{
    try {
        form.beSigned(*this);
        std::cout << _name << " signs " << form.getName() << ". "<< std::endl;
    } catch (std::exception& e) {
        std::cout << _name << " cannot sign " << form.getName() << " because " << e.what() << std::endl;
    }
}