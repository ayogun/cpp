/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:55:32 by yogun             #+#    #+#             */
/*   Updated: 2023/03/16 14:34:37 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
public:
    WrongCat(void); // default constructor
    WrongCat(const WrongCat& other); // copy constructor
    virtual ~WrongCat(void); // destructor

    WrongCat& operator=(const WrongCat& other); // assiging operator

    virtual void makeSound() const;

private:
    std::string type_;
};

#endif
