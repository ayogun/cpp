/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 00:07:09 by yogun             #+#    #+#             */
/*   Updated: 2023/03/14 00:51:56 by yogun            ###   ########.fr       */
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
		bool				execute(Bureaucrat const & executor) const;
		std::string			getTarget(void) const;

	private:
		std::string				_target;
};

#endif