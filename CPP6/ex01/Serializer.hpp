/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 20:01:55 by sde-cama          #+#    #+#             */
/*   Updated: 2024/03/06 20:37:06 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream> // std::cout, std::cerr
#include <stdint.h> // uintptr_t

struct Data
{
	std::string name;
	int age;
};

class Serializer
{
public:
	/* Orthodox Canonical Form Methods */
	Serializer(void);
	Serializer(Serializer const &src);
	Serializer &operator=(Serializer const &rhs);
	~Serializer(void);

	static uintptr_t serialize(Data *ptr);
	static Data *deserialize(uintptr_t raw);
	/* What is the uintptr_t data type?
	'uintptr_t' is an unsigned integer type that is capable of storing a data
	pointer
	https://stackoverflow.com/questions/1845482/what-is-the-uintptr-t-data-type
	*/

	/* reinterpret_cast<type>
	Use reinterpret_cast for low-level reinterpreting of bit patterns.
	Use with extreme caution.
	- Reinterpreta padrões de bits e é de baixo nível.
	- Use-o quando estiver absolutamente certo sobre o tipo de destino.
	- Convertendo ponteiros para e de tipos inteiros e outros ponteiros.

	https://stackoverflow.com/questions/332030/when-should-static-cast-dynamic-cast-const-cast-and-reinterpret-cast-be-used
	*/
};