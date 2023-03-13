/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:55:32 by yogun             #+#    #+#             */
/*   Updated: 2023/03/13 17:17:34 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
public:
    WrongCat();
    WrongCat(const WrongCat& other);
    virtual ~WrongCat();

    WrongCat& operator=(const WrongCat& other);

    virtual void makeSound() const;
};

#endif