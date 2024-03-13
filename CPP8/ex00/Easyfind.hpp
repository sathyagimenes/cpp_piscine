/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 18:28:33 by sde-cama          #+#    #+#             */
/*   Updated: 2024/03/13 19:49:50 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

template <typename T>
typename T::iterator easyfind(T &array, int search)
{
	typename T::iterator occurance;

	/*
	template <class InputIterator, class T>
	InputIterator find (InputIterator first, InputIterator last, const T& val);

	Find value in range
	Returns an iterator to the first element in the range (first,last) that compares equal to val. If no such element is found, the function returns last.
	from <algorithm>
	https://cplusplus.com/reference/algorithm/find/
	*/
	occurance = std::find(array.begin(), array.end(), search);
	if (occurance == array.end())
		throw(std::out_of_range("Element not found in this container."));
	return (occurance);
}

#endif