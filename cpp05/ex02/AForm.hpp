/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 21:55:35 by yogun             #+#    #+#             */
/*   Updated: 2023/03/14 00:16:14 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

/*
    In C++, you can turn a class into an abstract class by declaring 
    at least one pure virtual function 
    in the class. A pure virtual function is a virtual function 
    that is declared in the base class 
    but has no implementation. It is denoted by appending "= 0" at the end 
    of the function declaration. Check line 73.
*/

// Aform class is abstract class. Because it has a pure virtual function which is execute.
// So what does it mean? It means that AForm class cannot be instantiated. It can only be inherited.
// So we can create a class that inherits from AForm and override the execute method.
// For example, we can create a class called PresidentialPardonForm that inherits from AForm and override the execute method.
// However, if we would like to instantiate Aform class, we can do it by creating a class that inherits from AForm and does not override the execute method.
class AForm {
public:
    AForm(void); // default constructor
    AForm(const std::string& name, int sign, int execute); // parameterized constructor
    AForm(const AForm& other); // copy constructor
    virtual ~AForm(); // virtual destructor

    AForm& operator=(const AForm& other); // assignment operator overload

    // exceptions for grades that are too high or low
    class GradeTooHighException : public std::exception {
    public:
		// what() method that returns a const char* with the error message
        virtual const char* what() const throw();
    };
	
    class GradeTooLowException : public std::exception {
    public:
		// what() method that returns a const char* with the error message
        virtual const char* what() const throw();
    };

	class FormNotSignedException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

    // getter methods
    std::string getName() const;
    bool getIsSigned() const;
    int getSignGrade() const;
    int getExecuteGrade() const;

    // sign method that takes a bureaucrat object and signs the AForm if grade is high enough
    void beSigned(const Bureaucrat& bureaucrat);
	// execute method that takes a bureaucrat object and executes the AForm if grade is high enough
	virtual bool		execute(Bureaucrat const & executor) const = 0;

private:
    const std::string _name;
    bool _isSigned;
    const int _signGrade;
    const int _executeGrade;
};

// overloaded operator for printing AForm details
std::ostream& operator<<(std::ostream& os, const AForm& aform);

#endif
