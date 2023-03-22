/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 01:14:07 by yogun             #+#    #+#             */
/*   Updated: 2023/03/22 15:34:39 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# define STRING	    0
# define FLOAT	    1
# define CHAR  	    2
# define INT   	    3
# define DOUBLE		4

# include <iostream>

class Converter {
	public:
		Converter(void);						// default constructor
		Converter(std::string value);					// constructor with value
		Converter(const Converter & fixed);		// copy constructor		
		~Converter(void);						// destructor

		Converter & operator=(const Converter & other); // assignation operator

		/*****************************************************************************************/

		class ConverterImpossible : public std::exception {
			public:
				virtual const char *what() const throw()
				{
					return ("impossible");
				}
		};

		class CharNonDisplayable : public std::exception {
			public:
				virtual const char *what() const throw()
				{
					return ("Non diplayable");
				}
		};
		
		/*****************************************************************************************/

		// getters
		std::string				getValue(void) const;
		int						getType(void) const;
		char					toChar(void) const;
		int						toInt(void) const;
		float					toFloat(void) const;
		double					toDouble(void) const;

		
		bool					NanMessage( void ) const;

	private:
		std::string		_value;
		int				_type;
		void			setType(void);
};

#endif