/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aillia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 19:47:25 by aillia            #+#    #+#             */
/*   Updated: 2019/10/11 19:47:26 by aillia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdexcept>
#include <cstring>

template<typename T>
class Array
{
private:
	T		*_arr;
	size_t	_size;

public:
	Array();
	Array(unsigned int n);
	Array(const Array& a);
	~Array();

	Array&	operator=(Array& a);
	T&		operator[](size_t i) const;

	size_t	size(void) const;
};

#include "Array.tpp"
 