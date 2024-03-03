/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 20:35:05 by sde-cama          #+#    #+#             */
/*   Updated: 2024/03/03 20:45:24 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void)
{
	std::cout << "Intern Default Constructor called" << std::endl;
	return ;
}

Intern::Intern(Intern const &src)
{
	std::cout << "Intern Copy Constructor called" << std::endl;
	(void)src;
	return ;
}

Intern::~Intern(void)
{
	std::cout << "Intern Destructor called" << std::endl;
	return ;
}

Intern & Intern::operator = (Intern const &rhs)
{
	std::cout << "Intern Assignment operator called" << std::endl;
	(void)rhs;
	return (*this);
}

AForm *Intern::makeForm(std::string formName, std::string target)
{
	t_form	form = NULL;
	
	static	s_form formOptions[3] = 
	{
		{"shrubbery creation", &ShrubberyCreationForm::create},
		{"robotomy request", &RobotomyRequestForm::create},
		{"presidential pardon", &PresidentialPardonForm::create},
	};

	for (int i = 0; i < 3; i++)
	{
		if (formOptions[i].name == formName)
		{
			form = formOptions[i].form;
			break ;
		}
	}

	if (!form)
		throw AForm::FormDoesntExistException();

	std::cout << "Intern created " << formName << " form" << std::endl;
	return (form(target));
}