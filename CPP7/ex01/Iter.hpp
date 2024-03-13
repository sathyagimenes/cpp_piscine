/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 22:31:43 by sde-cama          #+#    #+#             */
/*   Updated: 2024/03/08 23:11:12 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void	iter(T *array, size_t lenght, void (*func)(T &))
{
	for (size_t i = 0; i < lenght; i++)
	{
		func(array[i]);
	}
}

// template <typename T>
// void	iter(const T *array, size_t lenght, void (*func)(T const &))
// {
// 	for (size_t i = 0; i < lenght; i++)
// 	{
// 		func(array[i]);
// 	}
// }

template<typename T>
void	print(T x)
{
	std::cout << x << std::endl;
	return ;
}


#endif