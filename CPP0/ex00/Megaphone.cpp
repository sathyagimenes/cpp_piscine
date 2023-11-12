/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:39:50 by sde-cama          #+#    #+#             */
/*   Updated: 2023/11/06 15:56:17 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char *argv[]) {
	std::string word;

	if (argc == 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}

	for (int i = 1; i < argc; i++) {
		word = argv[i];
		for (size_t j = 0; j < word.length(); j++) {
			word[j] = std::toupper(word[j]);
		}
		std::cout << word;
	}
	std::cout << std::endl;
	return 0;
}
