/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 22:30:16 by sde-cama          #+#    #+#             */
/*   Updated: 2023/12/11 20:59:07 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

bool	check_argc(int argc)
{
	if (argc != 4)
	{
		std::cerr << "ERROR: invalid number of arguments" << std::endl;
		std::cerr << "<fileName> <searchString> <replaceString>" << std::endl;
		return (false);
	}
	return (true);
}

bool	check_in_file(std::ifstream &in)
{
	if (!in.is_open() || in.fail())
	{
		std::cerr << "ERROR: could not open infile." << std::endl;
		return (false);
	}
	return (true);
}

bool	check_out_file(std::ofstream &out)
{
	if (!out.is_open() || out.fail())
	{
		std::cerr << "ERROR: could not create outfile." << std::endl;
		return (false);
	}
	return (true);
}

void	replace(std::ifstream &in, std::ofstream &out, std::string s1, std::string s2)
{
	std::string line;
	size_t s1_pos;
	long unsigned int index;

	while(in.good())
	{
		std::getline(in, line);
		index = 0;
		while (true)
		{
			s1_pos = line.find(s1, index);//acha a posição da s1
			if (s1_pos == std::string::npos)//se não acha encerra o loop
				break;
			out << line.substr(index, s1_pos - index);//copia ate a incidência da s1
			out << s2;//copia a s2 no lugar da s1;
			index = (s1_pos + s1.length());//pula a s1
		}
		out << line.substr(index) << std::endl;
	}
}
