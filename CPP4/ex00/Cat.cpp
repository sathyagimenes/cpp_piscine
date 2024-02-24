/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 09:50:56 by sde-cama          #+#    #+#             */
/*   Updated: 2024/02/24 10:23:23 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat")
{
	std::cout << "Cat default constructor called as type Cat" << std::endl;
	return;
};

Cat::Cat(Cat const &copy) : Animal(copy)
{
	std::cout << "Cat Copy constructor called" << std::endl;
	this->_type = copy.getType();
	return;
};

Cat::~Cat(void)
{
	std::cout << "Cat Destructor called" << std::endl;
	return;
};

Cat &Cat::operator=(Cat const &rhs)
{
	std::cout << "Cat Assignment operator called" << std::endl;
	if (this != &rhs)
	{
		setType(rhs.getType());
	}
	return (*this);
}

void Cat::makeSound(void) const
{
	std::cout << "Miau" << std::endl;
	return;
}
