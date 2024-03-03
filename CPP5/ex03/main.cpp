/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 09:51:08 by sde-cama          #+#    #+#             */
/*   Updated: 2024/03/03 20:54:02 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"

void testForms(std::string formName, std::string target)
{
	std::cout << "\nCreating Form " << formName << ", using target: " << target << std::endl;
	Intern intern;
	Bureaucrat bureaucrat("Bureaucrat", 1);
	AForm *form;

	try
	{
		form = intern.makeForm(formName, target);
		bureaucrat.signForm(*form);
		bureaucrat.executeForm(*form);
		delete form;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	return;
}

int main(void)
{
	std::string const shrubberyForm = "shrubbery creation";
	std::string const robotomyForm = "robotomy request";
	std::string const presidentialForm = "presidential pardon";

	testForms(shrubberyForm, "tree");
	testForms(robotomyForm, "Bender");
	testForms(presidentialForm, "Marvin");
	testForms("Undefined", "Marvin");
	testForms("", "");
	return (0);
}