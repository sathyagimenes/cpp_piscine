/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 21:31:20 by gilmar            #+#    #+#             */
/*   Updated: 2024/04/14 06:30:58 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

bool checkInput(char **argv);

int main(int argc, char **argv)
{
    if (argc <= 2)
    {
        std::cerr << "Error: Invalid number of arguments" << std::endl;
        return 1;
    }

    if (checkInput(argv) == false)
    {
        std::cerr << "Error: Invalid argument" << std::endl;
        return 1;
    }

    try
    {
        PmergeMe pmergeMe;
        pmergeMe.merge(argv);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

bool checkInput(char **argv)
{
    std::vector<int> numbers;
    
    for (int i = 1; argv[i]; i++)
    {
        if (isdigit(argv[i][0]) == 0)
        {
            std::cerr << "Error: Invalid argument" << std::endl;
            return false;
        }

        int tmp = std::atoi(argv[i]);
        if (std::find(numbers.begin(), numbers.end(), tmp) != numbers.end())
        {
            return false;
        }
        
        numbers.push_back(tmp);
    }

    return true;
}
