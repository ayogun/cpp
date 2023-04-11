/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 00:07:09 by yogun             #+#    #+#             */
/*   Updated: 2023/04/11 13:52:47 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm{
	public:
		PresidentialPardonForm(void);	// default constructor
		PresidentialPardonForm(std::string target); // constructor
		PresidentialPardonForm(const PresidentialPardonForm & fixed); // copy constructor
		~PresidentialPardonForm(void); // destructor

		// copy assignment operator
		PresidentialPardonForm & operator=(const PresidentialPardonForm & other);

		// methods
		bool				execute(Bureaucrat const & executor) const; // execute function has been inherited from AForm and is overriden here
		std::string			getTarget(void) const;

	private:
		std::string				_target;
};

#endif