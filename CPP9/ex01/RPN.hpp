/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 21:16:20 by sde-cama          #+#    #+#             */
/*   Updated: 2024/03/18 23:50:46 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>	//std::cout, std::cerr
#include <stack>	//std::stack<int>

/*
The Reverse Polish Notation (RPN) refers to the mathematical notation where the 
operands (numerical values) are written first, followed by the operators. The 
main aim of this notation is to eliminate ambiguity, simplify evaluation, 
efficient memory utilization, and reduce parsing complexity.

https://www.wallstreetmojo.com/reverse-polish-notation/
*/

class RPN
{
	private:
		/*Stacks are a type of container adaptor, specifically designed to operate in a LIFO context (last-in first-out), where elements are inserted and extracted only from one end of the container.*/
		std::stack<int>	_stack;

		/* Member Functions */
		void	initStack(std::string expression);
		void	printStack(void);
		void	evaluateExpression(void);
		void	calculate(int &templ, int &tempr, char op);

	public:
		/* Orthodox Canonical Form methods */
		RPN(void);
		RPN(std::string expression);
		RPN(RPN const &src);
		RPN &operator = (RPN const &rhs);
		~RPN(void);

		/* Exceptions */
		class BadInputException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class ZeroDivisionException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};
#endif