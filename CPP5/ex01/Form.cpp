/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:29:23 by sde-cama          #+#    #+#             */
/*   Updated: 2024/03/01 21:46:09 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

const char *Form::GradeTooHighException::what(void) const throw()
{
	return "grade is too high";
}

const char *Form::GradeTooLowException::what(void) const throw()
{
	return "grade is too low";
}

Form::Form(void) : _signatureGrade(150), _executionGrade(150)
{
	std::cout << "Default Constructor called" << std::endl;
	const_cast<std::string &>(this->_name) = "Undefined";
	this->_signed = false;

	return;
}

Form::Form(std::string const &name, int const &gradeSign, int const &gradeExec)
	: _signatureGrade(gradeSign), _executionGrade(gradeExec)
{
	std::cout << "Parameter Constructor called" << std::endl;
	const_cast<std::string &>(this->_name) = name;
	this->_signed = false;
	if (this->getSignatureGrade() > 150 || this->getExecutionGrade() > 150)
		throw Form::GradeTooLowException();
	if (this->getSignatureGrade() < 1 || this->getExecutionGrade() < 1)
		throw Form::GradeTooHighException();
	return;
}

Form::Form(Form const &src) : _signatureGrade(src.getSignatureGrade()), _executionGrade(src.getExecutionGrade())
{
	std::cout << "Copy Constructor called" << std::endl;
	const_cast<std::string &>(this->_name) = src.getName();
	this->_signed = src.getSignature();
	return;
}

Form::~Form(void)
{
	std::cout << "Destructor called" << std::endl;
	return;
}

Form &Form::operator=(Form const &rhs)
{
	std::cout << "Assignment operator called" << std::endl;
	if (this != &rhs)
	{
		const_cast<std::string &>(this->_name) = rhs.getName();
		const_cast<int &>(this->_signatureGrade) = rhs.getSignatureGrade();
		const_cast<int &>(this->_executionGrade) = rhs.getExecutionGrade();
		this->_signed = rhs.getSignature();
	}
	return (*this);
}

std::ostream &operator<<(std::ostream &o, Form const &i)
{
	(void)i;
	o << "\n**Displaying Form**" << std::endl;
	o << "Name: " << i.getName() << std::endl;
	o << "Signature Grade: " << i.getSignatureGrade() << std::endl;
	o << "Execution Grade: " << i.getExecutionGrade() << std::endl;
	o << "Is signed: " << (i.getSignature() ? "True" : "False") << std::endl;
	return (o);
}

std::string Form::getName(void) const
{
	return (this->_name);
}

int Form::getSignatureGrade(void) const
{
	return (this->_signatureGrade);
}

int Form::getExecutionGrade(void) const
{
	return (this->_executionGrade);
}

bool Form::getSignature(void) const
{
	return (this->_signed);
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->getSignatureGrade())
		throw Form::GradeTooLowException();
	else
		this->_signed = true;
}