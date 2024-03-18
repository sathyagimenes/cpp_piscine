/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 21:16:05 by sde-cama          #+#    #+#             */
/*   Updated: 2024/03/17 21:25:11 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

bool	checkArgs(int argc)
{
	if (argc != 2)
	{
		std::cerr << "USAGE: ./btc <filename>";
		return (false);
	}
	return (true);
}
int	main(int argc, char **argv)
{
	if (!checkArgs(argc))
		return (1);
	try
	{	
		BitcoinExchange::readData();
		// BitcoinExchange::printMap();
		BitcoinExchange::executeExchange(argv[1]);
	}
	catch (BitcoinExchange::InvalidFileException &e) { std::cerr << e.what();}
	return (0);
}
