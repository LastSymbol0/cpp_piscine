/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aillia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 13:56:32 by aillia            #+#    #+#             */
/*   Updated: 2019/10/12 13:56:35 by aillia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"
// #include <iostream>

span::span() {}
span::span(unsigned int n) : _size(n) { _v.reserve(n); }

span::span(const span& a) {
	_v = a.getV();
	_size = a.getSize();
}

span::~span() { _v.clear(); }

span&	span::operator=(span& a) {
	_v = a.getV();
	_size = a.getSize();
	return (*this);
}

std::vector<int>		span::getV() const { return(_v); }
unsigned int	span::getSize() const { return(_size); }

void			span::addNumber(int n) {
	if (_v.size() + 1 > _size)
		throw std::length_error("Too many elements exception");
	_v.push_back(n);
	_is_sort = false;
	// std::cout << n << " ";
}

int				span::shortestSpan() {
	if (_v.empty() || _v.size() < 2)
		throw std::logic_error("Not enough elements exception");
	if (!_is_sort)
		std::sort(_v.begin(), _v.end());
	_is_sort = true;
	int	span = INT_MAX;
	std::vector<int>::iterator it = _v.begin();
	while (++it != _v.end())
		if (*it - *(it - 1) < span)
			span = *it - *(it - 1);
	return (span);
}

int				span::longestSpan() {
	if (_v.empty() || _v.size() < 2)
		throw std::logic_error("Not enough elements exception");
	if (!_is_sort)
		std::sort(_v.begin(), _v.end());
	_is_sort = true;
	return (*(_v.end() - 1) - *(_v.begin()));
}

