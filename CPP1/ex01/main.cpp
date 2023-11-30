/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 22:36:12 by sde-cama          #+#    #+#             */
/*   Updated: 2023/11/29 22:20:06 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void) {
	int hordeSize = 10;
    Zombie *horde = zombieHorde(hordeSize, "Zé");

    for (int i = 0; i < hordeSize; i++) {
        horde[i].announce();
    }

    delete[] horde;
}
