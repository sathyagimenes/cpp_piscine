/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 22:18:32 by sde-cama          #+#    #+#             */
/*   Updated: 2023/11/29 22:14:17 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

std::string _name;

Zombie::Zombie(void) { return; }
Zombie::Zombie(std::string name) {
	_name = name;
	return;
};

Zombie::~Zombie() {
	std::cout << _name << " is dead" << std::endl;
	return;
};

void Zombie::announce(void) {
	std::cout << _name << ": ";
	std::cout << "BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(std::string name)
{
	this->_name = name;
}
