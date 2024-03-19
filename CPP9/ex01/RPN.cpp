/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 21:16:13 by sde-cama          #+#    #+#             */
/*   Updated: 2024/03/19 00:45:53 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

const char *RPN::BadInputException::what(void) const throw()
{
	return ("Error: Bad input.");
}

const char *RPN::ZeroDivisionException::what(void) const throw()
{
	return ("Error: Invalid division by zero.");
}

RPN::RPN(void)
{
	// std::cout << "Default Constructor Called." << std::endl;
	return;
}

RPN::RPN(std::string expression)
{
	// std::cout << "RPN Parameter contructor called." << std::endl;
	initStack(expression);
	// printStack();
	evaluateExpression();
	return;
}

RPN::RPN(RPN const &src)
{
	// std::cout << "Copy Constructor Called." << std::endl;
	*this = src;
	return;
}

RPN::~RPN(void)
{
	// std::cout << "Destructor Called." << std::endl;
	return;
}

RPN &RPN::operator=(RPN const &rhs)
{
	std::cout << "Assignment Operator Called." << std::endl;
	(void)rhs;
	return (*this);
}

void RPN::initStack(std::string expression)
{
	std::string validElements;

	validElements = " +-*/0123456789";
	for (std::string::reverse_iterator it = expression.rbegin(); it != expression.rend(); it++)
	{
		if (validElements.find(*it) == std::string::npos)
			throw RPN::BadInputException();
		if (*it != ' ')
			_stack.push(*it);
	}
}

void RPN::printStack(void)
{
	std::stack<int> copyStack = _stack;

	while (!copyStack.empty())
	{
		std::cout << static_cast<char>(copyStack.top()) << std::endl;
		copyStack.pop();
	}
}

void RPN::evaluateExpression(void)
{
	int templ, tempr;

	templ = std::isdigit(_stack.top()) ? _stack.top() - '0' : throw BadInputException();
	tempr = -1;

	_stack.pop();
	while (!_stack.empty())
	{
		if (!std::isdigit(_stack.top()))
			calculate(templ, tempr, _stack.top());
		else if (tempr == -1)
			tempr = _stack.top() - '0';
		_stack.pop();
	}

	std::cout << templ << std::endl;
}

void RPN::calculate(int &templ, int &tempr, char op)
{
	std::cout << "templ: " << templ << " op: " << op << " tempr: " << tempr << std::endl;
	if (tempr < 0)
		return;

	switch (op)
	{
	case '+':
		templ += tempr;
		tempr = -1;
		break;
	case '-':
		templ -= tempr;
		tempr = -1;
		break;
	case '*':
		templ *= tempr;
		tempr = -1;
		break;
	case '/':
		if (tempr == 0)
			throw ZeroDivisionException();
		templ /= tempr;
		tempr = -1;
		break;
	default:
		throw RPN::BadInputException();
		break;
	}
}