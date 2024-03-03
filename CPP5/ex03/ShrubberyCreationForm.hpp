/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 11:20:17 by sde-cama          #+#    #+#             */
/*   Updated: 2024/03/03 19:28:56 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <fstream>
#include "AForm.hpp"

#define SCF_SIGN_GRADE 145
#define SCF_EXEC_GRADE 137
#define SHRUBBERY \
	"\
              * *\n\
           *    *  *\n\
      *  *    *     *  *\n\
     *     *    *  *    *\n\
 * *   *    *    *    *   *\n\
 *     *  *    * * .#  *   *\n\
 *   *     * #.  .# *   *\n\
  *     #.  #: # * *    *\n\
 *   * * #. ##       *\n\
   *       ###\n\
             ##\n\
              ##.\n\
              .##:\n\
              :###\n\
              ;###\n\
            ,####.\n\
VVVVVVVVVVV.######.VVVVVVVVV\n\
"

class ShrubberyCreationForm : public AForm
{
public:
	/* Orthodox Canonical Form Methods */
	ShrubberyCreationForm(void);
	ShrubberyCreationForm(ShrubberyCreationForm const &src);
	ShrubberyCreationForm(std::string const &target);
	ShrubberyCreationForm &operator=(ShrubberyCreationForm const &rhs);
	~ShrubberyCreationForm(void);

	/* Throw Exceptions */
	class FileCreateErrorException : public std::exception
	{
	public:
		const char *what(void) const throw();
	};

	/* Member Functions */
	void execute(Bureaucrat const &executor) const;
	static AForm *create(std::string const &target);
};