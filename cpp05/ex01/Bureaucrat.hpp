/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 21:45:59 by yogun             #+#    #+#             */
/*   Updated: 2023/04/11 13:30:20 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include "Form.hpp"

class Form;

class Bureaucrat {
public:
    // Exceptions. They are nested classes. 
    class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw(); // It is a virtual function because it is inherited from std::exception class. 
    };

    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
    // Declaring a method as virtual in a base class allows derived classes to override it with their own implementation. 
    // This means that when an exception is thrown, if its type is a derived class of std::exception, then calling what() on that exception will call the appropriate implementation of what() in that derived class.
    //------------------------------------------------------------

    Bureaucrat(void);                                       // default constructor
    Bureaucrat(const std::string& name, int grade);             // constructor
    Bureaucrat(const Bureaucrat& other);                       // copy constructor
    ~Bureaucrat(void);                                       // destructor

    Bureaucrat& operator=(const Bureaucrat& other);  // qassign operator


    // Getters
    const std::string& getName() const;
    int getGrade() const;

    // Methods
    void incrementGrade();  // Increase grade decrease the grade, because grade is the highest level of the bureaucrat is 1 and the lowest level is 150.
    void decrementGrade();  // grade can not be lower than 150
    void signForm(Form& form);  // Sign the form. If the grade is too low, it will throws an exception.

private:
    const std::string _name;
    int _grade;
};

// Overload operator. By this way we can print the object with cout.
std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj);

#endif
