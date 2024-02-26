/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 19:23:57 by sde-cama          #+#    #+#             */
/*   Updated: 2024/02/26 19:29:46 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __AANIMAL_H__
#define __AANIMAL_H__

#include <iostream>

/*
	An abstract class is a class that is designed to be specifically used as a base
	class. An abstract class contains at least one pure virtual function.
	https://www.ibm.com/docs/en/zos/2.4.0?topic=only-abstract-classes-c

	You can't create an object of an abstract class type. However, you can use pointers and references to abstract class types.
	https://learn.microsoft.com/en-us/cpp/cpp/abstract-classes-cpp?view=msvc-170
*/
class AAnimal
{
protected:
	std::string _type;

public:
	/* Orthodox Canonical Form methods*/
	AAnimal(void);
	AAnimal(AAnimal const &copy);
	AAnimal(std::string type);
	virtual ~AAnimal(void);
	AAnimal &operator=(AAnimal const &rhs);

	/* Getters */
	std::string getType(void) const;

	/* Setters */
	void setType(std::string const &type);

	/*
		You create an abstract class by declaring at least one pure virtual member function. That's a virtual function declared by using the pure specifier (= 0) syntax. Classes derived from the abstract class must implement the pure virtual function or they, too, are abstract classes.
		https://learn.microsoft.com/en-us/cpp/cpp/abstract-classes-cpp?view=msvc-170
	*/
	virtual void makeSound(void) const = 0;
};

#endif