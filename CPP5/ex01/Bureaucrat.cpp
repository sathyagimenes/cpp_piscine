/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 20:22:44 by sde-cama          #+#    #+#             */
/*   Updated: 2024/03/01 20:53:12 by sde-cama         ###   ########.fr       */
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
	std::cout << "Default Constructor called" << std::endl;
	const_cast<std::string &>(this->_name) = "Undefined";
	/*
		Sometimes, you have a const variable and you really want to pass it into a function that you are certain won't modify it. But that function doesn't declare its argument as const
		Fortunately, if you know that you are safe in passing a const variable into a function that
		doesn't explicitly indicate that it will not change the data, then you can use a const_cast
		in order to temporarily strip away the const-ness of the object.
		Const casts look like regular typecasts in C++, except that they can only be used for casting away constness but not converting between types or casting down a class hierarchy.
		const_cast<type>(x)

		https://www.cprogramming.com/tutorial/const_correctness.html
	*/
	this->_grade = 150;
	/*
		The ‘this’ pointer is passed as a hidden argument to all nonstatic member function calls
		and is available as a local variable within the body of all nonstatic functions. ‘this’
		pointer is not available in static member functions as static member functions can be
		called without any object (with class name). Even if only one member of each function
		exists which is used by multiple objects, the compiler supplies an implicit pointer along
		with the names of the functions as ‘this’.
		https://www.geeksforgeeks.org/pointers-and-references-in-c/?ref=lbp
	*/
	return;
}

Bureaucrat::Bureaucrat(std::string const &name, int grade)
{
	std::cout << "Parameter Constructor called" << std::endl;
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
	std::cout << "Copy Constructor called";
	const_cast<std::string &>(this->_name) = src.getName();
	this->_grade = src.getGrade();
	return;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Destructor called" << std::endl;
	return;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhs)
{
	std::cout << "Assignment operator called" << std::endl;
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

void Bureaucrat::signForm(Form &form)
{
	if (form.getSignature())
		return;

	try
	{
		form.beSigned(*this);
		std::cout << this->getName() << " signed " << form.getName();
	}
	catch (Form::GradeTooLowException &e)
	{
		std::cerr << this->getName() << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	}
	catch (Form::GradeTooHighException &e)
	{
		std::cerr << this->getName() << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	}
}