/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:55:06 by yogun             #+#    #+#             */
/*   Updated: 2023/03/16 14:30:30 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <string>
# include <iostream>

class WrongAnimal {
public:
    WrongAnimal(void); // default constructor
    WrongAnimal(const std::string& type); // constructor
    WrongAnimal(const WrongAnimal& other); // copy constructor
    virtual ~WrongAnimal(void); // destructor

    WrongAnimal& operator=(const WrongAnimal& other); // assiging operator

    // Mmember functions
    virtual void makeSound() const;
    std::string getType() const;

protected:
    std::string type_;
};

#endif
