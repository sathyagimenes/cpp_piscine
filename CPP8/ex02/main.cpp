/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 22:33:52 by sde-cama          #+#    #+#             */
/*   Updated: 2024/03/14 23:22:15 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main()
{
	std::cout << "Stack - Last in First out" << std::endl;
	MutantStack<int> mStack;
	MutantStack<int>::iterator itB;
	MutantStack<int>::iterator itE;

	mStack.push(30);
	std::cout << "> Element on top of stack: ";
	std::cout << mStack.top() << std::endl;
	std::cout << "*Adding new element*" << std::endl;
	mStack.push(25);
	std::cout << "> Element on top of stack: ";
	std::cout << mStack.top() << std::endl;
	std::cout << "*Removing element from stack*" << std::endl;
	mStack.pop();
	std::cout << "> Element on top of stack: ";
	std::cout << mStack.top() << std::endl;
	std::cout << "*Adding new elements*" << std::endl;
	mStack.push(53);
	mStack.push(10);
	mStack.push(3);

	std::cout << "> Size: " << mStack.size() << std::endl;

	std::cout << "*Getting Begin and End*" << std::endl;
	itB = mStack.begin();
	itE = mStack.end();

	std::cout << "*Iterating through de Stack*" << std::endl;
	++itB;
	--itB;
	while (itB != itE)
	{
		std::cout << *itB << " ";
		++itB;
	}
	std::stack<int> s(mStack);

	std::cout << std::endl
			  << std::endl
			  << "*List*" << std::endl;
	std::list<int> list;
	std::list<int>::iterator itListB;
	std::list<int>::iterator itListE;

	list.push_back(30);
	std::cout << "> Element on back of list: ";
	std::cout << list.back() << std::endl;
	std::cout << "*Adding new element*" << std::endl;
	list.push_back(25);
	std::cout << "> Element on back of list: ";
	std::cout << list.back() << std::endl;
	std::cout << "*Removing element from list*" << std::endl;
	list.pop_back();
	std::cout << "> Element on back of list: ";
	std::cout << list.back() << std::endl;
	std::cout << "*Adding new elements*" << std::endl;
	list.push_back(53);
	list.push_back(10);
	list.push_back(3);

	std::cout << "Size: " << list.size() << std::endl;

	std::cout << "*Getting Begin and End*" << std::endl;
	itListB = list.begin();
	itListE = list.end();

	std::cout << "*Iterating through de Stack*" << std::endl;
	while (itListB != itListE)
	{
		std::cout << *itListB << " ";
		++itListB;
	}
	std::list<int> l(list);
	std::cout << std::endl;

	return (0);
}