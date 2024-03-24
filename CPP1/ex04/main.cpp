/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 22:36:12 by sde-cama          #+#    #+#             */
/*   Updated: 2024/03/24 18:29:53 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

int main(int argc, char *argv[])
{
    if (!check_argc(argc))
        return(1);

    std::ifstream	infile(argv[1]);
    if (!check_in_file(infile))
        return(1);

    std::string fileName(argv[1]);
    fileName += ".replace";
    std::ofstream   outfile(fileName.c_str());
    if (!check_out_file(outfile))
        return (1);

    std::string s1(argv[2]);
    std::string s2(argv[3]);
    if (s1.empty()) {
        std::cout << "Error: invalid expression. String #1 can not be empty" << std::endl;
        return(1);
    }

    replace(infile, outfile, s1, s2);

    infile.close();
    outfile.close();

    return (0);
}
