/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 22:36:12 by sde-cama          #+#    #+#             */
/*   Updated: 2023/11/22 23:19:06 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void) {
	Zombie	*zombie;

	zombie = newZombie("Heap");
	zombie->announce();
	randomChump("Stack");
	delete zombie;
	return (0);
}
