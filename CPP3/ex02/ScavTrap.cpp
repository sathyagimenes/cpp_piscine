/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 13:01:47 by sde-cama          #+#    #+#             */
/*   Updated: 2024/02/22 22:17:19 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap("Default", 100, 50, 20)
{
	std::cout << "ScavTrap default constructor called" << std::endl;
	return;
};

ScavTrap::ScavTrap(std::string const &name) : ClapTrap(name, 100, 50, 20)
{
	std::cout << "ScavTrap constructor called with name: " << name << std::endl;
	return;
};

ScavTrap::ScavTrap(ScavTrap const &copy) : ClapTrap(copy)
{
	std::cout << "ScavTrap Copy constructor called" << std::endl;
	setName(copy.getName());
	setHitPoints(copy.getHitPoints());
	setEnergyPoints(copy.getEnergyPoints());
	setAttackDamage(copy.getAttackDamage());
	return;
};

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap destructor called" << std::endl;
	return;
};

ScavTrap & ScavTrap::operator = (ScavTrap const &rhs)
{
	std::cout << "ScavTrap Assignment operator called" << std::endl;
	if (this != &rhs)
		this->ClapTrap::operator = (rhs);
	return *this;
}

void ScavTrap::attack(const std::string &target)
{
	if (getEnergyPoints() > 0)
	{
		std::cout << "ScavTrap " << getName() << " attacks " << target << ", causing " << getAttackDamage() << " points of damage!" << std::endl;
	}
	else
	{
		std::cout << "ScavTrap " << getName() << " doesn't have any more energy!" << std::endl;
	}
	return;
}

void ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << getName() << " is now in gate keeper mode." << std::endl;
}
