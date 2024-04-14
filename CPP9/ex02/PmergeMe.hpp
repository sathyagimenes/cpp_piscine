/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 02:53:52 by sde-cama          #+#    #+#             */
/*   Updated: 2024/04/14 06:31:51 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <algorithm>
#include <ctime>
#include <iomanip>

#define RESET "\033[0m"
#define BLACK "\033[30m" /* Black */
#define RED "\033[31m"	 /* Red */
#define GREEN "\033[32m" /* Green */
#define BLUE "\033[34m"	 /* Blue */

class PmergeMe
{
public:
	void merge(char **argv);

private:
	void _sortByList(char **argv);
	void _sortByVector(char **argv);
};

int jacobsthal(int n);

template <typename T>
void printNumbers(const T &container)
{
	typename T::const_iterator it;

	for (it = container.begin(); it != container.end(); it++)
	{
		std::cout << *it << " ";
	}

	std::cout << std::endl;
}

/// @brief Determina a ordem de inserção de acordo com a sequencia de jacobsthal
/// @tparam T tipo do container
/// @param listSize Tamanho da lista
/// @return Sequencia
template <typename T>
T insertionOrder(size_t listSize)
{
	T jacobsthalSequence;
	T sequence;
	size_t jacobsthalNumber;
	size_t indexOutOfJacobsthal;
	size_t lastJacobsthalNumber;

	if (listSize < 1)
	{
		return sequence;
	}

	jacobsthalNumber = 2;
	int nextJacobsthalNumber = jacobsthal(jacobsthalNumber++);

	// Gera a sequencia de jacobsthal
	while (nextJacobsthalNumber <= static_cast<int>(listSize))
	{
		jacobsthalSequence.push_back(nextJacobsthalNumber);
		nextJacobsthalNumber = jacobsthal(jacobsthalNumber++);
	}

	lastJacobsthalNumber = 1;
	jacobsthalNumber = 1;

	// insere os index anteriores que não são jacobsthal logo após o jacobsthal
	for (typename T::iterator it = jacobsthalSequence.begin(); it != jacobsthalSequence.end(); ++it)
	{
		jacobsthalNumber = *it;

		sequence.push_back(jacobsthalNumber);

		indexOutOfJacobsthal = jacobsthalNumber - 1;
		while (indexOutOfJacobsthal > lastJacobsthalNumber)
		{
			sequence.push_back(indexOutOfJacobsthal);
			indexOutOfJacobsthal--;
		}
		lastJacobsthalNumber = jacobsthalNumber;
	}
	// adiciona numeros posteriores que não são jacobsthal
	while (jacobsthalNumber++ < listSize)
	{
		sequence.push_back(jacobsthalNumber);
	}

	return sequence;
}

/// @brief Recursivamente ordena os n/2 maiores elementos de cada par
/// @tparam T Tipo container
/// @param pairs Lista de pares
/// @param size Tamanho da lista
template <typename T>
void sortedPairs(T &pairs, size_t size)
{
	if (size < 2)
	{
		return;
	}

	T left;
	T right;

	typename T::iterator it = pairs.begin();
	for (size_t i = 0; i < size / 2; i++)
	{
		left.push_back(*it++);
	}

	for (size_t i = size / 2; i < size; i++)
	{
		right.push_back(*it++);
	}

	pairs.clear();

	sortedPairs(left, left.size());
	sortedPairs(right, right.size());

	// Compara os pares e ordena ate que uma lista esteja vazia.
	while (!right.empty() && !left.empty())
	{
		if (left.front().first < right.front().first)
		{
			// Se o par estiver ordenado então adiciona o par na lista de pares
			// a ideia é sempre ordenar o par pelo primeiro elemento. [(5, 3), (12, 1)]
			// o outro par continua na lista left ou right para comparar com o seguinte par
			pairs.push_back(left.front());
			left.erase(left.begin());
		}
		else
		{
			pairs.push_back(right.front());
			right.erase(right.begin());
		}
	}

	// Acontece quando a lista da esquerda é maior que a lista da direita e não tem como comparar.
	while (!left.empty())
	{
		pairs.push_back(left.front());
		left.erase(left.begin());
	}

	while (!right.empty())
	{
		pairs.push_back(right.front());
		right.erase(right.begin());
	}
}

/// @brief Ordena o container
/// @tparam T Tipo do container
/// @param sequence Container
/// @return Retorna lista ordenada
template <typename T>
T sortedOrder(T &sequence)
{
	int stragglers = -1;

	if (sequence.size() < 2)
	{
		return sequence;
	}

	// se a lista for de tamanho impar, separa o ultimo elemento
	if (sequence.size() % 2 != 0)
	{
		stragglers = sequence.back();
		sequence.pop_back();
	}

	std::list<std::pair<int, int> > pairs;

	// popula lista de pares, colocando o maior na frente
	for (typename T::iterator it = sequence.begin(); it != sequence.end(); ++it)
	{
		int first = *it;
		int second = *(++it);
		if (first < second)
		{
			pairs.push_back(std::make_pair(second, first));
		}
		else
		{
			pairs.push_back(std::make_pair(first, second));
		}
	}

	// Recursivamente ordena os n/2 maiores elementos de cada par
	sortedPairs(pairs, pairs.size());

	T mainChain;
	T pend;

	// Cria a mainChain com os primeiros elementos (elementos maiores, que ja foram ordenados)
	// Cria a pend que os menores elementos de cada par, estes elementos ainda não estão ordenados
	for (typename std::list<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it)
	{
		mainChain.push_back(it->first);
		pend.push_back(it->second);
	}

	// adiciona o elemento que foi separado no começo, caso a lista seja de tamanho impar
	if (stragglers != -1)
	{
		pend.push_back(stragglers);
	}

	// Adiciona o primeiro elemento da lista pend antes do primeiro elemento da mainchain. Pois já sabemos que ele é menor que o primeiro elemento da mainchain, uma vez que faziam parte do mesmo par
	mainChain.insert(mainChain.begin(), pend.front());

	// Obtém a sequencia da jacobsthal a partir da minha lista desordenada(pend)
	T indexOrder = insertionOrder<T>(pend.size() - 1);

	// Faz o insert de acordo com a ordem de jacobstahl
	if (!indexOrder.empty())
	{
		for (typename T::iterator it = indexOrder.begin(); it != indexOrder.end(); ++it)
		{
			typename T::iterator itPend = pend.begin();
			std::advance(itPend, *it);
			typename T::iterator itPositionInsertion = std::lower_bound(mainChain.begin(), mainChain.end(), *itPend);
			mainChain.insert(itPositionInsertion, *itPend);
		}
	}

	return mainChain;
}

#endif