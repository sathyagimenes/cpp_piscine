/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 10:54:25 by sde-cama          #+#    #+#             */
/*   Updated: 2024/02/26 19:24:31 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : AAnimal("Dog")
{
	std::cout << "Dog default constructor called as type Dog" << std::endl;
	this->_brain = new Brain();
	return;
};

Dog::Dog(Dog const &copy) : AAnimal(copy)
{
	std::cout << "Dog Copy constructor called" << std::endl;
	this->_type = copy.getType();
	this->_brain = new Brain(*copy._brain);
	return;
};

Dog::~Dog(void)
{
	std::cout << "Dog Destructor called" << std::endl;
	delete this->_brain;
	return;
};

Dog &Dog::operator=(Dog const &rhs)
{
	std::cout << "Dog Assignment operator called" << std::endl;
	if (this != &rhs)
	{
		setType(rhs.getType());
		delete this->_brain;
		_brain = new Brain(*rhs._brain);
	}
	return (*this);
}

std::ostream &operator << (std::ostream &o, Dog const &i)
{
	(void)i;
	o << "Type: " << i.getType() << std::endl;
	o << "Brain location: " << i.getBrain() << std::endl;
	o << "makeSound: ";
	i.makeSound();
	return (o);
}

void Dog::makeSound(void) const
{
	std::cout << "Au au" << std::endl;
	return;
}


std::string	Dog::getIdea(size_t i) const
{
	return(this->_brain->getIdea(i));
}

void	Dog::setIdea(size_t i, std::string &idea)
{
	this->_brain->setIdea(i, idea);
}

Brain	*Dog::getBrain(void) const
{
	return (this->_brain);
}
