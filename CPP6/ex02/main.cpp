/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 09:51:08 by sde-cama          #+#    #+#             */
/*   Updated: 2024/03/08 21:48:14 by sde-cama         ###   ########.fr       */
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
   The dynamic_cast will seek out the desired object and return it if possible. If it can't, it will return nullptr in the case of a pointer, or throw std::bad_cast in the case of a reference
   https://stackoverflow.com/questions/332030/when-should-static-cast-dynamic-cast-const-cast-and-reinterpret-cast-be-used

	To work on dynamic_cast there must be one virtual function in the base class. A dynamic_cast works only polymorphic base class because it uses this information to decide safe downcasting.
	Downcasting: Casting a base class pointer (or reference) to a derived class pointer (or reference) is known as downcasting.
	Upcasting: Casting a derived class pointer (or reference) to a base class pointer (or reference) is known as upcasting. In figure 1 Casting from Derived class 2 pointer/reference to the “Base class” pointer/reference showing Upcasting (Derived class 2 -> Base Class).
   https://www.geeksforgeeks.org/dynamic-_cast-in-cpp/
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