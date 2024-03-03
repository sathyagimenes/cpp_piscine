/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 12:44:52 by sde-cama          #+#    #+#             */
/*   Updated: 2024/03/03 18:04:26 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

const char *ShrubberyCreationForm::FileCreateErrorException::what(void) const throw()
{
	return "Error, failed to create file.";
}

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("Shrubbery Creation Form", SCF_SIGN_GRADE, SCF_EXEC_GRADE)
{
	std::cout << "Default Constructor called" << std::endl;
	return;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src) : AForm(src)
{
	std::cout << "Copy Constructor called" << std::endl;
	this->setName(src.getName());
	this->setSignature(src.getSignature());
	this->setSignatureGrade(src.getSignatureGrade());
	this->setExecutionGrade(src.getExecutionGrade());
	this->setTarget(src.getTarget());
	return;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) : AForm("Shrubbery Creation Form", SCF_SIGN_GRADE, SCF_EXEC_GRADE)
{
	std::cout << "Parameter Constructor Called" << std::endl;
	this->setTarget(target);
	return;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << "Destructor called" << std::endl;
	return;
}


ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs)
{
	std::cout << "Assignment operator called" << std::endl;
	if (this != &rhs)
	{
		this->setName(rhs.getName());
		this->setSignature(rhs.getSignature());
		this->setSignatureGrade(rhs.getSignatureGrade());
		this->setExecutionGrade(rhs.getExecutionGrade());
		this->setTarget(rhs.getTarget());
	}
	return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	std::string filename;
	std::ofstream outfile;
	AForm::execute(executor);

	filename = this->getTarget() + "_shrubbery";
	std::ofstream out(filename.c_str());
	if (!out.is_open() || out.fail())
		throw ShrubberyCreationForm::FileCreateErrorException();
	outfile.open(filename.c_str());
	outfile << SHRUBBERY;
	std::cout << filename << " created with success." << std::endl;
	outfile.close();
	out.close();
}