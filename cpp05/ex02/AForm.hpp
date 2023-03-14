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

class Bureaucrat; // forward declaration


class AForm {
public:
    AForm(); // default constructor
    AForm(const std::string& name, int sign, int execute); // parameterized constructor
    AForm(const AForm& other); // copy constructor
    virtual ~AForm(); // virtual destructor

    AForm& operator=(const AForm& other); // assignment operator overload

    // exceptions for grades that are too high or low
    class GradeTooHighException : public std::exception {
    public:
		// what() method that returns a const char* with the error message
        virtual const char* what() const throw() { 
            return "Grade is too high!";
        }
    };
    class GradeTooLowException : public std::exception {
    public:
		// what() method that returns a const char* with the error message
        virtual const char* what() const throw() {
            return "Grade is too low!";
        }
    };

			class GradeNotSignedException : public std::exception {
			public:
				// what() method that returns a const char* with the error message
				virtual const char *what() const throw()
				{
					return ("Form is not signed!");
				}
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
