/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 20:35:14 by sde-cama          #+#    #+#             */
/*   Updated: 2024/03/20 21:30:28 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream> // std::cout, std::cin, std::endl
#include <string>	// std::string
#include "Contact.hpp"
#include "Utils.hpp"

const int SIZE = 8;

class PhoneBook
{
private:
	Contact phoneBook[SIZE];

public:
	PhoneBook(void);
	~PhoneBook(void);

	void AddNewContact(int index);
	void DisplayPhoneBook(void);
	void SearchContact(void);
};

#endif