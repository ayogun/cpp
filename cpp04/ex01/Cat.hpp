/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:48:11 by yogun             #+#    #+#             */
/*   Updated: 2023/03/14 13:53:31 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include <iostream>

class Cat : public Animal {
    public:
        Cat(void );
        Cat(const Cat& other);
        virtual ~Cat();

        Cat& operator=(const Cat& other);

        virtual void makeSound() const;
		const std::string& getIdea(int i) const;

	private:
		Brain* _brain; 
};

#endif
