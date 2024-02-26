/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 08:50:23 by sde-cama          #+#    #+#             */
/*   Updated: 2024/02/25 09:10:15 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __WRONGANIMAL_H__
#define __WRONGANIMAL_H__

#include <iostream>

class WrongAnimal
{
protected:
	std::string _type;

public:
	/* Orthodox Canonical Form methods*/
	WrongAnimal(void);
	WrongAnimal(WrongAnimal const &copy);
	WrongAnimal(std::string type);
	~WrongAnimal(void);
	WrongAnimal &operator=(WrongAnimal const &rhs);

	/* Getters */
	std::string getType(void) const;

	/* Setters */
	void setType(std::string const &type);
	
	/* Member Functions */
	void makeSound(void) const;
};

#endif