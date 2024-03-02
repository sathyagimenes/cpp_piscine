/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 21:26:39 by sde-cama          #+#    #+#             */
/*   Updated: 2024/03/01 21:46:36 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	std::string const _name;
	bool _signed;
	int const _signatureGrade;
	int const _executionGrade;

public:
	/* Orthodox Canonical Form methods */
	Form(void);
	Form(std::string const &name, int const &gradeSign, int const &gradeExec);
	Form(Form const &src);
	Form &operator=(Form const &rhs);
	~Form(void);

	/* Getters */
	std::string getName(void) const;
	bool getSignature(void) const;
	int getSignatureGrade(void) const;
	int getExecutionGrade(void) const;
	
	/* Member Functions */
	void beSigned(Bureaucrat &bureaucrat);

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
};

std::ostream &operator<<(std::ostream &o, Form const &i);