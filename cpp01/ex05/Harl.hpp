/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 11:06:40 by yogun             #+#    #+#             */
/*   Updated: 2023/03/07 11:19:07 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <string>

class Harl {
    private:
        void debug();
        void info();
        void warning();
        void error();
		void	(Harl::*ptr[5]) ( void ); 
    
    public:
		Harl(void);
		~Harl(void);
        void complain(std::string level);
};

#endif
