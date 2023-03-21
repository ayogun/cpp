/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 00:03:53 by yogun             #+#    #+#             */
/*   Updated: 2023/03/14 00:56:41 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include <fstream>

class ShrubberyCreationForm : public AForm{
	public:
		ShrubberyCreationForm(void); // default constructor
		ShrubberyCreationForm(std::string target); // constructor
		ShrubberyCreationForm(const ShrubberyCreationForm & fixed); // copy constructor
		~ShrubberyCreationForm(void); // destructor

		// copy assignment operator
		ShrubberyCreationForm & operator=(const ShrubberyCreationForm & other);

		// methods
		bool				execute(Bureaucrat const & executor) const;
		std::string			getTarget(void) const;

	private:
		std::string				_target;
};

#endif