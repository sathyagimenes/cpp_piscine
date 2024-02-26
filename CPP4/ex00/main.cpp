/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 09:51:08 by sde-cama          #+#    #+#             */
/*   Updated: 2024/02/25 22:46:30 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{
    const Animal        *meta = new Animal();
    const Animal        *j = new Dog();
    const Animal        *i = new Cat();
    const WrongAnimal   *h = new WrongAnimal();
    const WrongAnimal   *g = new WrongCat();

    std::cout << j->getType() << ": ";
    j->makeSound();
    std::cout << i->getType() << ": ";
    i->makeSound(); // will output the cat sound!
    std::cout << meta->getType() << ": ";
    meta->makeSound();
    std::cout << h->getType() << ": ";
    h->makeSound(); // will output the wrong animal sound!
    std::cout << g->getType() << ": ";
    g->makeSound();

    delete h;
    delete g;
    delete i;
    delete j;
    delete meta;

    return 0;
}

/*
    Class Pointer VS Class Instance
        https://cplusplus.com/forum/general/37813/

    If you make it on the heap (Class Pointer and 'new'), it will exist until you deliberately delete it. So long as you don't lose the pointer to it, you can hand it around various scopes and functions, knowing it will still be there.
    If you make it on the stack (Class Instance), it will be destroyed as soon as you exit that scope.

    Important: You can only use polymorphy with instance pointers or references,
    not with instances.

    - Allocation on the heap is not as cheap as allocation on the stack.
    - Objects on the stack must be smaller, for variety of reasons
    (cost of copy construction, locality of reference, stack overflow, etc.)
    - Using pointers and references can remove compilation dependencies and
    consequently reduce the compilation times.
    - Objects on the stack are cleaned-up automatically in case of exceptions.
    - Objects on the stack tend to be closer to each other in memory,
    and this helps caching and paging.
*/
