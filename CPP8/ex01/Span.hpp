/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 18:28:33 by sde-cama          #+#    #+#             */
/*   Updated: 2024/04/14 14:12:57 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <exception>
#include <list>

class Span
{
	private:
		std::list<int> _list;
		unsigned int _n;

	public:
		/* Orthodox Canonical Form methods */
		Span(void);
		Span(unsigned int n);
		Span(Span const &src);
		~Span(void);

		/* Overload methods */
		Span &operator=(Span const &rhs);

		/* Member Functions */
		void addNumber(int number);
		void addNumber(std::list<int>::const_iterator itBegin, std::list<int>::const_iterator itEnd, unsigned int size);
		unsigned int shortestSpan();
		unsigned int longestSpan();
		const std::list<int> &getList(void) const;
};
std::ostream &operator<<(std::ostream &os, const Span &obj);

#endif