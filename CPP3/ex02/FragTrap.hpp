/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 22:30:16 by sde-cama          #+#    #+#             */
/*   Updated: 2024/02/22 22:29:12 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FRAGTRAP_H__
#define __FRAGTRAP_H__

#include <iostream>
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{

public:
	/* Orthodox Canonical Form methods*/
	FragTrap(void);
	FragTrap(std::string const &name);
	FragTrap(FragTrap const &copy);
	~FragTrap(void);
	FragTrap &operator=(FragTrap const &rhs);

	/* Member Functions */
	void	highFivesGuy(void);
};

#endif