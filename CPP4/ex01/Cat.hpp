/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 09:50:21 by sde-cama          #+#    #+#             */
/*   Updated: 2024/02/26 16:44:48 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CAT_H__
#define __CAT_H__

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
private:
	Brain *_brain;

public:
	/* Orthodox Canonical Form methods*/
	Cat(void);
	Cat(Cat const &copy);
	~Cat(void);
	Cat &operator=(Cat const &rhs);

	/* Member Functions */
	void makeSound(void) const;
	std::string getIdea(size_t i) const;
	void setIdea(size_t i, std::string &idea);
	Brain *getBrain(void) const;
};
std::ostream &operator<<(std::ostream &o, Cat const &i);

#endif