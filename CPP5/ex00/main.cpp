/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 09:51:08 by sde-cama          #+#    #+#             */
/*   Updated: 2024/02/26 21:58:23 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
    std::cout << "**Calling Bureaucrat Constructors**" << std::endl;
    Bureaucrat zaphod = Bureaucrat("Zaphod Beeblebrox", 150);
    std::cout << zaphod;

    std::cout << "\n**Increment Grade x3**" << std::endl;
    zaphod.incrementGrade();
    zaphod.incrementGrade();
    zaphod.incrementGrade();
    std::cout << zaphod;
    std::cout << "\n**Decrement Grade x3**" << std::endl;
    zaphod.decrementGrade();
    zaphod.decrementGrade();
    zaphod.decrementGrade();
    std::cout << zaphod;

    std::cout << "\n**Out of Bounds Decrement**" << std::endl;
    try
    {
        std::cout << "\n*Try to Decrement Grade x1*" << std::endl;
        zaphod.decrementGrade();
        std::cout << zaphod;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    
    std::cout << "\n**Out of Bounds Increment**\n" << std::endl;
    try
    {
        zaphod = Bureaucrat("Fake Zaphod Beeblebrox", 1);
        std::cout << zaphod;
        std::cout << "\n*Try to Increment Grade x1*" << std::endl;
        zaphod.incrementGrade();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    
	std::cout << "\n**Invalid Constructors**" << std::endl;
	try
	{
		std::cout << "*Invalid Constructor with Grade 0*" << std::endl;
		zaphod = Bureaucrat("Invalid Zaphod Beeblebrox", 0);
	}
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

	try
	{
		std::cout << "\n*Invalid Constructor with Grade -42*" << std::endl;
		zaphod = Bureaucrat("Invalid Zaphod Beeblebrox", -42);
	}
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

	try
	{
		std::cout << "\n*Invalid Constructor with Grade 151*" << std::endl;
		zaphod = Bureaucrat("Invalid Zaphod Beeblebrox", 151);
	}
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n**Calling Destructors**" << std::endl;
    return 0;
}
