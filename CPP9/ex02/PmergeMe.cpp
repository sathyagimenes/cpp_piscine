/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 02:54:04 by sde-cama          #+#    #+#             */
/*   Updated: 2024/04/14 06:30:22 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int jacobsthal(int n)
{
	if (n == 0)
	{
		return 0;
	}

	if (n == 1)
	{
		return 1;
	}

	return jacobsthal(n - 1) + 2 * jacobsthal(n - 2);
}

void PmergeMe::merge(char **argv)
{
	_sortByList(argv);
	_sortByVector(argv);
}

void PmergeMe::_sortByList(char **argv)
{
	std::list<int> unsorted;
	std::list<int> sorted;

	clock_t start = clock();

	std::cout << GREEN << "[SORTING WITH: std::list]" << RESET << std::endl;

	for (int i = 1; argv[i]; i++)
	{
		unsorted.push_back(std::atoi(argv[i]));
	}

	std::cout << BLUE << "Before: " << RESET;
	printNumbers(unsorted);

	std::cout << BLUE << "After: " << RESET;
	sorted = sortedOrder(unsorted);
	printNumbers(sorted);

	clock_t end = clock();
	double duration = double(end - start) / CLOCKS_PER_SEC;

	std::cout << std::endl
			  << "Time to process a range of " << sorted.size()
			  << " elements with std::list: " << std::fixed
			  << std::setprecision(5) << duration << " µs" << RESET << std::endl;
}

void PmergeMe::_sortByVector(char **argv)
{
	std::vector<int> unsorted;
	std::vector<int> sorted;

	clock_t start = clock();

	std::cout << std::endl
			  << BLUE << "[SORTING WITH: std::vector]" << RESET << std::endl;

	for (int i = 1; argv[i]; i++)
	{
		unsorted.push_back(std::atoi(argv[i]));
	}

	std::cout << GREEN << "Before: " << RESET;
	printNumbers(unsorted);

	std::cout << GREEN << "After: " << RESET;
	sorted = sortedOrder(unsorted);
	printNumbers(sorted);

	clock_t end = clock();
	double duration = double(end - start) / CLOCKS_PER_SEC;

	std::cout << std::endl
			  << "Time to process a range of " << sorted.size()
			  << " elements with std::vector : " << std::fixed
			  << std::setprecision(5) << duration << " µs" << RESET << std::endl;
}
