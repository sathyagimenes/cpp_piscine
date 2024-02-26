/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 08:51:50 by sde-cama          #+#    #+#             */
/*   Updated: 2024/02/25 09:32:35 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
	: _type("WrongUndefined")
{
	std::cout << "WrongAnimal default constructor called as type " << _type << std::endl;
	return;
};

WrongAnimal::WrongAnimal(WrongAnimal const &copy)
{
	std::cout << "WrongAnimal Copy constructor called" << std::endl;
	this->_type = copy.getType();
	return;
};

WrongAnimal::WrongAnimal(std::string type)
	: _type(type)
{
	std::cout << "WrongAnimal Constructor called with type " << type << std::endl;
	_type = type;
	return;
};

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal Destructor called" << std::endl;
	return;
};

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &rhs)
{
	std::cout << "WrongAnimal Assignment operator called" << std::endl;
	if (this != &rhs)
	{
		setType(rhs.getType());
	}
	return (*this);
}

void WrongAnimal::makeSound(void) const
{
	std::cout << "Wrong grrrr" << std::endl;
	return;
}

// GETTERS
std::string WrongAnimal::getType(void) const
{
	return (_type);
}

// SETTERS
void WrongAnimal::setType(std::string const &type)
{
	_type = type;
}
