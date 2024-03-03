/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 11:20:17 by sde-cama          #+#    #+#             */
/*   Updated: 2024/03/03 19:28:10 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

#define PPF_SIGN_GRADE 25
#define PPF_EXEC_GRADE 5

class PresidentialPardonForm : public AForm
{
	public:
		/* Orthodox Canonical Form Methods */
		PresidentialPardonForm(void);
		PresidentialPardonForm(PresidentialPardonForm const &src);
		PresidentialPardonForm(std::string const &target);
		PresidentialPardonForm &operator = (PresidentialPardonForm const &rhs);
		~PresidentialPardonForm(void);

		/* Member Functions */
		void	execute(Bureaucrat const &executor) const;
		static AForm	*create(std::string const &target);
};