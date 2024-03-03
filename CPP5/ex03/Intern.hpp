/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 20:35:05 by sde-cama          #+#    #+#             */
/*   Updated: 2024/03/03 18:52:08 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	public:
		/* Orthodox Canonical Form Methods */
		Intern(void);
		Intern(Intern const &src);
		Intern & operator = (Intern const &rhs);
		~Intern(void);

		AForm	*makeForm(std::string formName, std::string target);
};