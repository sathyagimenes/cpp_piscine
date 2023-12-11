/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 22:30:16 by sde-cama          #+#    #+#             */
/*   Updated: 2023/12/09 18:40:53 by sde-cama         ###   ########.fr       */
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
		std::cerr << "ERROR: could not open file." << std::endl;
		return (false);
	}
	return (true);
}

bool	check_out_file(std::ofstream &out)
{
	if (!out.is_open() || out.fail())
	{
		std::cerr << "ERROR: could not create file." << std::endl;
		return (false);
	}
	return (true);
}