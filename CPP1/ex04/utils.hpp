/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 22:30:16 by sde-cama          #+#    #+#             */
/*   Updated: 2023/12/09 19:05:11 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __UTILS_H__
#define __UTILS_H__

#include <string>
#include <iostream>
#include <fstream>

bool	check_argc(int argc);
bool	check_in_file(std::ifstream &in);
bool	check_out_file(std::ofstream &out);
void	replace(std::ifstream &in, std::ofstream &out, std::string s1, std::string s2);

#endif