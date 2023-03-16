/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:47:19 by yogun             #+#    #+#             */
/*   Updated: 2023/03/16 16:43:54 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include "Brain.hpp"

class Animal {
public:
    Animal(void);                       // default constructor
    Animal(const std::string& type);    // constructor
    Animal(const Animal& other);        // copy constructor
    virtual ~Animal(void);              // destructor

    Animal& operator=(const Animal& other); // assiging operator

    virtual void makeSound() const;
    std::string getType() const;

protected:
    std::string _type;
};

#endif
