/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:02:58 by sde-cama          #+#    #+#             */
/*   Updated: 2023/11/12 16:18:29 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include<iostream>

Contact::Contact(void) { return; }
Contact::~Contact(void) { return; }

Contact::Contact(std::string firstName, std::string lastName,
                 std::string nickname, std::string phoneNumber,
                 std::string darkestSecret)
    : _firstName(firstName), _lastName(lastName), _nickname(nickname),
      _phoneNumber(phoneNumber), _darkestSecret(darkestSecret) {
  return;
}

void	Contact::display(void)
{
  std::cout << "-------------------------------------------------------------" << std::endl;
	std::cout << "First Name:\t" << this->_firstName << std::endl;
	std::cout << "Last Name:\t" << this->_lastName << std::endl;
	std::cout << "Nickname:\t" << this->_nickname << std::endl;
	std::cout << "Phone Number:\t" << this->_phoneNumber << std::endl;
	std::cout << "Darkest Secret:\t" << this->_darkestSecret << std::endl;
  std::cout << "-------------------------------------------------------------" << std::endl;
}

std::string	Contact::getFirstName() const { return this->_firstName; }
std::string	Contact::getLastName() const { return this->_lastName; }
std::string	Contact::getNickname() const { return this->_nickname; }
std::string	Contact::getPhoneNumber() const { return this->_phoneNumber; }
std::string	Contact::getDarkestSecrect() const { return this->_darkestSecret; }