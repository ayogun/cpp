/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:47:48 by yogun             #+#    #+#             */
/*   Updated: 2023/03/14 13:52:10 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include <iostream>


class Dog : public Animal {
public:
    Dog();
    Dog(const Dog& other);
    virtual ~Dog();

    Dog& operator=(const Dog& other);

    virtual void makeSound() const;
};

#endif
