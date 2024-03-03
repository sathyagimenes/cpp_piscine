/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 11:20:17 by sde-cama          #+#    #+#             */
/*   Updated: 2024/03/03 20:42:31 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("Robotomy Request Form", RRF_SIGN_GRADE, RRF_EXEC_GRADE)
{
	std::cout << "RobotomyRequestForm Default Constructor called" << std::endl;
	return;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src) : AForm(src)
{
	std::cout << "RobotomyRequestForm Copy Constructor called" << std::endl;
	this->setName(src.getName());
	this->setSignature(src.getSignature());
	this->setSignatureGrade(src.getSignatureGrade());
	this->setExecutionGrade(src.getExecutionGrade());
	this->setTarget(src.getTarget());
	return;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target) : AForm("Robotomy Request Form", RRF_SIGN_GRADE, RRF_EXEC_GRADE)
{
	std::cout << "RobotomyRequestForm Parameter Constructor called" << std::endl;
	this->setTarget(target);
	return;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << "RobotomyRequestForm Destructor called" << std::endl;
	return;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs)
{
	std::cout << "RobotomyRequestForm Assignment operator called" << std::endl;
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

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	AForm::execute(executor);
	std::cout << "* Drilling noises *" << std::endl;
	
	/*
		srand() gives the random function a new seed, a starting point (usually random numbers are calculated by taking the previous number (or the seed) and then do many operations on that number to generate the next).
		time(0) gives the time in seconds since the Unix epoch, which is a pretty good "unpredictable" seed (you're guaranteed your seed will be the same only once, unless you start your program multiple times within the same second).
	*/
	std::srand(std::time(0));
	if (std::rand() % 2)
	{
		std::cout << this->getTarget() << " has been robotomized successfully." << std::endl;
	}
	else
		std::cout << "Robotomization failed on " << this->getTarget() << std::endl;
}

AForm	*RobotomyRequestForm::create(std::string const &target)
{
	return (new RobotomyRequestForm(target));
}