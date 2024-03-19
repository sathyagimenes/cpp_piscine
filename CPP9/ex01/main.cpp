/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 21:16:05 by sde-cama          #+#    #+#             */
/*   Updated: 2024/03/19 00:47:35 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cerr << "usage: ./RPN <number> <number> <number> <number>" << std::endl;
		return (1);
	}

	RPN rpn(argv[1]);
	return (0);
}
