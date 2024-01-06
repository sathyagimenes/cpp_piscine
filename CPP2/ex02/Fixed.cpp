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
	_rawBits = 0;
	return;
};

Fixed::Fixed(Fixed const &copy)
{
	*this = copy;
	return;
};

Fixed::Fixed(const int intValue)
{
	_rawBits = intValue << _fractionalBits;
	return;
};

Fixed::Fixed(const float floatValue)
{
	_rawBits = roundf(floatValue * (1 << _fractionalBits));
	return;
};

Fixed::~Fixed(void)
{
	return;
};

Fixed &Fixed::operator=(Fixed const &fixed)
{
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

Fixed	Fixed::operator > (Fixed const &rightHandSide)
{
	return (getRawBits() > rightHandSide.getRawBits());
}

Fixed	Fixed::operator < (Fixed const &rightHandSide)
{
	return (getRawBits() < rightHandSide.getRawBits());
}

Fixed	Fixed::operator >= (Fixed const &rightHandSide)
{
	return (getRawBits() >= rightHandSide.getRawBits());
}

Fixed	Fixed::operator <= (Fixed const &rightHandSide)
{
	return (getRawBits() <= rightHandSide.getRawBits());
}

Fixed	Fixed::operator == (Fixed const &rightHandSide)
{
	return (getRawBits() == rightHandSide.getRawBits());
}

Fixed	Fixed::operator != (Fixed const &rightHandSide)
{
	return (getRawBits() != rightHandSide.getRawBits());
}

Fixed	Fixed::operator + (Fixed const &rightHandSide)
{
	Fixed result;

	result.setRawBits(getRawBits() + rightHandSide.getRawBits());
	return (result);
}

Fixed	Fixed::operator - (Fixed const &rightHandSide)
{
	Fixed result;

	result.setRawBits(getRawBits() - rightHandSide.getRawBits());
	return (result);}

Fixed	Fixed::operator * (Fixed const &rightHandSide)
{
	return (Fixed(this->toFloat() * rightHandSide.toFloat()));
}

Fixed	Fixed::operator / (Fixed const &rightHandSide)
{
	return (Fixed(this->toFloat() / rightHandSide.toFloat()));
}

Fixed	&Fixed::operator ++ (void)
{
	++this->_rawBits;
	return(*this);
}

Fixed	Fixed::operator ++ (int)
{
	Fixed result = *this;
	this->_rawBits++;
	return(result);
}

Fixed	&Fixed::operator -- (void)
{
	--this->_rawBits;
	return(*this);
}
Fixed	Fixed::operator -- (int)
{
	Fixed result = *this;
	this->_rawBits--;
	return(result);
}

Fixed	&Fixed::min(Fixed &leftHandSide, Fixed &rightHandSide)
{
	if (leftHandSide.getRawBits() < rightHandSide.getRawBits())
		return (leftHandSide);
	return (rightHandSide);
}

const Fixed	&Fixed::min(Fixed const &leftHandSide, Fixed const &rightHandSide)
{
	if (leftHandSide.getRawBits() < rightHandSide.getRawBits())
		return (leftHandSide);
	return (rightHandSide);
}

Fixed	&Fixed::max(Fixed &leftHandSide, Fixed &rightHandSide)
{
	if (leftHandSide.getRawBits() > rightHandSide.getRawBits())
		return (leftHandSide);
	return (rightHandSide);
}

const Fixed	&Fixed::max(Fixed const &leftHandSide, Fixed const &rightHandSide)
{
	if (leftHandSide.getRawBits() > rightHandSide.getRawBits())
		return (leftHandSide);
	return (rightHandSide);
}
