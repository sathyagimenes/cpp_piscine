/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 13:01:47 by sde-cama          #+#    #+#             */
/*   Updated: 2024/02/22 21:57:36 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
	: _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "Default constructor called" << std::endl;
	return;
};

ClapTrap::ClapTrap(ClapTrap const &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	setName(copy.getName());
	setHitPoints(copy.getHitPoints());
	setEnergyPoints(copy.getEnergyPoints());
	setAttackDamage(copy.getAttackDamage());
	return;
};

ClapTrap::ClapTrap(std::string name)
	: _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "Constructor called with name " << name << std::endl;
	_name = name;
	return;
};

ClapTrap::~ClapTrap(void)
{
	std::cout << "Destructor called" << std::endl;
	return;
};

ClapTrap & ClapTrap::operator = (ClapTrap const &rhs)
{
	std::cout << "ClapTrap Assignment operator called" << std::endl;
	if (this != &rhs)
	{
		setName(rhs.getName());
		setHitPoints(rhs.getHitPoints());
		setEnergyPoints(rhs.getEnergyPoints());
		setAttackDamage(rhs.getAttackDamage());
	}
	return (*this);
}

ClapTrap::ClapTrap(int hitPoints, int energyPoints, int attackDamage)
	: _name("Default"), _hitPoints(hitPoints), _energyPoints(energyPoints), _attackDamage(attackDamage)
{
	std::cout << "Default Constructor called" << std::endl;
	return;
}

ClapTrap::ClapTrap(std::string const &name, int hitPoints, int energyPoints, int attackDamage)
	: _name(name), _hitPoints(hitPoints), _energyPoints(energyPoints), _attackDamage(attackDamage)
{
	std::cout << "New Constructor called with name " << name << std::endl;
	_name = name;
	return;
}

void ClapTrap::attack(const std::string &target)
{
	if (_energyPoints > 0)
	{
		std::cout << "ClapTrap " << getName() << " attacks " << target << ", causing " << getAttackDamage() << " points of damage!" << std::endl;
	}
	else
	{
		std::cout << "ClapTrap " << getName() << " doesn't have any more energy!" << std::endl;
	}
	return;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints > 0)
	{
		setHitPoints(getHitPoints() - amount);
		std::cout << "ClapTrap " << getName() << " takes " << amount << " damage! HP: " << getHitPoints() << std::endl;
	}
	else
	{
		std::cout << "ClapTrap " << getName() << " is dead." << std::endl;
	}
	return;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_energyPoints > 0 && _hitPoints > 0)
	{
		setHitPoints(getHitPoints() + amount);
		setEnergyPoints(getEnergyPoints() - 1);
		std::cout << "ClapTrap " << getName() << " heal " << amount << " hit points! HP: " << getHitPoints() << std::endl;
	}
	else if (_hitPoints <= 0)
	{
		std::cout << "ClapTrap " << getName() << " is dead." << std::endl;
	}
	else if (_energyPoints <= 0)
	{
		std::cout << "ClapTrap " << getName() << " doesn't have any more energy!" << std::endl;
	}
	return;
}

// GETTERS
std::string ClapTrap::getName(void) const
{
	return (_name);
}

int ClapTrap::getHitPoints(void) const
{
	return (_hitPoints);
}

int ClapTrap::getEnergyPoints(void) const
{
	return (_energyPoints);
}

int ClapTrap::getAttackDamage(void) const
{
	return (_attackDamage);
}

// SETTERS
void ClapTrap::setName(std::string const &name)
{
	_name = name;
}

void ClapTrap::setHitPoints(int const hitPoints)
{
	_hitPoints = hitPoints;
}

void ClapTrap::setEnergyPoints(int const energyPoints)
{
	_energyPoints = energyPoints;
}

void ClapTrap::setAttackDamage(int const attackDamage)
{
	_attackDamage = attackDamage;
}
