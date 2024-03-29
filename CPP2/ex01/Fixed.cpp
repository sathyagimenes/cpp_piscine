/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 22:30:16 by sde-cama          #+#    #+#             */
/*   Updated: 2023/12/11 20:59:07 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	_rawBits = 0;
	return;
};

Fixed::Fixed(Fixed const &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
	return;
};

Fixed::Fixed(const int intValue)
{
	std::cout << "Int constructor called" << std::endl;
	_rawBits = intValue << _fractionalBits;
	return;
};

Fixed::Fixed(const float floatValue)
{
	std::cout << "Float constructor called" << std::endl;
	_rawBits = roundf(floatValue * (1 << _fractionalBits));
	return;
};

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
	return;
};

Fixed &Fixed::operator=(Fixed const &fixed)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &fixed)
		_rawBits = fixed.getRawBits();
	return *this;
}

int Fixed::getRawBits(void) const
{
	return (this->_rawBits);
}

void Fixed::setRawBits(int const raw)
{
	this->_rawBits = raw;
}

float Fixed::toFloat(void) const
{
	return ((float)getRawBits() / (1 << _fractionalBits));
	//The expression (1 << 8) is a bitwise left shift operation, which effectively means 2 raised to the power of 8. 
	//So, (1 << 8) is equivalent to 256. This function is converting the fixed-point representation to a 
	//floating-point representation.
	//It does this by dividing the raw binary value (getRawBits()) by 256. 
	//This division by 256 corresponds to shifting the binary point 8 positions to the right, 
	//effectively converting the fixed-point number with 8 fractional bits into a floating-point number. The result is a float value representing the fixed-point number in a floating-point format.
	// (1 << _fractionalBits) = 2⁸ => left bitshifting 
	// getRawBits() / (1 << _fractionalBits) = getRawBits * 2^(-8) => right bitshifting
}

int Fixed::toInt(void) const
{
	return (getRawBits() >> _fractionalBits);
}

std::ostream &operator<<(std::ostream &o, Fixed const &i)
{
	o << i.toFloat();
	return (o);
}
