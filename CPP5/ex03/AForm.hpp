/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 11:20:17 by sde-cama          #+#    #+#             */
/*   Updated: 2024/03/30 18:18:04 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	std::string const _name;
	bool _signed;
	int const _signatureGrade;
	int const _executionGrade;
	std::string const _target;

protected:
	void setName(std::string const name);
	void setSignature(bool const sign);
	void setSignatureGrade(int const grade);
	void setExecutionGrade(int const grade);
	void setTarget(std::string const target);

public:
	/* Orthodox Canonical AForm methods */
	AForm(void);
	AForm(std::string const &name, int const &gradeSign, int const &gradeExec);
	AForm(AForm const &src);
	AForm &operator=(AForm const &rhs);
	virtual ~AForm(void);

	/* Getters */
	std::string getName(void) const;
	bool getSignature(void) const;
	int getSignatureGrade(void) const;
	int getExecutionGrade(void) const;
	std::string getTarget(void) const;

	/* Member Functions */
	void beSigned(Bureaucrat &bureaucrat);
	virtual void execute(Bureaucrat const &executor) const = 0;

	/*
		By inheriting from and modifying the functionality of exception class,
		you may create your own exceptions.
		https://linuxhint.com/throw-cpp-exception/
	*/
	class GradeTooHighException : public std::exception
	{
	public:
		const char *what(void) const throw();
	};
	class GradeTooLowException : public std::exception
	{
	public:
		const char *what(void) const throw();
	};
	class FormNotSignedException : public std::exception
	{
	public:
		const char *what(void) const throw();
	};
	class	FormDoesntExistException : public std::exception
	{
		public:
			const char *what(void) const throw();
	};
};

std::ostream &operator<<(std::ostream &o, AForm const &i);

/*
This typedef named t_form defines a pointer to a function that takes a constant reference to a std::string named target as an argument and returns a pointer to an object of type AForm.
*/
typedef AForm *(*t_form)(std::string const &target);

/*
This defines a struct named s_form. It contains two members:
name: This is a std::string member variable.
form: This is a member variable of type t_form, which is the typedef we declared earlier. So, form is a function pointer that points to a function with the signature specified by t_form.
*/
struct s_form
{
	std::string name;
	t_form form;
};