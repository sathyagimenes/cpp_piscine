/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 22:36:12 by sde-cama          #+#    #+#             */
/*   Updated: 2023/12/11 22:42:53 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char *argv[])
{
    Harl harl;

    if (argc != 2)
    {
        std::cerr << "ERROR: invalid number of arguments" << std::endl;
        std::cerr << "./main <level>" << std::endl;
        return (1);
    }

    harl.complain(argv[1]);
    return (0);
}
