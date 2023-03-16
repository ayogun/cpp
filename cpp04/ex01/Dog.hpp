/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:47:48 by yogun             #+#    #+#             */
/*   Updated: 2023/03/16 15:35:09 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog : public Animal {
public:
    Dog(void);  
    Dog(const Dog& other);
    virtual ~Dog(void);
    
    Dog& operator=(const Dog& other);

    virtual void makeSound() const;
	const std::string & getIdea(int index) const;

private:
	Brain*		_brain;
};

#endif
