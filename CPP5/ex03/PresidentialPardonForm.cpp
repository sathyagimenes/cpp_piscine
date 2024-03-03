/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 11:20:17 by sde-cama          #+#    #+#             */
/*   Updated: 2024/03/03 20:43:21 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("Presidential Pardon Form", PPF_SIGN_GRADE, PPF_EXEC_GRADE)
{
	std::cout << "PresidentialPardonForm Default Constructor called" << std::endl;
	return;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src) : AForm(src)
{
	std::cout << "PresidentialPardonForm Copy Constructor called" << std::endl;
	this->setName(src.getName());
	this->setSignature(src.getSignature());
	this->setSignatureGrade(src.getSignatureGrade());
	this->setExecutionGrade(src.getExecutionGrade());
	this->setTarget(src.getTarget());
	return;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const &target) : AForm("Presidential Pardon Form", PPF_SIGN_GRADE, PPF_EXEC_GRADE)
{
	std::cout << "PresidentialPardonForm Parameter Constructor called" << std::endl;
	this->setTarget(target);
	return;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << "PresidentialPardonFormDestructor called" << std::endl;
	return;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs)
{
	std::cout << "PresidentialPardonForm Assignment operator called" << std::endl;
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

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	AForm::execute(executor);
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

AForm	*PresidentialPardonForm::create(std::string const &target)
{
	return (new PresidentialPardonForm(target));
}