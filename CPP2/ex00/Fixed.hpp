/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 22:30:16 by sde-cama          #+#    #+#             */
/*   Updated: 2023/12/16 21:23:21 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FIXED_H__
#define __FIXED_H__

// #include <string>
#include <iostream>

class Fixed {
	private:
		int	_rawBits;
		static const int	_fractionalBits = 8;

	public:
		Fixed(void);
		Fixed(Fixed const &copy);		
		~Fixed(void);

		Fixed &operator= (Fixed const &fixed);
		int getRawBits(void) const;
		void setRawBits(int const raw);
};

#endif