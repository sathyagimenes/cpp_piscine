/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 22:36:12 by sde-cama          #+#    #+#             */
/*   Updated: 2023/12/04 23:25:21 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void)
{
    std::string myString = "HI THIS IS BRAIN";
    std::string *stringPTR = &myString;
    std::string &stringREF = myString;

    std::cout << "The string: " << myString << std::endl;

    std::cout << "The memory address of the string variable: ";
    std::cout << &myString << std::endl;

    std::cout << "The memory address held by stringPTR: ";
    std::cout << stringPTR << std::endl;

    std::cout << "The memory address held by stringREF: ";
    std::cout << &stringREF << std::endl;

    std::cout << "The value of the string variable: ";
    std::cout << myString << std::endl;

    std::cout << "The value pointed to by stringPTR: ";
    std::cout << *stringPTR << std::endl;

    std::cout << "The value pointed to by stringREF: ";
    std::cout << stringREF << std::endl;

    return (0);
}
