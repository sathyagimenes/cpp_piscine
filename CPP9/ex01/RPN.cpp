/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 21:16:13 by sde-cama          #+#    #+#             */
/*   Updated: 2024/03/20 00:26:57 by sde-cama         ###   ########.fr       */
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

const char *RPN::NotEnoughOperators::what(void) const throw()
{
	return ("Error: not enough operators");
}

RPN::RPN(void)
{
	return;
}

RPN::RPN(std::string expression)
{
	validateExperession(expression);
	// printStack();
	evaluateExpression(expression);
	return;
}

RPN::RPN(RPN const &src)
{
	*this = src;
	return;
}

RPN::~RPN(void)
{
	return;
}

RPN &RPN::operator=(RPN const &rhs)
{
	(void)rhs;
	return (*this);
}

void RPN::validateExperession(std::string expression)
{
	std::string validElements;

	validElements = " +-*/0123456789";
	for (std::string::iterator it = expression.begin(); it != expression.end(); it++)
	{
		if (validElements.find(*it) == std::string::npos)
			throw RPN::BadInputException();
	}
}

void RPN::printStack(void)
{
	std::stack<int> copyStack = _stack;

	while (!copyStack.empty())
	{
		std::cout << static_cast<char>(copyStack.top()) << " ";
		copyStack.pop();
	}
	std::cout << std::endl;
}

void RPN::evaluateExpression(std::string expression)
{
	int	temp;

	for (int i = 0; expression[i]; i++)
	{
		if (expression[i] >= '0' && expression[i] <= '9')
		{
			this->_stack.push(atoi(std::string(1, expression[i]).c_str()));
			if (expression[i + 1] != ' ')
				throw RPN::BadInputException();
		}
		else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/')
		{
			if (this->_stack.size() < 2)
				throw std::invalid_argument("Error: input");
			temp = this->_stack.top();
			this->_stack.pop();
			temp = calculate(this->_stack.top(), temp, expression[i]);
			this->_stack.pop();
			this->_stack.push(temp);
		}
		else
			continue;
	}

	//print result
	if (this->_stack.size() == 1)
		std::cout << this->_stack.top() << std::endl;
	else
		throw RPN::NotEnoughOperators();
}

int RPN::calculate(int &value1, int &value2, char op)
{
	// std::cout << " " << value1 << " " << op << " " << value2;
	switch (op)
	{
	case '+':
		value1 += value2;
		break;
	case '-':
		value1 -= value2;
		break;
	case '*':
		value1 *= value2;
		break;
	case '/':
		if (value2 == 0)
			throw ZeroDivisionException();
		value1 /= value2;
		break;
	default:
		throw RPN::BadInputException();
		break;
	}
	// std::cout << " = " << value1 << std::endl;
	return value1;
}