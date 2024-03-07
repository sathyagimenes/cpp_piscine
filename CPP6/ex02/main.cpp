/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 09:51:08 by sde-cama          #+#    #+#             */
/*   Updated: 2024/03/07 19:41:37 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>	//std::rand(); std::srand()
#include <ctime>	//std::time();
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base	*generate(void)
{
	Base	*random;
	int		type = std::rand() % 3;
	
	switch (type)
	{
		case 0 :
			random = new A;
			break;
		case 1 :
			random = new B;
			break;
		case 2 :
			random = new C;
			break;
	}
	return (random);
}

void	identify(Base *p)
{
	if (dynamic_cast<A *>(p))
	{
		std::cout << "Class A." << std::endl;
	}
	else if (dynamic_cast<B *>(p))
	{
		std::cout << "Class B." << std::endl;
	}
	else if (dynamic_cast<C *>(p))
	{
		std::cout << "Class C." << std::endl;
	}
	else
	{
		std::cout << "Invalid type." << std::endl;
	}
}

void	identify(Base &p)
{
	try
	{
		(void)dynamic_cast<A &>(p);
		std::cout << "Class A." << std::endl;
	}
	catch(std::exception &e) {}
	
	try
	{
		(void)dynamic_cast<B &>(p);
		std::cout << "Class B." << std::endl;
	}
	catch(std::exception &e) {}

	try
	{
		(void)dynamic_cast<C &>(p);
		std::cout << "Class C." << std::endl;
	}
	catch(std::exception &e) {}
}

/* dynamic_cast<type>
   Use dynamic_cast for converting pointers/references within an inheritance hierarchy.

   https://stackoverflow.com/questions/332030/when-should-static-cast-dynamic-cast-const-cast-and-reinterpret-cast-be-used
*/

int	main(void)
{
	/* Set seed for random number generator */
	std::srand(std::time(0));
	Base *random;

	for (int i = 0; i < 10; i++)
	{
		std::cout << "======== Test [" << i << "] ========" << std::endl;
		random = generate();
		std::cout << ">identify(Base *p)" << std::endl;
		identify(random);
		std::cout << "\n>identify(Base &p)" << std::endl;
		identify(*random);
		delete (random);
		std::cout << "" << std::endl;
	}
	return (0);
}