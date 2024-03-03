/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 11:20:17 by sde-cama          #+#    #+#             */
/*   Updated: 2024/03/03 20:51:30 by sde-cama         ###   ########.fr       */
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

typedef AForm *(*t_form)(std::string const &target);

struct s_form
{
	std::string name;
	t_form form;
};