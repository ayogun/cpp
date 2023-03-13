/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 16:13:25 by yogun             #+#    #+#             */
/*   Updated: 2023/03/13 17:18:19 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Brain class Default constructor called" << std::endl;
}

Brain::~Brain(void)
{
	std::cout << "Brain class Destructor called" << std::endl;
}

Brain::Brain(const Brain & other)
{
	std::cout << "Brain class Copy constructor called" << std::endl;
	*this = other;
}

// Assignment operator
Brain & Brain::operator=(const Brain & other)
{
	std::cout << "Brain class Copy assignment operator called" << std::endl;
	if (this == &other)
		return (*this);
	for (int i = 0; i < 100; i++)
		this->_idea[i] = other._idea[i];
	return (*this);
}

// Setter
void	Brain::setIdea(std::string idea, int index)
{
	this->_idea[index] = idea;
}

// Getter
const std::string & Brain::getIdea(int index) const
{
	return (this->_idea[index]);
}