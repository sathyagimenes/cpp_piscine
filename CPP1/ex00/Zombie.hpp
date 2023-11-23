/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 22:19:51 by sde-cama          #+#    #+#             */
/*   Updated: 2023/11/22 23:13:14 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

# include <string>
# include <iostream>

class Zombie {
	private:
		std::string _name;

	public:
		Zombie(std::string);
		~Zombie(void);
		void announce(void);
};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

#endif
