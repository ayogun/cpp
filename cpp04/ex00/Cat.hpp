/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:48:11 by yogun             #+#    #+#             */
/*   Updated: 2023/03/16 15:29:39 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include <iostream>

class Cat : public Animal {
public:
    Cat(void);  // default constructor
    Cat(const Cat& other); // copy constructor
    virtual ~Cat(void); // destructor

    Cat& operator=(const Cat& other); // assiging operator

    virtual void makeSound() const;
};

#endif
