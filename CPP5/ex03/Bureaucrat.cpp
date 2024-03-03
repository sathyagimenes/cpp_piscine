/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 20:22:44 by sde-cama          #+#    #+#             */
/*   Updated: 2024/03/03 20:44:53 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return "Grade is too high, highest grade is 1";
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return "Grade is too low, lowest grade is 150";
}

Bureaucrat::Bureaucrat(void)
{
	std::cout << "Bureaucrat Default Constructor called" << std::endl;
	const_cast<std::string &>(this->_name) = "Undefined";
	this->_grade = 150;

	return;
}

Bureaucrat::Bureaucrat(std::string const &name, int grade)
{
	std::cout << "Bureaucrat Parameter Constructor called" << std::endl;
	const_cast<std::string &>(this->_name) = name;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = grade;
	return;
}

Bureaucrat::Bureaucrat(Bureaucrat const &src)
{
	std::cout << "Bureaucrat Copy Constructor called";
	const_cast<std::string &>(this->_name) = src.getName();
	this->_grade = src.getGrade();
	return;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Bureaucrat Destructor called" << std::endl;
	return;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhs)
{
	std::cout << "Bureaucrat Assignment operator called" << std::endl;
	if (this != &rhs)
	{
		const_cast<std::string &>(this->_name) = rhs.getName();
		this->_grade = rhs.getGrade();
	}
	return (*this);
}

std::ostream &operator<<(std::ostream &o, Bureaucrat const &i)
{
	(void)i;
	o << "**Displaying Bureaucrat**" << std::endl;
	o << "Name: " << i.getName() << std::endl;
	o << "Grade: " << i.getGrade() << std::endl;
	return (o);
}

int Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

std::string Bureaucrat::getName(void) const
{
	return (this->_name);
}

void Bureaucrat::decrementGrade(void)
{
	if (this->getGrade() == 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade++;
}

void Bureaucrat::incrementGrade(void)
{
	if (this->getGrade() == 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade--;
}

void Bureaucrat::signForm(AForm &form)
{
	if (form.getSignature())
		return;

	try
	{
		form.beSigned(*this);
		std::cout << this->getName() << " signed " << form.getName() << std::endl;
	}
	catch (AForm::GradeTooLowException &e)
	{
		std::cerr << this->getName() << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	}
	catch (AForm::GradeTooHighException &e)
	{
		std::cerr << this->getName() << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm const &form) const
{
	try
	{
		form.execute(*this);
		std::cout << this->getName() << " executed " << form.getName() << std::endl;
	}
	catch (AForm::GradeTooLowException &e)
	{
		std::cout << this->getName() << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
	}
}