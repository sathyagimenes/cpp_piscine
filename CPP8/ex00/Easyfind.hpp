/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 18:28:33 by sde-cama          #+#    #+#             */
/*   Updated: 2024/04/14 14:12:03 by sde-cama         ###   ########.fr       */
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

	occurance = std::find(array.begin(), array.end(), search);
	if (occurance == array.end())
		throw(std::out_of_range("Element not found in this container."));
	return (occurance);
}

#endif