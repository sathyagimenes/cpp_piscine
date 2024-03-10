/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 22:31:43 by sde-cama          #+#    #+#             */
/*   Updated: 2024/03/10 10:45:41 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream> //std::cout, std::endl, std::cerr
#include <iomanip>	//std::setw, std::setfill
#include <cstdlib>	//sts::srand

template <typename T>
class Array
{
private:
	T *_array;
	unsigned int _size;

public:
	/* Orthodox Canonical Form Methods */
	Array<T>(void) : _array(new T()), _size(0){};
	Array<T>(unsigned int size) : _array(new T[size]), _size(size){};
	Array<T>(Array<T> const &src) : _array(new T[src.size()]), _size(src.size())
	{
		for (size_t i = 0; i < _size; i++)
		{
			_array[i] = src._array[i];
		}
	};
	~Array<T>(void) { delete[] _array; };

	/* Operator Overload */
	Array<T> &operator=(Array<T> const &rhs)
	{
		if (this != &rhs)
		{
			delete[] _array;
			_array = new T[rhs.size()];
			_size = rhs.size();
			for (size_t i = 0; i < _size; i++)
			{
				_array[i] = rhs._array[i];
			}
		}
	};
	T &operator[](unsigned int index) const
	{
		if (index >= this->size())
		{
			throw OutOfBoundsException();
		}
		return (_array[index]);
	};

	/* Member Functions */
	unsigned int size(void) const
	{
		return (_size);
	};

	/* Throw Exceptions */
	class OutOfBoundsException : public std::exception
	{
		public:
			virtual const char *what(void) const throw()
			{
				return ("Index is out of bounds");
			};
	};
};

template <typename T>
std::ostream &operator<<(std::ostream &os, Array<T> const &array)
{
	for (size_t i = 0; i < array.size(); i++)
		os << array[i] << " ";
	return (os);
};

#endif

/*
How to implment template classes
header files are not the only portable solution. But they are the most convenient portable solution.
A common solution to this is to write the template declaration in a header file, then implement the class in an implementation file (for example .tpp), and include this implementation file at the end of the header.
*/