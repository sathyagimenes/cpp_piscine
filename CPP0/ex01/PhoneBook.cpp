/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:03:28 by sde-cama          #+#    #+#             */
/*   Updated: 2024/03/20 21:43:16 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

Contact phoneBook[SIZE];

PhoneBook::PhoneBook() { return; };
PhoneBook::~PhoneBook() { return; };

static std::string formatString(std::string str)
{
	if (str.length() <= 10)
		return str;
	str.resize(10);
	str[9] = '.';
	return str;
}

static void printWithPadding(std::string str)
{
	std::cout.width(10);
	std::cout << std::right << str << '|';
}

static void printWithPadding(int index)
{
	std::cout.width(10);
	std::cout << std::right << index << '|';
}

void PhoneBook::DisplayPhoneBook()
{
	std::string value;
	printWithPadding("Index");
	printWithPadding("First Name");
	printWithPadding("Last Name");
	printWithPadding("Nickname");
	std::cout << std::endl;

	for (int i = 0; i < SIZE; i++)
	{
		printWithPadding(i + 1);
		printWithPadding(formatString(phoneBook[i].getFirstName()));
		printWithPadding(formatString(phoneBook[i].getLastName()));
		printWithPadding(formatString(phoneBook[i].getNickname()));
		std::cout << std::endl;
	};
}

void PhoneBook::SearchContact()
{
	int index;
	std::string inputIndex;
	DisplayPhoneBook();

	while (true)
	{
		std::cout << "Input contact's index wanted: ";
		inputIndex = getValue();

		if (inputIndex == "EXIT")
			return;
		for (unsigned int i = 0; i < inputIndex.length(); i++)
		{
			if (!std::isdigit(inputIndex[i]))
			{
				std::cerr << "\nIndex must be a positive number!\n\n";
				break;
			}
			else
			{
				index = std::atoi(inputIndex.c_str());
				if (index < 1 || index >= 8)
				{
					std::cerr << "\nIndex out of range!\n\n";
					break;
				}
				else if (phoneBook[index - 1].getFirstName().empty())
				{
					std::cerr << "\nInvalid index!\n\n";
				}
			}
		}
		if (index >= 1 && index < 8 && !phoneBook[index - 1].getFirstName().empty())
		{
			break;
		}
	}
	phoneBook[index - 1].display();
}

bool PhoneBook::AddNewContact(int index)
{
	bool invalidInput = false;

	std::cout << "Input First Name: ";
	std::string firstName = getValue();
	std::cout << "Input Last Name: ";
	std::string lastName = getValue();
	std::cout << "Input Nickname: ";
	std::string nickname = getValue();
	std::cout << "Input Phone Number: ";
	std::string phoneNumber = getValue();
	std::cout << "Input Darkest Secret: ";
	std::string darkestSecret = getValue();
	for (unsigned int i = 0; i < phoneNumber.length(); i++)
	{
		if (!std::isdigit(phoneNumber[i]))
			invalidInput = true;
	}
	if (invalidInput)
	{
		std::cerr << "\nFAILED TO ADD NEW CONTACT\n";
		std::cerr << "Phone Number must be only numbers!\n";
	}
	else
		phoneBook[index] = Contact(firstName, lastName, nickname, phoneNumber, darkestSecret);
	return (!invalidInput);
}
