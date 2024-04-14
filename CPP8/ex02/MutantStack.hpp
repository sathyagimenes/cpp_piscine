/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 18:28:33 by sde-cama          #+#    #+#             */
/*   Updated: 2024/04/14 14:13:29 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <algorithm>
#include <exception>
#include <stack>
#include <list>
#include <deque>

template <typename T, class Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
	public:
		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
		typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;

		MutantStack(void)
		{
			std::cout << "Default Constructor called" << std::endl;
			return;
		};
		MutantStack(MutantStack const &src)
		{
			std::cout << "Copy Constructor called";
			*this = src;
			return;
		};
		~MutantStack(void)
		{
			std::cout << "Destructor called" << std::endl;
			return;
		};

		MutantStack &operator=(MutantStack const &rhs)
		{
			std::cout << "Assignment operator called" << std::endl;
			if (this != &rhs)
			{
				this->_n = rhs._n;
				this->_list = rhs._list;
			}
			return (*this);
		};

		iterator begin(void)
		{
			return (this->c.begin());
		};
		iterator end(void)
		{
			return (this->c.end());
		};

		reverse_iterator rbegin(void)
		{
			return (this->c.rbegin());
		};
		reverse_iterator rend(void)
		{
			return (this->c.rend());
		};

		const_reverse_iterator crbegin(void)
		{
			return (this->c.crbegin());
		};
		const_reverse_iterator crend(void)
		{
			return (this->c.crend());
		};

		const_iterator cbegin(void)
		{
			return (this->c.cbegin());
		};
		const_iterator cend(void)
		{
			return (this->c.cend());
		};
};

#endif