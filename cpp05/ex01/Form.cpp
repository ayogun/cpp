/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 21:56:06 by yogun             #+#    #+#             */
/*   Updated: 2023/03/13 22:26:42 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(const std::string name, int signGrade, int execGrade) : name_(name), signGrade_(signGrade), execGrade_(execGrade), isSigned_(false)
{
    if (signGrade < 1 || execGrade < 1)
        throw GradeTooHighException();
    if (signGrade > 150 || execGrade > 150)
        throw GradeTooLowException();
}

Form::~Form() {}

const std::string& Form::getName() const {
    return name_;
}

int Form::getSignGrade() const {
    return signGrade_;
}

int Form::getExecGrade() const {
    return execGrade_;
}

bool Form::getIsSigned() const {
    return isSigned_;
}

void Form::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() <= signGrade_) {
        isSigned_ = true;
    }
    else {
        throw GradeTooLowException();
    }
}

const char* Form::GradeTooHighException::what() const throw() {
    return "Grade too high";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Grade too low";
}

const char* Form::FormNotSignedException::what() const throw() {
    return "Form not signed";
}

std::ostream& operator<<(std::ostream& os, const Form& form) {
    os << "Form " << form.getName() << ", sign grade " << form.getSignGrade() << ", exec grade " << form.getExecGrade() << ", signed ";
    if (form.getIsSigned()) {
        os << "yes";
    }
    else {
        os << "no";
    }
    return os;
}
