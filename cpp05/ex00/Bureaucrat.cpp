/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 21:47:04 by yogun             #+#    #+#             */
/*   Updated: 2023/04/10 12:27:50 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// Here under this constructor we print a message then we check
// whether the grade is too high or too low. If it is, we throw
// an exception. If not, we set the _grade to the given value(grade).
Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name)
{
    std::cout << "Bureaucrat " << name << " constructed with constructer with " << grade << " grade" << std::endl;
    if (grade < 1) {
        throw GradeTooHighException();
    } else if (grade > 150) {
        throw GradeTooLowException();
    }
    _grade = grade;
}

// Copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name)
{
    std::cout << "Bureaucrat copy constructor called" << std::endl;
    *this = other;
}

// Default constructor
Bureaucrat::Bureaucrat(void)
{
    std::cout << "Bureaucrat default constructor called" << std::endl;
    return ;
}

// Destructor
Bureaucrat::~Bureaucrat(void)
{
    std::cout << "Bureaucrat destructor called" << std::endl;
    return ;
}

// Assignment operator
// We check if the object is not the same as the other object.
// If it is, we return the object. If not, we set the _grade to the
// other object's _grade.
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    std::cout << "Bureaucrat assignation operator called" << std::endl;
    if (this != &other) {
        _grade = other._grade;
    }
    return *this;
}

// Getter for _name
const std::string& Bureaucrat::getName() const
{
    return _name;
}

// Getter for _grade
int Bureaucrat::getGrade() const
{
    return _grade;
}

// Here we increment the grade by 1. If the grade is already 1,
// we throw an exception. If not, we increment the grade.
// Remember that the grade is reversed. So the higher the grade,
// the lower the rank.
void Bureaucrat::incrementGrade()
{
    if (_grade <= 1) {
        throw GradeTooHighException();
    }
    std::cout << "Bureaucrat incrementGrade called" << std::endl;
    _grade--;
}

// Here we decrement the grade by 1. If the grade is already 150,
// we throw an exception. If not, we decrement the grade.
// Remember that the grade is reversed. So the higher the grade,
void Bureaucrat::decrementGrade()
{
    if (_grade >= 150) {
        throw GradeTooLowException();
    }
    std::cout << "Bureaucrat decrementGrade called" << std::endl;
    _grade++;
}

// Here we overload the << operator. We print the name and the grade.
// We return the ostream object.
std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj)
{
    os << obj.getName() << ", bureaucrat grade is " << obj.getGrade();
    return os;
}

// Exception message for GradeTooHighException
const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Bureaucrat grade is too high!";
}

// Exception message for GradeTooLowException
const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Bureaucrat grade is too low!";
}
