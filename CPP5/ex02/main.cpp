/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 09:51:08 by sde-cama          #+#    #+#             */
/*   Updated: 2024/03/03 18:33:08 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

int main(void)
{
	std::cout << "\n**Form Constructors**" << std::endl;
	ShrubberyCreationForm shrubbery("tree");
	Bureaucrat b1("Zaphod 1", 137);

	RobotomyRequestForm robotomy("Marvin");
	Bureaucrat b2("Zaphod 2", 46);

	PresidentialPardonForm presidential("Marvin");
	Bureaucrat b3("Zaphod 3", 6);

	try
	{
		std::cout << "\n**1 - Signing ShrubberyCreation form**" << std::endl;
		std::cout << "\n**1.1 - No signature/Failure on execution**" << std::endl;
		b1.executeForm(shrubbery);
		std::cout << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::cout << "\n**1.1 - Success on signature/Failure on execution**" << std::endl;
		b1.decrementGrade();
		b1.signForm(shrubbery);
		b1.executeForm(shrubbery);
		std::cout << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n**1.3 - Success on signature/Success on execution**" << std::endl;
	b1.incrementGrade();
	b1.signForm(shrubbery);
	b1.executeForm(shrubbery);

	/* RobotomyRequestForm testing simple */
	try
	{
		std::cout << "\n**2 - Signing RobotomyRequest form**" << std::endl;
		std::cout << "\n**2.1 - Failure on signature/Failure on execution**" << std::endl;
		b2.signForm(robotomy);
		b2.executeForm(robotomy);
		std::cout << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "\n**2.2 - Success on signature/Success on execution**" << std::endl;
	b2.incrementGrade();
	b2.signForm(robotomy);
	b2.executeForm(robotomy);

	try
	{
		std::cout << "\n**3 - Signing Presidential form**" << std::endl;
		std::cout << "\n**3.1 - Failure on signature/Failure on execution**" << std::endl;
		b3.signForm(presidential);
		b3.executeForm(presidential);
		std::cout << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "\n**3.2 - Success on signature/Success on execution**" << std::endl;
	b3.incrementGrade();
	b3.signForm(presidential);
	b3.executeForm(presidential);

	std::cout << "\n**Form Destructors**" << std::endl;
	return (0);
}