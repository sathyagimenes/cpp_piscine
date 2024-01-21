/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 22:30:16 by sde-cama          #+#    #+#             */
/*   Updated: 2024/01/21 17:54:11 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CLAPTRAP_H__
#define __CLAPTRAP_H__

#include <iostream>

class ClapTrap
{
private:
	std::string _name;
	int _hitPoints;
	int _energyPoints;
	int _attackDamage;

public:
	ClapTrap(void);
	ClapTrap(ClapTrap const &copy);
	ClapTrap(std::string name);
	~ClapTrap(void);

	/* Getters */
	std::string	getName(void) const;
	int		getHitPoints(void) const;
	int		getEnergyPoints(void) const;
	int		getAttackDamage(void) const;

	/* Setters */
	void	setName(std::string const &name);
	void	setHitPoints(int const hitPoints);
	void	setEnergyPoints(int const energyPoints);
	void	setAttackDamage(int const attackDamage);
	
	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};

#endif