/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aillia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 19:14:32 by aillia            #+#    #+#             */
/*   Updated: 2019/10/09 19:14:36 by aillia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"
#include <cctype>
#include <iostream>
#include <sstream>
#include <string>
#include <cmath>

Convert::Convert(std::string s) {
	_nan_inf = false;
	_int_imp = false;
	if (s.find("nan") != std::string::npos)
		start_nan(s);
	else if (s.find("inf") != std::string::npos)
		start_inf(s);
	else if (isprint(s[0]) && s.length() == 1 && !isdigit(s[0]))
		start_char(s);
	else if (s.find(".") != std::string::npos)
	{
		if (s.find("f") != std::string::npos)
			start_float(s);
		else
			start_double(s);
	}
	else
		start_int(s);
	std::cout.setf(std::ios::fixed);
}

void	Convert::start_nan(std::string s) {
	if (s == "nan" || s == "nanf") {
		_nan_inf = true;
		_f = nanf("s");
		_d = static_cast<double>(_f);
		_n = 0;
		_c = 0;
	}
	else
		throw ConvertStringFormatException();
}

void	Convert::start_inf(std::string s) {
	if (s == "+inf" || s == "+inff" || s == "inf" || s == "inff") {
		_nan_inf = true;
		_f = INFINITY;
		_d = static_cast<double>(_f);
		_n = 0;
		_c = 0;
	} else if (s == "-inf" || s == "-inff") {
		_nan_inf = true;
		_f = - INFINITY;
		_d = static_cast<double>(_f);
		_n = 0;
		_c = 0;
	}
	else
		throw ConvertStringFormatException();
}

void	Convert::start_char(std::string s) {
	_c = s[0];
	_n = static_cast<int>(_c);
	_f = static_cast<float>(_n);
	_d = static_cast<double>(_n);
	std::cout.precision(1);
}

void	Convert::start_int(std::string s) {
	std::istringstream	iss(s);
	iss >> _n;
	if (iss.fail())
		throw ConvertStringFormatException();
	_c = static_cast<char>(_n);
	_f = static_cast<float>(_n);
	_d = static_cast<double>(_n);
	std::cout.precision(1);
}

void	Convert::start_float(std::string s) {
	std::istringstream	iss(s.substr(0, s.length() - 1));
	iss >> _f;
	if (iss.fail())
		throw ConvertStringFormatException();
	if (_f > INT_MAX || _f < INT_MIN)
		_int_imp = true;
	_n = static_cast<int>(_f);
	_c = static_cast<char>(_n);
	_d = static_cast<double>(_f);
	std::cout.precision(s.find("f") - s.find(".") - 1);
}

void	Convert::start_double(std::string s) {
	std::istringstream	iss(s);
	iss >> _d;
	if (iss.fail())
		throw ConvertStringFormatException();
	if (_d > INT_MAX || _d < INT_MIN)
		_int_imp = true;
	_n = static_cast<int>(_d);
	_c = static_cast<char>(_n);
	_f = static_cast<float>(_d);

	if (_d > __FLT_MAX__)
		_f = INFINITY;
	else if (_d < __FLT_MIN__)
		_f = INFINITY;
	std::cout.precision(s.length() - s.find(".") - 1);
}

void		Convert::print_nan_inf() const {
	std::cout << "Int: impossible" << std::endl;
	std::cout << "Char: impossible" << std::endl;
	std::cout << "Float: " << _f << "f" << std::endl;
	std::cout << "Double: " << _d << std::endl;
}

void		Convert::print() const {
	if (_nan_inf)
		print_nan_inf();
	else {
		_int_imp ? (std::cout << "Int: impossible" << std::endl) : (std::cout << "Int: " << _n << std::endl);
		(std::isprint(static_cast<unsigned char>(_n))) ? (std::cout << "Char: '" <<  _c << "'" << std::endl) : (std::cout << "Char: Non-printable character" << std::endl);
		std::cout << "Float: " << _f << "f" << std::endl;
		std::cout << "Double: " << _d << std::endl;
	}
}

Convert::ConvertStringFormatException::ConvertStringFormatException() : exception() {}
Convert::ConvertStringFormatException::ConvertStringFormatException(const ConvertStringFormatException&) : exception() {}
Convert::ConvertStringFormatException::~ConvertStringFormatException() _NOEXCEPT {}
const char* Convert::ConvertStringFormatException::what() const _NOEXCEPT {
	return ("ConvertStringFormatException");
}