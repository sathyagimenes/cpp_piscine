/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 13:01:47 by sde-cama          #+#    #+#             */
/*   Updated: 2024/02/22 22:33:26 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap("Default", 100, 100, 30)
{
	std::cout << "FragTrap default constructor called" << std::endl;
	return;
};

FragTrap::FragTrap(std::string const &name) : ClapTrap(name, 100, 100, 30)
{
	std::cout << "FragTrap constructor called with name: " << name << std::endl;
	return;
};

FragTrap::FragTrap(FragTrap const &copy) : ClapTrap(copy)
{
	std::cout << "FragTrap Copy constructor called" << std::endl;
	setName(copy.getName());
	setHitPoints(copy.getHitPoints());
	setEnergyPoints(copy.getEnergyPoints());
	setAttackDamage(copy.getAttackDamage());
	return;
};

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap destructor called" << std::endl;
	return;
};

FragTrap & FragTrap::operator = (FragTrap const &rhs)
{
	std::cout << "FragTrap Assignment operator called" << std::endl;
	if (this != &rhs)
		this->ClapTrap::operator = (rhs);
	return *this;
}

void FragTrap::highFivesGuy(void)
{
	std::cout << "FragTrap " << getName() << " requests a high five!" << std::endl;
}
