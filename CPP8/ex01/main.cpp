/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 22:33:52 by sde-cama          #+#    #+#             */
/*   Updated: 2024/03/14 21:20:33 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

void	test10000(void);

int main()
{
	int array[] = {10, 2, 3, 9, 5, 8, 7, 4, 1, 6};
	std::list<int>::iterator resultList;

	std::list<int> list(array, array + sizeof(array) / sizeof(array[0]));
	Span span = Span(11);
	Span emptySpan = Span(2);

	try
	{
		std::cout << "\n**Adding range of elements**" << std::endl;
		span.addNumber(list.begin(), list.end());
		std::cout << "> List elements: ";
		std::cout << span << std::endl;

		std::cout << "\n**Adding single element '42'**" << std::endl;
		span.addNumber(42);
		std::cout << "> List elements: ";
		std::cout << span << std::endl;

		std::cout << "\n> Shortest Span: " << span.shortestSpan() << std::endl;
		std::cout << "\n> Longest Span: " << span.longestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::cout << "\n**Attempt to add new element on full array**" << std::endl;
		span.addNumber(43);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::cout << "\n**Attempt to get shortest span on empty list**" << std::endl;
		std::cout << "> List elements: ";
		std::cout << emptySpan << std::endl;
		std::cout << "\n> Shortest Span: " << emptySpan.shortestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	
	test10000();

	return (0);
}

void	test10000(void)
{
	std::cout << "\n**10000 elements test**" << std::endl;
	Span	sp(10000);
	std::list<int>	zeroes(10000, 0);
	
	try 
	{
		sp.addNumber(zeroes.begin(), zeroes.end());
		std::cout << sp << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	return ;
}