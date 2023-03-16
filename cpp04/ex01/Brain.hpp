/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 16:13:14 by yogun             #+#    #+#             */
/*   Updated: 2023/03/16 15:39:54 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

class Brain {
public:
    Brain(void);
    Brain(const Brain& other);
    virtual ~Brain(void);

    Brain& operator=(const Brain& other);

    void setIdea(std::string idea, int index);
    const std::string& getIdea(int index) const;

protected:
    std::string _idea[100];
};

#endif
