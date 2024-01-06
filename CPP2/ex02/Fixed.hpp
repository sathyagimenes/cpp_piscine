/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 22:30:16 by sde-cama          #+#    #+#             */
/*   Updated: 2024/01/06 20:11:17 by sde-cama         ###   ########.fr       */
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

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;

//Overload of assignment operator
		Fixed	&operator = (Fixed const &rightHandSide);

//Overload of comparison operators
		Fixed	operator > (Fixed const &rightHandSide);
		Fixed	operator < (Fixed const &rightHandSide);
		Fixed	operator >= (Fixed const &rightHandSide);
		Fixed	operator <= (Fixed const &rightHandSide);
		Fixed	operator == (Fixed const &rightHandSide);
		Fixed	operator != (Fixed const &rightHandSide);

//Overload of arithmetic operators
		Fixed	operator + (Fixed const &rightHandSide);
		Fixed	operator - (Fixed const &rightHandSide);
		Fixed	operator * (Fixed const &rightHandSide);
		Fixed	operator / (Fixed const &rightHandSide);

// Overload of increment/decrement operators
		Fixed	&operator ++ (void);
		Fixed	operator ++ (int);
		Fixed	&operator -- (void);
		Fixed	operator -- (int);

// Overload of member functions
		static Fixed	&min(Fixed &leftHandSide, Fixed &rightHandSide);
		static const Fixed	&min(Fixed const &leftHandSide, Fixed const &rightHandSide);
		static Fixed	&max(Fixed &leftHandSide, Fixed &rightHandSide);
		static const Fixed	&max(Fixed const &leftHandSide, Fixed const &rightHandSide);
};

std::ostream	&operator << (std::ostream & o, Fixed const & i);

#endif