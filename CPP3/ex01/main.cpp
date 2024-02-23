/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 22:36:12 by sde-cama          #+#    #+#             */
/*   Updated: 2024/02/22 22:10:00 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void)
{
    ScavTrap voldemort("Voldemort");
    ScavTrap harry("Harry Potter");

	voldemort.attack("Harry Potter");
    
	harry.takeDamage(voldemort.getAttackDamage());
    harry.beRepaired(10);
    harry.attack("Voldemort");
    
    voldemort.takeDamage(harry.getAttackDamage());
    voldemort.attack("Harry Potter");
    
    harry.takeDamage(voldemort.getAttackDamage());
    harry.guardGate();
    harry.beRepaired(10);
    harry.attack("Voldemort");

    voldemort.takeDamage(harry.getAttackDamage());
    voldemort.beRepaired(5);

    return 0;
}
