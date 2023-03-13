/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:47:19 by yogun             #+#    #+#             */
/*   Updated: 2023/03/13 17:17:11 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>

class Animal {
public:
    Animal(void);
    Animal(const std::string& type);
    Animal(const Animal& other);
    virtual ~Animal();

    Animal& operator=(const Animal& other);

    virtual void makeSound() const;
    std::string getType() const;

protected:
    std::string type_;
};

#endif