/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 11:20:17 by sde-cama          #+#    #+#             */
/*   Updated: 2024/03/03 19:28:23 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include <cstdlib> //std::rand(); std::srand()
#include <ctime>   //std::time();

#define RRF_SIGN_GRADE 72
#define RRF_EXEC_GRADE 45

class RobotomyRequestForm : public AForm
{
public:
	/* Orthodox Canonical Form Methods */
	RobotomyRequestForm(void);
	RobotomyRequestForm(RobotomyRequestForm const &src);
	RobotomyRequestForm(std::string const &target);
	RobotomyRequestForm &operator=(RobotomyRequestForm const &rhs);
	~RobotomyRequestForm(void);

	/* Member Function */
	void execute(Bureaucrat const &executor) const;
	static AForm	*create(std::string const &target);
};