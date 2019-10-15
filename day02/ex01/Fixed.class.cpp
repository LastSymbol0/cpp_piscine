/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aillia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 17:46:26 by aillia            #+#    #+#             */
/*   Updated: 2019/10/03 17:46:27 by aillia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.class.hpp"
#include <iostream>
#include <cmath>

const int	Fixed::_bits = 8;

Fixed::Fixed(const Fixed& a)
{
	std::cout << "Copy construct called" << std::endl;
	val = a.getRawBits();
}

Fixed::Fixed(void)
{
	std::cout << "Default construct called" << std::endl;
	val = 0;
}

Fixed::Fixed(const int n)
{
	std::cout << "Int construct called" << std::endl;
	setRawBits(n << 8);
}

Fixed::Fixed(const float n)
{
	std::cout << "Float construct called" << std::endl;
	setRawBits(roundf(n * (1 << _bits)));
}

Fixed::~Fixed(void)
{
	std::cout << "Destruct called" << std::endl;
}

Fixed&		Fixed::operator=(Fixed& a)
{
	std::cout << "Assignation operator overload called" << std::endl;
	val = a.getRawBits();
	return (a);
}

Fixed		Fixed::operator=(Fixed a)
{
	std::cout << "Assignation operator overload called" << std::endl;
	val = a.getRawBits();
	return (a);
}

std::ostream&	operator<<(std::ostream& os, const Fixed& a)
{
	// std::cout << "operator << overload called" << std::endl;
	os << a.toFloat();
	return (os);
}

int			Fixed::getRawBits(void) const {
	// std::cout << "getRawBits called" << std::endl;
	return val;
}

void		Fixed::setRawBits(int const raw) {
	// std::cout << "setRawBits called" << std::endl;
	val = raw;
}

float		Fixed::toFloat(void) const
{
	return (((float)val / (1 << _bits)));
}
int			Fixed::toInt(void) const
{
	return (val >> _bits);
}