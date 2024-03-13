/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 22:33:52 by sde-cama          #+#    #+#             */
/*   Updated: 2024/03/10 11:26:00 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

#define SIZE 10

int main()
{
	int *a = new int();
	std::cout << a << std::endl;
	delete a;

	Array<int> intArray(SIZE);
	Array<float> floatArray(SIZE);
	Array<double> doubleArray(SIZE);
	Array<std::string> stringArray(SIZE);

	for (int i = 0; i < 10; i++)
	{
		intArray[i] = i;
		floatArray[i] = static_cast<float>(i);
		doubleArray[i] = static_cast<double>(i);
		stringArray[i] = std::string(1, '0' + i);
	}
	


	std::cout << "\n**Print arrays**" << std::endl;
	std::cout << "Int array: " << intArray << std::endl;
	std::cout << "Float array: " << floatArray << std::endl;
	std::cout << "Double array: " << doubleArray << std::endl;
	std::cout << "String array: " << stringArray << std::endl;

	try
	{
		std::cout << "\n**Out of boounds check**" << std::endl;
		std::cout << "Invalid index at int array: " << intArray[SIZE] << std::endl;
	}
	catch (Array<int>::OutOfBoundsException &e)
	{
		std::cout << e.what() << std::endl;
	}
		
	try
	{
		std::cout << "\n**Out of boounds check**" << std::endl;
		std::cout << "Invalid index at string array: " << stringArray[SIZE] << std::endl;
	}
	catch (Array<std::string>::OutOfBoundsException &e)
	{
		std::cout << e.what() << std::endl;
	}
	
	std::cout << "\n**Copy check**" << std::endl;
	Array<int> copyIntArray = intArray;
	std::cout << "Original Array size: " << intArray.size() << std::endl;
	std::cout << "Copy Array size: " << copyIntArray.size() << std::endl;
	std::cout << "Original Element at index 3: " << intArray[3] << std::endl;
	std::cout << "Copy Element at index 3: " << intArray[3] << std::endl;
	std::cout << "*Changing Element at index 3 of Copy array*" << std::endl;
	copyIntArray[3] = 42;
	std::cout << "Copy array: " << copyIntArray << std::endl;
	std::cout << "Original array: " << intArray << std::endl;

	return (0);
}