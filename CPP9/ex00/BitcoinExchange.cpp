/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 21:16:13 by sde-cama          #+#    #+#             */
/*   Updated: 2024/03/17 21:48:07 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

std::map<std::string, double>	BitcoinExchange::_map;

const char *BitcoinExchange::InvalidFileException::what(void) const throw()
{
	return ("Error: could not open file.");
}

BitcoinExchange::BitcoinExchange(void)
{
	std::cout << "Default Constructor Called." << std::endl;
	return;
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &src)
{
	std::cout << "Default Constructor Called." << std::endl;
	*this = src;
	return;
}

BitcoinExchange::~BitcoinExchange(void)
{
	std::cout << "Destructor Called." << std::endl;
	return;
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &rhs)
{
	std::cout << "Assignment Operator Called." << std::endl;
	(void)rhs;
	return (*this);
}

/// @brief Checks if a date is in the YYYY-MM-DD format.
/// @param date The date to check.
/// @return true When date is in the YYYY-MM-DD format.
static bool checkDate(std::string date)
{
	/* Size check */
	if (date.size() != 10)
		return (false);
	/* Month check */
	if (date[5] != '0' && date[5] != '1')
		return (false);
	/* Day check */
	if (date[8] > '3' || date[8] < '0') // Day check
		return (false);
	/* Only digits check */
	for (size_t i = 0; i < date.size(); i++)
	{
		if (!std::isdigit(date[i]) && date[i] != '-')
			return (false);
	}
	return (true);
}

static bool checkSeparator(std::string row)
{
	/* '|' check */
	if (row.find('|') == std::string::npos)
		return (false);
	/* White space check */
	if (row[row.find('|') + 1] != ' ' || row[row.find('|') - 1] != ' ')
		return (false);
	/* Only digits check and permitted separators */
	for (size_t i = 0; i < row.size(); i++)
	{
		if (!std::isdigit(row[i]) && row[i] != '-' &&
			row[i] != '|' && row[i] != '.' && row[i] != ' ')
			return (false);
	}
	return (true);
}

static bool checkValue(std::string value)
{
	int		i;
	float	fvalue;

	/* Positive check */
	i = -1;
	while (value[++i] == ' ')
		;
	if (value[i] == '-')
	{
		std::cerr << "Error: not a positive number." << std::endl;
		return (false);
	}

	/* Digitis check */
	i = -1;
	while (value[++i])
	{
		while (value[i] == ' ')
			i++;
		if (!std::isdigit(value[i]) && value[i] != '.')
		{
			std::cerr << "Error: not a number." << std::endl;
			return (false);
		}
	}

	/* Size check */
	fvalue = std::atof(value.c_str());
	if (fvalue > 1000)
	{
		std::cerr << "Error: too large a number." << std::endl;
		return (false);
	}
	return (true);
}

void BitcoinExchange::readData(void)
{
	std::ifstream data("./data/data.csv"); // input file stream
	std::string row;

	if (!data.is_open()) // verifica se está aberto o arquivo
		throw BitcoinExchange::InvalidFileException();
	std::getline(data, row); // le a primeira lihnha e guarda na variavel row
	while (std::getline(data, row))
	{
		std::istringstream iss(row); //"transforma" a linha lida em inputstring stream a ser lido
		std::string date;
		std::string valueStr;

		if (!std::getline(iss, date, ',') || !std::getline(iss, valueStr)) // tenta ler até encontrar delimitador ','
			continue;
		if (!checkDate(date)) // checa a data
			return;
		float value = atof(valueStr.c_str());									   // transforma a string em float
		BitcoinExchange::_map.insert(std::pair<std::string, double>(date, value)); // insere os dois valores na lista
	}
}

void BitcoinExchange::executeExchange(char *filename)
{
	std::ifstream fs(filename); // input file stream
	std::string row;

	if (!fs.is_open()) // checa se o arquivo está aberto
		throw BitcoinExchange::InvalidFileException();
	std::getline(fs, row); // lê a primeira linha

	if (row != "date | value") // checa se a primeira linha está fora do padrão
	{
		std::cerr << "Error: bad input => " << row << std::endl;
		return;
	}

	while (std::getline(fs, row))
	{
		std::string date;
		std::string value;
		float fValue;
		float closestValue;
		size_t splitPoint;

		splitPoint = row.find('|');// encontra posição q vai fazer o split dos valores
		date = row.substr(0, splitPoint - 1);// salva primeira parte
		value = row.substr(splitPoint + 2, row.length());// salva parte após o split
		if (!checkDate(date) || (!checkSeparator(row)))
		{
			std::cerr << "Error: bad input => " << row << std::endl;
			continue;
		}
		if (!checkValue(value))
			continue;
		fValue = atof(value.c_str()); // transforma valor em float
		closestValue = findLower(date);//retorna valor data ou da data anterior
		std::cout << date << " => " << fValue << " = " << closestValue * fValue << std::endl;
	}
}

/// @brief Find a date in the database, or the closest and lower one.
/// @param date The target date to search for.
/// @return double The value in the date or closes and lower date.
double BitcoinExchange::findLower(const std::string &date)
{
	std::map<std::string, double>::const_iterator it = BitcoinExchange::_map.lower_bound(date); // Finds the beginning of a subsequence matching given key.
	const std::string &returnDate = it->first;// pega a key do dicionario

	if (it == BitcoinExchange::_map.begin() || returnDate == date) // se encontrar o match da data ou se for o começo
		return (it->second);// retorna o valor do dicionario
	--it;// pega a data anterior
	return (it->second);// retorna o valor do pair/dicionario
}

void	BitcoinExchange::printMap(void)
{
	std::map<std::string, double>::iterator	it = BitcoinExchange::_map.begin();

	for (; it != BitcoinExchange::_map.end(); it++)
		std::cout << "Key: " << it->first << ", Value: " << it->second << std::endl;
}