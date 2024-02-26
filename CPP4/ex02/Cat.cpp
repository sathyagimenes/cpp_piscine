/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 09:50:56 by sde-cama          #+#    #+#             */
/*   Updated: 2024/02/26 19:24:19 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : AAnimal("Cat")
{
	std::cout << "Cat default constructor called as type Cat" << std::endl;
	this->_brain = new Brain();
	return;
};

Cat::Cat(Cat const &copy) : AAnimal(copy)
{
	std::cout << "Cat Copy constructor called" << std::endl;
	this->_type = copy.getType();
	this->_brain = new Brain(*copy._brain);
	return;
};

Cat::~Cat(void)
{
	std::cout << "Cat Destructor called" << std::endl;
	delete this->_brain;
	return;
};

Cat &Cat::operator=(Cat const &rhs)
{
	std::cout << "Cat Assignment operator called" << std::endl;
	if (this != &rhs)
	{
		setType(rhs.getType());
		delete this->_brain;
		_brain = new Brain(*rhs._brain);
	}
	return (*this);
}

std::ostream &operator << (std::ostream &o, Cat const &i)
{
	(void)i;
	o << "Type: " << i.getType() << std::endl;
	o << "Brain location: " << i.getBrain() << std::endl;
	o << "makeSound: ";
	i.makeSound();
	return (o);
}

void Cat::makeSound(void) const
{
	std::cout << "Miau" << std::endl;
	return;
}

std::string	Cat::getIdea(size_t i) const
{
	return(this->_brain->getIdea(i));
}

void	Cat::setIdea(size_t i, std::string &idea)
{
	this->_brain->setIdea(i, idea);
}

Brain	*Cat::getBrain(void) const
{
	return (this->_brain);
}
