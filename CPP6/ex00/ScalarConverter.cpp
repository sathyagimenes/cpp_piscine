/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 20:49:15 by sde-cama          #+#    #+#             */
/*   Updated: 2024/03/06 20:00:37 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void)
{
	std::cout << "Default constructor called.";
	return ;
}

ScalarConverter::ScalarConverter(ScalarConverter const &src)
{
	std::cout << "Copy constructor called.";
	(void)src;
	return ;
}

ScalarConverter::~ScalarConverter(void)
{
	std::cout << "Destructor called.";
	return ;
}

ScalarConverter & ScalarConverter::operator = (ScalarConverter const &rhs)
{
	std::cout << "Assignment operator called.";
	(void)rhs;
	return (*this);
}

int		ScalarConverter::is_infinity(const std::string &str)
{
	if (!str.compare("-inff") || !str.compare("+inff") || !str.compare("nanf"))
		return (FLOAT);
	if (!str.compare("-inf") || !str.compare("+inf") || !str.compare("nan"))
		return (DOUBLE);
	return (INVALID);
}

bool	ScalarConverter::is_all_digits(const std::string &str, int type)
{
	unsigned int	i = 0;

	if (str[0] == '+' || str[0] == '-')
		i++;
	if (type == 1)//int
	{
		while (i < str.length())
		{
			if (!isdigit(str[i++]))
				return (false);
		}
	}
	else if (type == 2)//float
	{
		while (i < str.length())
		{
			if (!isdigit(str[i]) && str[i] != '.' && str[i] != 'f')
				return (false);
			i++;
		}
	}
	else
		return (false);
	return (true);
}

bool	ScalarConverter::is_char(const std::string &str)
{
	if (str.length() == 1 && std::isprint(str[0]) && !std::isdigit(str[0]))
		return (true);
	return (false);
}

bool	ScalarConverter::is_int(const std::string &str)
{
	if (is_all_digits(str, 1) && str.length() < 16)
		return (true);
	return (false);
}

bool	ScalarConverter::is_float(const std::string &str)
{
	size_t dlength = str.length() - 1;

	if (str.at(dlength) != 'f')
		return (false);
	if (is_infinity(str) == FLOAT)
		return (true);
	if (is_all_digits(str, 2) && str.find('.') <= 16)
		return (true);
	return (false);
}

bool	ScalarConverter::is_double(const std::string &str)
{
	if (is_infinity(str) == DOUBLE)
		return (true);
	if (is_all_digits(str, 2) && str.find('.') <= 16)
		return (true);
	return (false);
}

int	ScalarConverter::get_type(const std::string str)
{
	if (str.empty())
		return (INVALID);
	if (is_char(str))
		return (CHAR);
	if (is_int(str))
		return (INT);
	if (is_float(str))
		return (FLOAT);
	if (is_double(str))
		return (DOUBLE);
	return (INVALID);
}

void	ScalarConverter::convert_to_char(const std::string &str)
{
	print_char(str[0]);
	print_int(static_cast<int>(str[0]));
	print_float(static_cast<float>(str[0]));
	print_double(static_cast<double>(str[0]));
}

bool	ScalarConverter::is_overflow(const std::string &str)
{
	long int	of = std::atol(str.c_str());
	
	if (of >= LimitsInt::min() && of <= LimitsInt::max())
		return (true);
	print_impossible("char");
	print_impossible("int");
	print_float(static_cast<float>(of));
	print_double(static_cast<double>(of));
	return (false);
}

void	ScalarConverter::convert_to_int(const std::string &str)
{
	if (!is_overflow(str))
		return ;
	int	nb = std::atoi(str.c_str());
	
	if (nb < LimitsChar::min() || nb > LimitsChar::max())
		print_impossible("char");
	else
		print_char(static_cast<char>(nb));
	print_int(nb);
	print_float(static_cast<float>(nb));
	print_double(static_cast<double>(nb));
}

void	ScalarConverter::convert_to_float(const std::string &str)
{
	float	nb = std::strtof(str.c_str(), NULL);

	if (nb < LimitsChar::min() || nb > LimitsChar::max() || std::isnan(nb) || std::isinf(nb))
		print_impossible("char");
	else
		print_char(static_cast<char>(nb));
	
	if (nb < LimitsInt::min() || nb > LimitsInt::max() || std::isnan(nb) || std::isinf(nb))
		print_impossible("int");
	else
		print_int(static_cast<int>(nb));
	print_float(nb);
	print_double(static_cast<double>(nb));
}

void	ScalarConverter::convert_to_double(const std::string &str)
{
	double	nb = std::strtod(str.c_str(), NULL);

	if (nb < LimitsChar::min() || nb > LimitsChar::max() || std::isnan(nb) || std::isinf(nb))
		print_impossible("char");
	else
		print_char(static_cast<char>(nb));
	if (nb < LimitsInt::min() || nb > LimitsInt::max() || std::isnan(nb) || std::isinf(nb))
		print_impossible("int");
	else
		print_int(static_cast<int>(nb));
	if (nb < LimitsFloat::min() || nb > LimitsFloat::max())
		print_impossible("float");
	else
		print_float(static_cast<float>(nb));
	print_double(nb);
}

void	ScalarConverter::print_char(char c)
{
	if (std::isprint(c))
	{
		std::cout << "char: '" << c << "'" << std::endl;
	}
	else
	{
		std::cout << "char: Non displayable" << std::endl;
	}
}

void	ScalarConverter::print_int(int d)
{
	std::cout << "int: " << d << std::endl;
}

void	ScalarConverter::print_float(float f)
{
	std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
}

void	ScalarConverter::print_double(double d)
{
	std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
}

void	ScalarConverter::print_impossible(const std::string type)
{
	std::cout << type << ": impossible" << std::endl;
}

void	ScalarConverter::impossible_conversion(void)
{
	print_impossible("char");
	print_impossible("int");
	print_impossible("float");
	print_impossible("double");
}

void	ScalarConverter::convert(const std::string str)
{
	int	type = get_type(str);

	switch (type)
	{
		case CHAR:
			convert_to_char(str);
			break;
		case INT:
			convert_to_int(str);
			break;
		case FLOAT:
			convert_to_float(str);
			break;
		case DOUBLE:
			convert_to_double(str);
			break;
		default :
			impossible_conversion();
	}
}