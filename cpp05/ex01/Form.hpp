/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 21:55:35 by yogun             #+#    #+#             */
/*   Updated: 2023/04/11 13:31:07 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
public:
    Form(void); // default constructor
    Form(const std::string& name, int sign, int execute); // parameterized constructor
    Form(const Form& other); // copy constructor
    virtual ~Form(void); // virtual destructor

    Form& operator=(const Form& other); // assignment operator overload

    // exceptions for grades that are too high or low
    class GradeTooHighException : public std::exception
    {
    public:
        virtual const char* what() const throw();
    };
    class GradeTooLowException : public std::exception
    {
    public:
        virtual const char* what() const throw();
    };

    // getter methods
    std::string getName() const;
    bool getIsSigned() const;
    int getSignGrade() const;
    int getExecuteGrade() const;

    // sign method that takes a bureaucrat object and signs the form if grade is high enough
    void beSigned(const Bureaucrat& bureaucrat);

private:
    const std::string _name;
    bool _isSigned;
    const int _signGrade;
    const int _executeGrade;
};

// overloaded operator for printing form details
std::ostream& operator<<(std::ostream& os, const Form& form);

#endif
