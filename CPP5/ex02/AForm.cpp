/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 11:20:09 by sde-cama          #+#    #+#             */
/*   Updated: 2024/03/03 17:42:32 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

const char *AForm::GradeTooHighException::what(void) const throw()
{
	return "grade is too high";
}

const char *AForm::GradeTooLowException::what(void) const throw()
{
	return "grade is too low";
}

const char *AForm::FormNotSignedException::what(void) const throw()
{
	return "Form is not signed";
}

AForm::AForm(void) : _signatureGrade(150), _executionGrade(150)
{
	std::cout << "Default Constructor called" << std::endl;
	const_cast<std::string &>(this->_name) = "Undefined";
	this->_signed = false;

	return;
}

AForm::AForm(std::string const &name, int const &gradeSign, int const &gradeExec)
	: _signatureGrade(gradeSign), _executionGrade(gradeExec)
{
	std::cout << "Parameter Constructor called" << std::endl;
	const_cast<std::string &>(this->_name) = name;
	this->_signed = false;
	if (this->getSignatureGrade() > 150 || this->getExecutionGrade() > 150)
		throw AForm::GradeTooLowException();
	if (this->getSignatureGrade() < 1 || this->getExecutionGrade() < 1)
		throw AForm::GradeTooHighException();
	return;
}

AForm::AForm(AForm const &src) : _signatureGrade(src.getSignatureGrade()), _executionGrade(src.getExecutionGrade())
{
	std::cout << "Copy Constructor called" << std::endl;
	const_cast<std::string &>(this->_name) = src.getName();
	this->_signed = src.getSignature();
	return;
}

AForm::~AForm(void)
{
	std::cout << "Destructor called" << std::endl;
	return;
}

AForm &AForm::operator=(AForm const &rhs)
{
	std::cout << "Assignment operator called" << std::endl;
	if (this != &rhs)
	{
		const_cast<std::string &>(this->_name) = rhs.getName();
		const_cast<int &>(this->_signatureGrade) = rhs.getSignatureGrade();
		const_cast<int &>(this->_executionGrade) = rhs.getExecutionGrade();
		this->_signed = rhs.getSignature();
		const_cast<std::string &>(this->_target) = rhs.getTarget();
	}
	return (*this);
}

std::ostream &operator<<(std::ostream &o, AForm const &i)
{
	(void)i;
	o << "\n**Displaying AForm**" << std::endl;
	o << "Name: " << i.getName() << std::endl;
	o << "Signature Grade: " << i.getSignatureGrade() << std::endl;
	o << "Execution Grade: " << i.getExecutionGrade() << std::endl;
	o << "Is signed: " << (i.getSignature() ? "True" : "False") << std::endl;
	return (o);
}

// GETTERS
std::string AForm::getName(void) const
{
	return (this->_name);
}

int AForm::getSignatureGrade(void) const
{
	return (this->_signatureGrade);
}

int AForm::getExecutionGrade(void) const
{
	return (this->_executionGrade);
}

bool AForm::getSignature(void) const
{
	return (this->_signed);
}

std::string AForm::getTarget(void) const
{
	return (this->_target);
}

// SETTERS
void AForm::setName(std::string const name)
{
	const_cast<std::string &>(this->_name) = name;
}

void AForm::setSignature(bool const sign)
{
	const_cast<bool &>(this->_signed) = sign;
}

void AForm::setSignatureGrade(int const grade)
{
	const_cast<int &>(this->_signatureGrade) = grade;
}

void AForm::setExecutionGrade(int const grade)
{
	const_cast<int &>(this->_executionGrade) = grade;
}

void AForm::setTarget(std::string const target)
{
	const_cast<std::string &>(this->_target) = target;
}

// MEMBER FUNCTIONS
void AForm::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->getSignatureGrade())
		throw AForm::GradeTooLowException();
	else
		this->_signed = true;
}

void AForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > this->getExecutionGrade())
		throw AForm::GradeTooLowException();
	if (!this->getSignature())
		throw AForm::FormNotSignedException();
}
