/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 22:33:52 by sde-cama          #+#    #+#             */
/*   Updated: 2024/04/14 14:12:12 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Easyfind.hpp"

int main()
{
	int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	std::vector<int>::iterator resultVector;
	std::list<int>::iterator resultList;

	std::vector<int> vect(array, array + sizeof(array) / sizeof(array[0]));
	std::list<int> list(array, array + sizeof(array) / sizeof(array[0]));

	try
	{
		std::cout << "**Searching for '1' in a Vector**" << std::endl;
		resultVector = easyfind(vect, 1);
		std::cout << "Found: " << *resultVector << std::endl;
		std::cout << "**Searching for '5' in a List**" << std::endl;
		resultList = easyfind(list, 5);
		std::cout << "Found: " << *resultList << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::cout << "**Searching for 'unexisting value (0)' in a Vector**" << std::endl;
		resultVector = easyfind(vect, 0);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::cout << "**Searching for 'unexisting value (100)' in a List**" << std::endl;
		resultList = easyfind(list, 100);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	return (0);
}