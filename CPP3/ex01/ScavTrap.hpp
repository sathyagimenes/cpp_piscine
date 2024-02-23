/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 22:30:16 by sde-cama          #+#    #+#             */
/*   Updated: 2024/02/22 21:51:50 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SCAVTRAP_H__
#define __SCAVTRAP_H__

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{

public:
	/* Orthodox Canonical Form methods*/
	ScavTrap(void);
	ScavTrap(std::string const &name);
	ScavTrap(ScavTrap const &copy);
	~ScavTrap(void);
	ScavTrap &operator=(ScavTrap const &rhs);

	void attack(const std::string &target);
	void guardGate(void);
};

#endif