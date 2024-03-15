/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 20:40:20 by sde-cama          #+#    #+#             */
/*   Updated: 2024/03/14 21:10:12 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(void) : _n(1)
{
	std::cout << "Default Constructor called" << std::endl;
	return;
}

Span::Span(unsigned int n) : _n(n)
{
	std::cout << "Parameter Constructor called" << std::endl;
	return;
}

Span::Span(Span const &src)
{
	std::cout << "Copy Constructor called";
	*this = src;
	return;
}

Span::~Span(void)
{
	std::cout << "Destructor called" << std::endl;
	return;
}

Span &Span::operator=(Span const &rhs)
{
	std::cout << "Assignment operator called" << std::endl;
	if (this != &rhs)
	{
		this->_n = rhs._n;
		this->_list = rhs._list;
	}
	return (*this);
}

std::ostream &operator<<(std::ostream &os, const Span &obj)
{
	std::list<int>::const_iterator it;
	for (it = obj.getList().begin(); it != obj.getList().end(); ++it)
		os << *it << " ";
	return (os);
}

const std::list<int> &Span::getList(void) const
{
	return (this->_list);
}

void Span::addNumber(int number)
{
	if (this->_list.size() >= this->_n)
		throw std::out_of_range("Span is full");
	this->_list.push_back(number);
}

void Span::addNumber(std::list<int>::const_iterator begin, std::list<int>::const_iterator end)
{
	while (begin != end)
	{
		if (this->_list.size() >= this->_n)
			throw(std::out_of_range("Span is full"));
		this->_list.push_back(*begin);
		begin++;
	}
}

unsigned int Span::shortestSpan(void)
{
	if (this->_list.size() < 2)
		throw std::out_of_range("Span is empty");

	std::list<int>::const_iterator it = this->_list.begin();
	std::list<int>::const_iterator previous = it;
	it++;
	unsigned int min = std::abs(*it - *previous);
	for (; it != this->_list.end(); it++)
	{
		if (std::abs(*it - *previous) < static_cast<int>(min))
			min = static_cast<unsigned int>(std::abs(*it - *previous));
		previous++;
	}
	return (min);
}

unsigned int Span::longestSpan(void)
{
	if (this->_list.size() < 2)
		throw(std::out_of_range("Span is empty"));
	unsigned int max = *std::max_element(this->_list.begin(), this->_list.end());
	unsigned int min = *std::min_element(this->_list.begin(), this->_list.end());
	return (max - min);
}