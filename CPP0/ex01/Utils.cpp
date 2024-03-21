/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 21:47:39 by sde-cama          #+#    #+#             */
/*   Updated: 2024/03/20 21:31:32 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Utils.hpp"

std::string getValue(void) {
  std::string value;

  std::cin >> value;
  if (std::cin.eof()) {
    std::cout << std::endl;
  }
  return value;
}
