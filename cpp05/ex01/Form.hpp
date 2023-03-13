/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 21:55:35 by yogun             #+#    #+#             */
/*   Updated: 2023/03/13 22:26:16 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <string>
#include "Bureaucrat.hpp"

class Form {
public:
    class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    Form(const std::string name, int signGrade, int execGrade);
    ~Form();

    const std::string& getName() const;
    int getSignGrade() const;
    int getExecGrade() const;
    bool getIsSigned() const;

    void beSigned(const Bureaucrat& bureaucrat);

    class FormNotSignedException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    virtual void execute(const Bureaucrat& executor) const = 0;

protected:
    const std::string name_;
    const int signGrade_;
    const int execGrade_;
    bool isSigned_;
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif
