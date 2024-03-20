/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 21:16:20 by sde-cama          #+#    #+#             */
/*   Updated: 2024/03/20 00:20:53 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream> //std::cout, std::cerr
#include <stack>	//std::stack<int>
#include <cmath>	//atoi

/*
RPN has the property that brackets are not required to represent the order of evaluation or grouping of the terms. RPN expressions are simply evaluated from left to right and this greatly simplifies the computation of the expression within computer programs. As an example, the arithmetic expression (3+4)×5 can be expressed in RPN as 3 4 + 5 ×.

In practice RPN can be conveniently evaluated using a stack structure. Reading the expression from left to right, the following operations are performed:

1. If a value appears next in the expression, push this value on to the stack.

2. If an operator appears next, pop two items from the top of the stack and push the result of the operation on to the stack.

https://mathworld.wolfram.com/ReversePolishNotation.html
*/
class RPN
{
private:
	/*Stacks are a type of container adaptor, specifically designed to operate in a LIFO context (last-in first-out), where elements are inserted and extracted only from one end of the container.*/
	std::stack<int> _stack;

	/* Member Functions */
	void validateExperession(std::string expression);
	void printStack(void);
	void evaluateExpression(std::string expression);
	int calculate(int &templ, int &tempr, char op);

public:
	/* Orthodox Canonical Form methods */
	RPN(void);
	RPN(std::string expression);
	RPN(RPN const &src);
	RPN &operator=(RPN const &rhs);
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

	class NotEnoughOperators : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
};
#endif