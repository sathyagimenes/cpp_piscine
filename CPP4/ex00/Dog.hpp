/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 10:54:44 by sde-cama          #+#    #+#             */
/*   Updated: 2024/02/24 10:54:47 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __DOG_H__
#define __DOG_H__

#include <iostream>
#include "Animal.hpp"

class Dog : public Animal
{
protected:
	std::string _type;

public:
	/* Orthodox Canonical Form methods*/
	Dog(void);
	Dog(Dog const &copy);
	~Dog(void);
	Dog &operator=(Dog const &rhs);

	/* Member Functions */
	void makeSound(void) const;
};

#endif