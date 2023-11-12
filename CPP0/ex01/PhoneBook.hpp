/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 20:35:14 by sde-cama          #+#    #+#             */
/*   Updated: 2023/11/12 15:52:22 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

const int SIZE = 8;

class PhoneBook {
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