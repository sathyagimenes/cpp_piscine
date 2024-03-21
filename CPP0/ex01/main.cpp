/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 21:52:25 by sde-cama          #+#    #+#             */
/*   Updated: 2024/03/20 21:42:17 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include "Utils.hpp"
#include <iostream>

int main(void) {
	PhoneBook phoneBook;
    int contacts_count = 0;
	std::string inputCommand;
	

	do {
		std::cout << "-------------------------------------------------------------\n";
		std::cout << "You can enter one of the three commands: ADD, SEARCH and EXIT\n";
		std::cout << "ADD: add a new contact into phone book.\n";
		std::cout << "SEARCH: search information from contacts in the phone book.\n";
		std::cout << "EXIT: exit the program.\n";
		std::cout << "-------------------------------------------------------------\n";
		inputCommand = getValue();
		if (inputCommand == "SEARCH") {
			phoneBook.SearchContact();
		}
		else if (inputCommand == "ADD") {
			bool success = phoneBook.AddNewContact(contacts_count);
			if (success)
				contacts_count = (contacts_count + 1) % SIZE;
		}
	} while (inputCommand != "EXIT");
	return 0;
}