/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 09:50:31 by sde-cama          #+#    #+#             */
/*   Updated: 2024/02/24 10:40:23 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ANIMAL_H__
#define __ANIMAL_H__

#include <iostream>

class Animal
{
protected:
	std::string _type;

public:
	/* Orthodox Canonical Form methods*/
	Animal(void);
	Animal(Animal const &copy);
	Animal(std::string type);
	virtual ~Animal(void);
	Animal &operator=(Animal const &rhs);

	/* Getters */
	std::string getType(void) const;

	/* Setters */
	void setType(std::string const &type);

	virtual void makeSound(void) const;
};

#endif