/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 09:51:08 by sde-cama          #+#    #+#             */
/*   Updated: 2024/02/26 19:34:43 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main(void)
{
    // AAnimal	test; // This should not compile because abstract classes cannot be instantiated

    size_t arraySize = 3;
    const AAnimal *AAnimals[arraySize];
    /*
        We can create a pointer to an abstract class, which could be actually
        pointing to the objects of its derived classes. In this way, a container
        of base class pointers can be created which can also store derived class
        objects. Thus dynamic binding will take place for the virtual methods and
        class specific methods will be called.
        https://www.geekinterview.com/question_details/87951
    */

    std::cout << "\n======================================" << std::endl;
    std::cout << "First test: Manipulation of an Array of objects" << std::endl;
    std::cout << "======================================\n"
              << std::endl;

    std::cout << "**Calling Constructors**" << std::endl;
    for (size_t i = 0; i <= arraySize; i++)
    {
        if (i <= arraySize / 2)
            AAnimals[i] = new Dog();
        else
            AAnimals[i] = new Cat();
    }

    std::cout << "\n**Checking Classes**" << std::endl;
    for (size_t i = 0; i <= arraySize; i++)
    {
        if (i <= arraySize / 2)
        {
            std::cout << "Class Dog" << std::endl;
            std::cout << "Type: ";
            std::cout << AAnimals[i]->getType() << std::endl;
            std::cout << "makeSound: ";
            AAnimals[i]->makeSound();
        }
        else
        {
            std::cout << "Class Cat" << std::endl;
            std::cout << "Type: ";
            std::cout << AAnimals[i]->getType() << std::endl;
            std::cout << "makeSound: ";
            AAnimals[i]->makeSound();
        }
        std::cout << std::endl;
    }

    std::cout << "**Calling Destructors**" << std::endl;
    for (size_t i = 0; i <= arraySize; ++i)
        delete AAnimals[i];

    std::cout << "\n===============================" << std::endl;
    std::cout << "Second test: Manipulation of Ideas - copy constructor" << std::endl;
    std::cout << "================================\n"
              << std::endl;

    std::cout << "**Calling Cat Constructors**" << std::endl;
    Cat cat;
    Cat copyCat(cat);

    std::cout << "\n**Display Cats**" << std::endl;
    std::cout << "\nOriginal Cat" << std::endl;
    std::cout << cat;
    std::cout << "\nCopied Cat" << std::endl;
    std::cout << copyCat;

    std::cout << "\n**Display Cats Ideas**" << std::endl;
    std::cout << "Original Cat - Idea number 2: ";
    std::cout << cat.getIdea(2) << std::endl;
    std::cout << "Copied Cat - Idea number 2: ";
    std::cout << copyCat.getIdea(2) << std::endl;

    std::cout << "\n...Changing Cats Ideas..." << std::endl;
    std::string empty("new idea at original cat...");
    cat.setIdea(2, empty);
    empty = "new idea at copied cat...";
    copyCat.setIdea(2, empty);

    std::cout << "\n**Display Cats New Ideas**" << std::endl;
    std::cout << "Original Cat - New Idea number 2: ";
    std::cout << cat.getIdea(2);
    std::cout << "\nCopied Cat - New Idea number 2: ";
    std::cout << copyCat.getIdea(2) << std::endl;

    std::cout << "\n===============================" << std::endl;
    std::cout << "Third test: Manipulation of Ideas - assignment operator" << std::endl;
    std::cout << "================================\n"
              << std::endl;

    std::cout << "\n**Calling Dog Constructors**" << std::endl;
    Dog dog;
    Dog copyDog;
    copyDog = dog;

    std::cout << "**Display Dogs**" << std::endl;
    std::cout << "\nOriginal Dog" << std::endl;
    std::cout << dog;
    std::cout << "\nCopied Dog" << std::endl;
    std::cout << copyDog;

    std::cout << "\n**Display Dogs Ideas**" << std::endl;
    std::cout << "Original Dog - Idea number 2: ";
    std::cout << dog.getIdea(2) << std::endl;
    std::cout << "Copied Dog - Idea number 2: ";
    std::cout << copyDog.getIdea(2) << std::endl;

    std::cout << "\n...Changing Dogs Ideas..." << std::endl;
    empty = "new idea at original dog...";
    dog.setIdea(2, empty);
    empty = "new idea at copied dog...";
    copyDog.setIdea(2, empty);

    std::cout << "\n**Display Dogs New Ideas**" << std::endl;
    std::cout << "Original Dog - New Idea number 2: ";
    std::cout << dog.getIdea(2);
    std::cout << "\nCopied Dog - New Idea number 2: ";
    std::cout << copyDog.getIdea(2) << std::endl;

    std::cout << "\n**Calling Destructors**" << std::endl;
    return (0);
}

/*
    In shallow copy, an object is created by simply copying the data of all variables of the original object. This works well if none of the variables of the object are defined in the heap section of memory. If some variables are dynamically allocated memory from heap section, then the copied object variable will also reference the same memory location.
    In Deep copy, an object is created by copying data of all variables, and it also allocates similar memory resources with the same value to the object. In order to perform Deep copy, we need to explicitly define the copy constructor and assign dynamic memory as well, if required. Also, it is required to dynamically allocate memory to the variables in the other constructors, as well.

    https://www.geeksforgeeks.org/shallow-copy-and-deep-copy-in-c/
*/