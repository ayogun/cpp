/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 00:03:59 by yogun             #+#    #+#             */
/*   Updated: 2023/03/14 00:56:04 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

// Default constructor
ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("ShrubberyCreationForm", 25, 5), _target("nothing")
{
	// std::cout << "ShrubberyCreationForm Default Constructor called" << std::endl;
}

// Constructor
ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 25, 5), _target(target)
{
	// std::cout << "ShrubberyCreationForm Constructor called" << std::endl;
}

// Destructor. This is called when you delete an object.
ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	// std::cout << "ShrubberyCreationForm Destructor called" << std::endl;
}

// Copy constructor. This is called when you pass by value.
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm & other)
{
	// std::cout << "ShrubberyCreationForm Copy constructor called" << std::endl;
	*this = other;
}

// Copy assignment operator. This is called when you assign by value.
ShrubberyCreationForm & ShrubberyCreationForm::operator=(const ShrubberyCreationForm & other)
{
	// std::cout << "ShrubberyCreationForm Copy assignment operator called" << std::endl;
	if (this == &other)
		return (*this);
	this->_target = other.getTarget();
	AForm::operator=(other);
	return (*this);
}

// Getter
std::string	ShrubberyCreationForm::getTarget(void) const
{
	return(this->_target);
}

// In this function we draw a diamond.
void	drawDiamond(std::string name)
{
	std::ofstream		ofs;

	ofs.open(name.append("_shrubbery"));
	if (ofs.fail())
	{
		std::cerr << "Error: Can't create the file!" << std::endl;
		return ;
	}
    ofs << "  *  " << std::endl;
    ofs << " *** " << std::endl;
    ofs << "*****" << std::endl;
    ofs << " *** " << std::endl;
    ofs << "  *  " << std::endl;
	ofs << std::endl;
	ofs.close();
}

// With this function we execute the form.
bool	ShrubberyCreationForm:: execute(Bureaucrat const & executor) const
{
	if (this->getIsSigned() == false)
		throw GradeNotSignedException();
	else if (executor.getGrade() > this->getExecuteGrade())
		throw GradeTooLowException();
	else
		drawDiamond(this->getTarget());
	return(true);
}