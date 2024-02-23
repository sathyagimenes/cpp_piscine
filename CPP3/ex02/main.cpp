/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 22:36:12 by sde-cama          #+#    #+#             */
/*   Updated: 2024/02/22 22:45:22 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main(void)
{
    FragTrap weasley("Ron Weasley");
    FragTrap harry("Harry Potter");

	weasley.attack("Harry Potter");
    
	harry.takeDamage(weasley.getAttackDamage());
    harry.beRepaired(10);
    harry.attack("Ron Weasley");
    
    weasley.takeDamage(harry.getAttackDamage());
    weasley.attack("Harry Potter");
    
    harry.takeDamage(weasley.getAttackDamage());
    harry.beRepaired(10);
    harry.attack("Ron Weasley");

    weasley.takeDamage(harry.getAttackDamage());
    weasley.beRepaired(5);
    harry.highFivesGuy();

    return 0;
}
