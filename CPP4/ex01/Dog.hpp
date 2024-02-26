/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 10:54:44 by sde-cama          #+#    #+#             */
/*   Updated: 2024/02/26 17:43:55 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __DOG_H__
#define __DOG_H__

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain	*_brain;

	public:
		/* Orthodox Canonical Form methods*/
		Dog(void);
		Dog(Dog const &copy);
		~Dog(void);
		Dog &operator=(Dog const &rhs);

		/* Member Functions */
		void makeSound(void) const;
		std::string getIdea(size_t i) const;
		void setIdea(size_t i, std::string &idea);
		Brain *getBrain(void) const;
};
std::ostream &operator << (std::ostream &o, Dog const &i);
#endif