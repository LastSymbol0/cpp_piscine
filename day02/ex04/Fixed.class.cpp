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
	val = a.getRawBits();
}

Fixed::Fixed(void)
{
	val = 0;
}

Fixed::Fixed(const int n)
{
	setRawBits(n << 8);
}

Fixed::Fixed(const float n)
{
	setRawBits(roundf(n * (1 << _bits)));
}

Fixed::~Fixed(void)
{
	return ;
}

// Math

Fixed&		Fixed::operator=(Fixed& a)
{
	val = a.getRawBits();
	return (a);
}

Fixed		Fixed::operator=(Fixed a)
{
	val = a.getRawBits();
	return (a);
}

Fixed		Fixed::operator+(Fixed a)
{
	return (Fixed (toFloat() + a.toFloat()));
}

Fixed		Fixed::operator-(Fixed a)
{
	return (Fixed (toFloat() - a.toFloat()));
}

Fixed		Fixed::operator*(Fixed a)
{
	return (Fixed (toFloat() * a.toFloat()));
}

Fixed		Fixed::operator/(Fixed a)
{
	return (Fixed (toFloat() / a.toFloat()));
}

Fixed		Fixed::operator++(void)
{
	Fixed res;

	res.val = ++val;
	return (res);
}

Fixed		Fixed::operator++(int)
{
	Fixed res;

	res.val = val++;
	return (res);
}

Fixed		Fixed::operator--(void)
{
	Fixed res;

	res.val = --val;
	return (res);
}

Fixed		Fixed::operator--(int)
{
	Fixed res;

	res.val = val--;
	return (res);
}

// Bool

bool		Fixed::operator==(Fixed a)
{
	return (val == a.val);
}

bool		Fixed::operator!=(Fixed a)
{
	return (val != a.val);
}

bool		Fixed::operator>(Fixed a)
{
	return (val  > a.val);
}

bool		Fixed::operator>(const Fixed a) const
{
	return (val  > a.val);
}

bool		Fixed::operator>=(Fixed a)
{
	return (val >= a.val);
}

bool		Fixed::operator<(Fixed a)
{
	return (val  < a.val);
}

bool		Fixed::operator<(const Fixed a) const
{
	return (val  < a.val);
}

bool		Fixed::operator<=(Fixed a)
{
	return (val <= a.val);
}

std::ostream&	operator<<(std::ostream& os, const Fixed& a)
{
	// std::cout << "operator << overload called" << std::endl;
	os << a.toFloat();
	return (os);
}

// methods

int			Fixed::getRawBits(void) const {
	return val;
}

void		Fixed::setRawBits(int const raw) {
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

// min/max

Fixed&		min(Fixed& a, Fixed& b) {
	return (a < b ? a : b);
}

const Fixed&	min(Fixed const& a, Fixed const& b) {
	return (a < b ? a : b);
}

Fixed&		max(Fixed& a, Fixed& b) {
	return (a > b ? a : b);
}

const Fixed&	max(Fixed const& a, Fixed const& b) {
	return (a > b ? a : b);
}
