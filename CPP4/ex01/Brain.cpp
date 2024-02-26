/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 23:11:52 by sde-cama          #+#    #+#             */
/*   Updated: 2024/02/26 18:05:22 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <cstdlib>

Brain::Brain(void)
{
	std::string activities[6] = {
        "sleep",
        "eat",
        "play",
        "run",
        "fight",
        "hunt"
    };

    for ( int i = 0; i < 100; i++ )
        this->_ideas[i] = activities[rand() % 6];
    std::cout << "Brain constructor called" << std::endl;
	return;
};

Brain::Brain(Brain const &copy)
{
	std::cout << "Brain Copy constructor called" << std::endl;

	for (size_t i = 0; i < 100; i++)
		this->_ideas[i] = copy._ideas[i];
	return;
};

Brain::~Brain(void)
{
	std::cout << "Brain Destructor called" << std::endl;
	return;
};

Brain &Brain::operator=(Brain const &rhs)
{
	std::cout << "Brain Assignment operator called" << std::endl;
	if (this != &rhs)
	{
		for (size_t i = 0; i < 100; i++)
			this->_ideas[i] = rhs._ideas[i];
	}
	return (*this);
};

// GETTERS
std::string Brain::getIdea(size_t i) const
{
	return (this->_ideas[i]);
};

// SETTERS
void Brain::setIdea(size_t i, std::string idea)
{
	this->_ideas[i] = idea;
};
