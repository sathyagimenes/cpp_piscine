/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 22:30:16 by sde-cama          #+#    #+#             */
/*   Updated: 2023/12/16 23:24:40 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FIXED_H__
#define __FIXED_H__

#include <iostream>
#include <cmath>

class Fixed {
	private:
		int	_rawBits;
		static const int	_fractionalBits = 8;

	public:
		Fixed(void);
		Fixed(Fixed const &copy);
		Fixed(const int intValue);
		Fixed(const float floatValue);
		~Fixed(void);

		Fixed &operator = (Fixed const &fixed);
		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;
};

std::ostream & operator << (std::ostream & o, Fixed const & i);

#endif