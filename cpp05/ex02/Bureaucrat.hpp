/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 21:45:59 by yogun             #+#    #+#             */
/*   Updated: 2023/03/14 00:40:22 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"

class AForm;

class Bureaucrat {
public:
    class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    Bureaucrat(const std::string& name, int grade);
    Bureaucrat(const Bureaucrat& other);
    ~Bureaucrat();

    Bureaucrat& operator=(const Bureaucrat& other);

    const std::string& getName() const;
    int getGrade() const;

    void incrementGrade();
    void decrementGrade();

	void	signForm(AForm & i);
	void	executeForm(AForm const & form);


private:
    std::string _name;
    int _grade;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj);

#endif
