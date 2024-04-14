/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 22:33:52 by sde-cama          #+#    #+#             */
/*   Updated: 2024/04/14 14:13:16 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main()
{
	std::cout << "===Stack - Last in First out===" << std::endl;
	MutantStack<int> mStack;
	MutantStack<int>::iterator itB;
	MutantStack<int>::iterator itE;
	MutantStack<int>::reverse_iterator ritB;
	MutantStack<int>::reverse_iterator ritE;

	mStack.push(1);
	std::cout << "> Element on top of stack: ";
	std::cout << mStack.top() << std::endl;
	std::cout << "*Adding new element*" << std::endl;
	mStack.push(2);
	std::cout << "> Element on top of stack: ";
	std::cout << mStack.top() << std::endl;
	std::cout << "*Removing element from stack*" << std::endl;
	mStack.pop();
	std::cout << "> Element on top of stack: ";
	std::cout << mStack.top() << std::endl;
	std::cout << "*Adding 3 new elements*" << std::endl;
	mStack.push(3);
	mStack.push(4);
	mStack.push(5);

	std::cout << "> New Size: " << mStack.size() << std::endl;

	std::cout << "*Getting Begin and End*" << std::endl;
	itB = mStack.begin();
	itE = mStack.end();

	std::cout << "*Iterating through the Stack printing each element*" << std::endl;
	++itB;
	--itB;
	while (itB != itE)
	{
		std::cout << *itB << " ";
		++itB;
	}

	std::cout << "\n*Backwards iteration*" << std::endl;
	ritB = mStack.rbegin();
	ritE = mStack.rend();
	while (ritB != ritE)
	{
		std::cout << *ritB << " ";
		++ritB;
	}

	std::cout << std::endl
			  << std::endl
			  << "===Test with List for comparison===" << std::endl;
	std::list<int> list;
	std::list<int>::iterator itListB;
	std::list<int>::iterator itListE;
	std::list<int>::reverse_iterator ritListB;
	std::list<int>::reverse_iterator ritListE;

	list.push_back(1);
	std::cout << "> Element on back of list: ";
	std::cout << list.back() << std::endl;
	std::cout << "*Adding new element*" << std::endl;
	list.push_back(2);
	std::cout << "> Element on back of list: ";
	std::cout << list.back() << std::endl;
	std::cout << "*Removing element from list*" << std::endl;
	list.pop_back();
	std::cout << "> Element on back of list: ";
	std::cout << list.back() << std::endl;
	std::cout << "*Adding 3 new elements*" << std::endl;
	list.push_back(3);
	list.push_back(4);
	list.push_back(5);

	std::cout << "Size: " << list.size() << std::endl;

	std::cout << "*Getting Begin and End*" << std::endl;
	itListB = list.begin();
	itListE = list.end();

	std::cout << "*Iterating through the List printing each element*" << std::endl;
	while (itListB != itListE)
	{
		std::cout << *itListB << " ";
		++itListB;
	}

	std::cout << "\n*Backwards iteration*" << std::endl;
	ritListB = list.rbegin();
	ritListE = list.rend();
	while (ritListB != ritListE)
	{
		std::cout << *ritListB << " ";
		++ritListB;
	}
	std::list<int> l(list);
	std::cout << std::endl;

	return (0);
}