/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 09:51:08 by sde-cama          #+#    #+#             */
/*   Updated: 2024/03/06 20:53:31 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main( void )
{
	std::cout << "=== Constructor List ===" << std::endl;
	Data		*dataOriginal = new Data();
	Serializer s = Serializer();
	uintptr_t	dataSerialized;
	Data		*dataDeserialized;
	dataOriginal->name = "Sathya";
	dataOriginal->age = 31;

	std::cout << "\n> Original Data:\t\t" << dataOriginal->name << std::endl;
	dataSerialized = s.serialize(dataOriginal);
	std::cout << "> Serialized Data:\t" << dataSerialized << std::endl;
	dataDeserialized = s.deserialize(dataSerialized);
	
	if (dataOriginal == dataDeserialized)
	{
		std::cout << "> Deserialized Data:\t" << dataDeserialized->name << std::endl;
	}
	else
	{
		std::cerr << "> Data not deserialized!" << std::endl;
	}
	
	std::cout << "\n=== Destructor List ===" << std::endl;
	delete dataOriginal;
	return (0);
}
