/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 09:03:33 by sde-cama          #+#    #+#             */
/*   Updated: 2024/02/25 09:03:35 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __WrongCat_H__
#define __WrongCat_H__

#include <iostream>
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
protected:
	std::string _type;

public:
	/* Orthodox Canonical Form methods*/
	WrongCat(void);
	WrongCat(WrongCat const &copy);
	~WrongCat(void);
	WrongCat &operator=(WrongCat const &rhs);

	/* Member Functions */
	void makeSound(void) const;
};

#endif