/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 00:04:18 by yogun             #+#    #+#             */
/*   Updated: 2023/03/14 00:52:52 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

class RobotomyRequestForm : public AForm{
	public:
		RobotomyRequestForm(void); // default constructor
		RobotomyRequestForm(std::string target); // constructor
		RobotomyRequestForm(const RobotomyRequestForm & fixed); // copy constructor
		~RobotomyRequestForm(void); // destructor

		// copy assignment operator
		RobotomyRequestForm & operator=(const RobotomyRequestForm & other);

		// methods
		bool				execute(Bureaucrat const & executor) const;
		std::string			getTarget(void) const;

	private:
		std::string				_target;
};

#endif