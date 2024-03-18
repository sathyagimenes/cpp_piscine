/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 21:16:20 by sde-cama          #+#    #+#             */
/*   Updated: 2024/03/17 20:13:58 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <fstream>	// std::fstream, open()
#include <iostream> // std::cout(), std::cerr()
#include <map>		// std::map<type, type>
#include <sstream>	// std::istringstream
#include <stdlib.h> // atof()
#include <string>	// c_str(), substr(), length(), find()

class BitcoinExchange
{
private:
	/*
	Maps are associative containers that store elements formed by a combination of a key value and a mapped value, following a specific order.

	In a map, the key values are generally used to sort and uniquely identify the elements, while the mapped values store the content associated to this key. The types of key and mapped value may differ, and are grouped together in member type value_type, which is a pair type combining both:

	typedef pair<const Key, T> value_type;
	*/
	static std::map<std::string, double> _map;

	/* Orthodox Canonical methods */
	BitcoinExchange(void);
	BitcoinExchange(BitcoinExchange const &src);
	BitcoinExchange &operator=(BitcoinExchange const &rhs);
	~BitcoinExchange(void);

public:
	static void readData(void);
	static void printMap(void);
	static void executeExchange(char *filename);
	static double findLower(const std::string &date);

	/* Exceptions */
	class InvalidFileException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
};

#endif