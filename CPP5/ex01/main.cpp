/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 09:51:08 by sde-cama          #+#    #+#             */
/*   Updated: 2024/03/01 21:49:42 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

int main(void)
{
	std::cout << "\n**Invalid Constructors**" << std::endl;
	try
	{
		std::cout << "\nTry Form(Lei xyz, 0, 0)" << std::endl;
        Form f("Lei xyz", 0, 0);
	}
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

	try
	{
		std::cout << "\nTry Form(Lei xyz, 151, 151)" << std::endl;
		Form f("Lei xyz", 151, 151);
	}
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

	std::cout << "\n**Bureaucrat try to sign valid form**" << std::endl;
	try
	{
        Form f("Lei xyz", 42, 84);
        Bureaucrat b("Assistente Junior", 150);
        std::cout << b;
        std::cout << f;
        std::cout << "\n*Try to sign Form*" << std::endl;
        b.signForm(f);
        std::cout << f << std::endl;
        
        std::cout << "\n*Creating new Bureaucrat in higher rank*" << std::endl;
    	Bureaucrat a("Presidente", 1);
        std::cout << a;
        std::cout << f;
        std::cout << "\n*Try to sign Form*" << std::endl;
        a.signForm(f);
        std::cout << f << std::endl;

        std::cout << "\n**Calling Destructors**" << std::endl;
	}
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
