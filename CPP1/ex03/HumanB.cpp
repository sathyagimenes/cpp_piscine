/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 22:18:32 by sde-cama          #+#    #+#             */
/*   Updated: 2023/12/05 00:15:45 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) {
	_name = name;
	return;
};

HumanB::~HumanB() {
	return;
};

void HumanB::setWeapon(Weapon &weapon) {
	_weapon = &weapon;
};

void HumanB::attack(void) {
	std::cout << _name << " attacks with their ";
	std::cout << _weapon->getType();
	std::cout << std::endl;
}
