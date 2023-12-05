/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 21:44:29 by sde-cama          #+#    #+#             */
/*   Updated: 2023/12/04 23:29:34 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon() {	return; };
Weapon::Weapon(std::string type ) {
    _type = type;
    return;
};

Weapon::~Weapon() {	return; };

std::string const &Weapon::getType() {
	return _type;
};

void Weapon::setType(std::string type) {
	_type = type;
};
