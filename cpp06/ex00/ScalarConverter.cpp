/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 01:14:17 by yogun             #+#    #+#             */
/*   Updated: 2023/04/11 15:13:46 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	Implicit casts are automatic type conversions that happen 
	when I assign a value of one data type to another data type. 
	Promotion casts are implicit casts that convert a value of a smaller data type 
	to a larger data type. For example, converting an int to a float or double.

	PDF is saying that I should only use implicit casts for promotion casts only. This means that I should only use implicit casts when I are converting from a smaller data type to a larger data type.
*/

#include "ScalarConverter.hpp"

// Default constructor
Converter::Converter(void) : _value("default"), _type(STRING)
{
	//std::cout << "Default Constructor called" << std::endl;
}

// Constructor with value
Converter::Converter(const std::string input) : _value(input), _type(STRING)
{
	//std::cout << "Constructor called" << std::endl;
	this->setType();
	return ; // If you want to print the type of input, delete this return
	switch (this->getType())
	{
		case STRING:
			std::cout << "The input type is string" << std::endl;
			break ;
		case CHAR:
			std::cout << "The input type is char" << std::endl;
			break ;
		case INT:
			std::cout << "The input type is int" << std::endl;
			break ;
		case FLOAT:
			std::cout << "The input type is float" << std::endl;
			break ;
		case DOUBLE:
			std::cout << "The input type is double" << std::endl;
			break ;
		default:
			std::cout << "The input type is ??" << std::endl;
			break ;
	}
}

// Destructor
Converter::~Converter(void)
{
	//std::cout << "Destructor called" << std::endl;
}

// copy constructor
Converter::Converter(const Converter & other)
{
	//std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

// ASSIGN operator
Converter & Converter::operator=(const Converter & other)
{
	//std::cout << "Copy assignment operator called" << std::endl;
	if (this == &other)
		return (*this);
	this->_value = other.getValue();	// copy value
	this->_type = other.getType();		// copy type
	return (*this);
}


/**********************   MEMBER FUNCTIONS    *********************/

// getter for _type
int	Converter::getType( void ) const
{
	return (this->_type);
}

// getter for _value
std::string	Converter::getValue( void ) const
{
	return (this->_value);
}

// Convert input to int data type
int	Converter::toInt( void ) const
{
	int	i;

	// First we check the input type with getType function and put it into switch case
	switch (this->getType())
	{
		case CHAR:
			i = static_cast<int>(this->getValue()[0]); // char to int. Here we use static_cast because we know that char is smaller than int. So this is promotion cast.
			break;
		case STRING:			// if the input is string, we can't convert it to int
			throw ConverterImpossible();
		default:
			try
			{
				i = std::stoi(this->getValue()); // string to int
			}
			catch(const std::exception& e)
			{
				throw ConverterImpossible();
			}
	}
	return (i);
}

// Convert input to char data type
char	Converter::toChar( void ) const
{
	int			i;

	switch (this->getType())
	{
		case STRING:	// if the input is string, we can't convert it to char
			throw ConverterImpossible();
		case CHAR:		// if the input is char, we can convert it to int
			i = static_cast<int>(this->getValue()[0]); // char to int
			break;
		default:		// if the input is int or float or double, we can convert it to int
			try
			{
				i = std::stoi(this->getValue()); // string to int
			}
			catch(const std::exception& e)
			{
				throw ConverterImpossible();
			}
	}

	// if the int value is greater than 127, we throw exception because ascii table has only 128 characters
	if( i > 127)
		throw ConverterImpossible();
	else if (i <= 31 || i == 127)		// if the int is smaller than 31 or equal to 127, we throw exception because it is not printable char
		throw CharNonDisplayable();
		
	return (i);
}

// Convert input to double data type
double	Converter::toDouble( void ) const
{
	double d;

	switch (this->getType())
	{
		case CHAR:
			d = static_cast<float>(this->getValue()[0]);	// char to double. Smallar to larger data type. So we use static_cast which is promotion cast.
			break;
		case STRING:
			throw ConverterImpossible();
		default:
			try
			{
				d = std::stod(this->getValue());
			}
			catch(const std::exception& e)
			{
				throw ConverterImpossible();
			}
	}
	return (d);
}

// Convert input to float data type
float	Converter::toFloat( void ) const
{
	float f;

	switch (this->getType())
	{
		case CHAR:
			f = static_cast<float>(this->getValue()[0]); // char to float. And yes you guessed right. Promotion cast again :) 
			break;
		case STRING:
			throw ConverterImpossible();
		default:
			try
			{
				f = std::stof(this->getValue()); // string to float
			}
			catch(const std::exception& e)
			{
				throw ConverterImpossible();
			}
	}
	return (f);
}

// In this function we check if the input is nan, +inf or -inf and so on and so on. This is a meaningless part of the proejct which was mandated by the pdf -_-
bool	Converter::NanMessage( void ) const
{
	if (this->getValue() == "nan" || this->getValue() == "+inf" || this->getValue() == "-inf")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << this->getValue() << "f" << std::endl; // We add f to the end of the string
		std::cout << "double: " << this->getValue() << std::endl;
	}
	else if (this->getValue() == "nanf" || this->getValue() == "+inff" || this->getValue() == "-inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << this->getValue() << std::endl;
		std::cout << "double: " << this->getValue().substr(0, this->getValue().length() - 1) << std::endl; // We remove the f at the end of the string
	}
	else
		return(false);
	return(true);
}

// We take the input and here we decide the type whether it's a char, int, float or double.
void	Converter::setType(void)
{
	int	i = 0;

	// If string has one char, it can be a char or an int
	if (this->getValue().length() < 2)
	{
		(isdigit(this->getValue()[0]) == 0) ? this->_type = CHAR : this->_type = INT;
		return ;
	}
	
	// Check for + or - at the beginning
	if (this->getValue()[i] == '-' || this->getValue()[i] == '+')
		i += 1;
	// Itereate through the string while there is a digit
	while (this->getValue()[i] && isdigit(this->getValue()[i]) != 0)
		i += 1;
	// If the string is finished, it can be an int
	if (!this->getValue()[i])
		this->_type = INT;

	// If the upcoming value is dot, it can be eaither float or double. If it's not, it's a string
	else if (this->getValue()[i] == '.')
	{
		i++;
		while (this->getValue()[i] && this->getValue()[i] == '0')
			i++;
		if (!this->getValue()[i] || (this->getValue()[i] == 'f' && !this->getValue()[i + 1])) // If the string is finished or the next value is f, it will be int. Because 0.0f is 0 int.
		{
			this->_type = INT;
			return ;
		}		

		// As long as there is a digit, we iterate
		while (this->getValue()[i] && isdigit(this->getValue()[i]) != 0)
			i++;

		// If the string is finished, it can be a float or a double. If the next value is f, it will be float. If not, it will be double. If both cases are wrong, it's a string
		if (this->getValue()[i] == 'f' && !this->getValue()[i + 1])
			this->_type = FLOAT;
		else if(!this->getValue()[i])
			this->_type = DOUBLE;
		else
			this->_type = STRING;
	}
	else
		this->_type = STRING;
}

// Exception message for impossible conversion
char const * Converter::ConverterImpossible::what() const throw()
{
	return ("impossible");
}

// Exception message for non displayable char
char const * Converter::CharNonDisplayable::what() const throw()
{
	return ("Non displayable");
}