/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 22:33:52 by sde-cama          #+#    #+#             */
/*   Updated: 2024/03/08 23:12:39 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iter.hpp"

#define ArraySize 10

int	main()
{
	int arrayi[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	iter(arrayi, ArraySize, &print);
	std::cout << std::endl;

	float arrayf[] = {0.5, 1.5, 2.5, 3.5, 4.5, 5.5, 6.5, 7.5, 8.5, 9.5};
	iter(arrayf, ArraySize, &print);
	std::cout << std::endl;

	double arrayd[] = {0.5, 1.5, 2.5, 3.5, 4.5, 5.5, 6.5, 7.5, 8.5, 9.5};
	iter(arrayd, ArraySize, &print);
	std::cout << std::endl;

	std::string arrays[] = {"0.5", "1.5", "2.5", "3.5", "4.5", "5.5", "6.5", "7.5", "8.5", "9.5"};
	iter(arrays, ArraySize, &print);
	std::cout << std::endl;

	return (0);
}