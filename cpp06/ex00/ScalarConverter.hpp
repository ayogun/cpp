/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 01:14:07 by yogun             #+#    #+#             */
/*   Updated: 2023/04/11 14:56:36 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# define INT   	    0
# define CHAR  	    1
# define FLOAT	    2
# define DOUBLE		3
# define STRING	    4

# include <iostream>

class Converter {
	public:
		Converter(void);						// default constructor
		Converter(std::string value);					// constructor with value
		Converter(const Converter & fixed);		// copy constructor		
		~Converter(void);						// destructor

		Converter & operator=(const Converter & other); // assignation operator

		/*****************************************************************************************/
		
		// Exception for impossible conversion
		class ConverterImpossible : public std::exception {
			public:
				virtual const char *what() const throw();
		};

		// Exception for non displayable char
		class CharNonDisplayable : public std::exception {
			public:
				virtual const char *what() const throw();
		};
		
		/*****************************************************************************************/

		bool					NanMessage( void ) const;	// Pint out Nan message
		char					toChar(void) const;			// convert to char
		float					toFloat(void) const;		// convert to float
		int						toInt(void) const;			// convert to int
		double					toDouble(void) const;		// convert to double

		// getters
		int						getType(void) const;		// get the type of the value
		std::string				getValue(void) const;		// get the value

		
		

	private:
		std::string		_value;			// value to convert, in other words it will be sent by user
		void			setType(void);	// set the type of the value
		int				_type; 			// 0 = int, 1 = char, 2 = float, 3 = double, 4 = string
};

#endif