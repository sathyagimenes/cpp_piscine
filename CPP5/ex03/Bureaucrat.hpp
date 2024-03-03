/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 20:35:05 by sde-cama          #+#    #+#             */
/*   Updated: 2024/03/02 11:59:54 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
private:
	std::string const _name;
	int _grade;

public:
	/* Orthodox Canonical AForm methods */
	Bureaucrat(void);
	Bureaucrat(std::string const &name, int grade);
	Bureaucrat(Bureaucrat const &src);
	Bureaucrat &operator=(Bureaucrat const &rhs);
	~Bureaucrat(void);

	/* Member Functions */
	int getGrade(void) const;
	std::string getName(void) const;
	void decrementGrade(void);
	void incrementGrade(void);
	void signForm(AForm &form);
	void executeForm(AForm const &form) const;

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

std::ostream &operator<<(std::ostream &o, Bureaucrat const &i);