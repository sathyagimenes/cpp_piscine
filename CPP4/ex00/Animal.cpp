/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 09:50:45 by sde-cama          #+#    #+#             */
/*   Updated: 2024/02/24 10:28:11 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void)
	: _type("Undefined")
{
	std::cout << "Animal default constructor called as type " << _type << std::endl;
	return;
};

Animal::Animal(Animal const &copy)
{
	std::cout << "Animal Copy constructor called" << std::endl;
	this->_type = copy.getType();
	return;
};

Animal::Animal(std::string type)
	: _type(type)
{
	std::cout << "Animal Constructor called with type " << type << std::endl;
	_type = type;
	return;
};

Animal::~Animal(void)
{
	std::cout << "Animal Destructor called" << std::endl;
	return;
};

Animal &Animal::operator=(Animal const &rhs)
{
	std::cout << "Animal Assignment operator called" << std::endl;
	if (this != &rhs)
	{
		setType(rhs.getType());
	}
	return (*this);
}

void Animal::makeSound(void) const
{
	std::cout << "grrrr" << std::endl;
	return;
}

// GETTERS
std::string Animal::getType(void) const
{
	return (_type);
}

// SETTERS
void Animal::setType(std::string const &type)
{
	_type = type;
}
