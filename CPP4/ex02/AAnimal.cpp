/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 19:24:05 by sde-cama          #+#    #+#             */
/*   Updated: 2024/02/26 19:24:07 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal(void)
	: _type("Undefined")
{
	std::cout << "AAnimal default constructor called as type " << _type << std::endl;
	return;
};

AAnimal::AAnimal(AAnimal const &copy)
{
	std::cout << "AAnimal Copy constructor called" << std::endl;
	this->_type = copy.getType();
	return;
};

AAnimal::AAnimal(std::string type)
	: _type(type)
{
	std::cout << "AAnimal Constructor called with type " << type << std::endl;
	_type = type;
	return;
};

AAnimal::~AAnimal(void)
{
	std::cout << "AAnimal Destructor called" << std::endl;
	return;
};

AAnimal &AAnimal::operator=(AAnimal const &rhs)
{
	std::cout << "AAnimal Assignment operator called" << std::endl;
	if (this != &rhs)
	{
		setType(rhs.getType());
	}
	return (*this);
}

// GETTERS
std::string AAnimal::getType(void) const
{
	return (_type);
}

// SETTERS
void AAnimal::setType(std::string const &type)
{
	_type = type;
}
