/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 10:54:25 by sde-cama          #+#    #+#             */
/*   Updated: 2024/02/24 11:05:10 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog")
{
	std::cout << "Dog default constructor called as type Dog" << std::endl;
	return;
};

Dog::Dog(Dog const &copy) : Animal(copy)
{
	std::cout << "Dog Copy constructor called" << std::endl;
	this->_type = copy.getType();
	return;
};

Dog::~Dog(void)
{
	std::cout << "Dog Destructor called" << std::endl;
	return;
};

Dog &Dog::operator=(Dog const &rhs)
{
	std::cout << "Dog Assignment operator called" << std::endl;
	if (this != &rhs)
	{
		setType(rhs.getType());
	}
	return (*this);
}

void Dog::makeSound(void) const
{
	std::cout << "Au au" << std::endl;
	return;
}
