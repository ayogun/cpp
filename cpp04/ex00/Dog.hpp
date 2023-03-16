/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:47:48 by yogun             #+#    #+#             */
/*   Updated: 2023/03/16 14:22:14 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include <iostream>


class Dog : public Animal {
public:
    Dog(void); // default constructor
    Dog(const Dog& other); // copy constructor
    virtual ~Dog(void); // destructor

    Dog& operator=(const Dog& other); // assiging operator

    virtual void makeSound() const;
};

#endif
