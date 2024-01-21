/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 22:36:12 by sde-cama          #+#    #+#             */
/*   Updated: 2024/01/21 18:11:50 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap harry("Harry Potter");
    ClapTrap voldemort("Voldemort");
	harry.setAttackDamage(5);
	voldemort.setAttackDamage(3);

	voldemort.attack("Harry Potter");
    
	harry.takeDamage(voldemort.getAttackDamage());
    harry.beRepaired(1);
    harry.attack("Voldemort");
    
    voldemort.takeDamage(harry.getAttackDamage());
    voldemort.attack("Harry Potter");
    
    harry.takeDamage(voldemort.getAttackDamage());
    harry.beRepaired(1);
    harry.attack("Voldemort");

    voldemort.takeDamage(harry.getAttackDamage());
    voldemort.beRepaired(5);

    return 0;
}
