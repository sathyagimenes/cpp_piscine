/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 20:49:15 by sde-cama          #+#    #+#             */
/*   Updated: 2024/03/06 20:39:54 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(void)
{
	std::cout << "Default constructor called." << std::endl;
	return;
}

Serializer::Serializer(Serializer const &src)
{
	std::cout << "Copy constructor called." << std::endl;
	*this = src;
	return;
}

Serializer::~Serializer(void)
{
	std::cout << "Destructor called." << std::endl;
	return;
}

Serializer &Serializer::operator=(Serializer const &rhs)
{
	std::cout << "Assignment operator called." << std::endl;
	(void)rhs;
	return (*this);
}

// Methods
uintptr_t Serializer::serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data *Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}
