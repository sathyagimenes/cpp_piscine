/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 23:05:56 by sde-cama          #+#    #+#             */
/*   Updated: 2024/02/25 23:46:50 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BRAIN_H__
#define __BRAIN_H__

#include <iostream>

class Brain
{
	private:
		std::string _ideas[100];

	public:
		/* Orthodox Canonical Form methods*/
		Brain(void);
		Brain(Brain const &copy);
		Brain &operator=(Brain const &rhs);
		~Brain(void);

		/* Getters */
		std::string getIdea(size_t i) const;

		/* Setters */
		void setIdea(size_t i, std::string idea);
};

#endif