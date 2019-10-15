/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aillia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 16:56:40 by aillia            #+#    #+#             */
/*   Updated: 2019/10/11 16:56:44 by aillia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "Fixed.class.hpp"
#include <string>
#include <iostream>

template<typename T>
void	display(T a) {
	std::cout << a;
}

template<typename T>
void	iter(T *arr, size_t len, void (* f)(T a)) {
	for (size_t i = 0; i < len; i++){
		(* f)(arr[i]);
	}
}

void	display_ch(char a) {
	std::cout << a;
}

int		main()
{
	char	carr[7] = {'a', 'b', 'c', 'd', 'e', 'f', 'g'};
	::iter(carr, 7, display);
	std::cout << std::endl;
	::iter(carr, 7, display_ch);
	std::cout << std::endl;

	int		iarr[7] = {1, 2, 3, 4, 5, 6, 7};
	::iter(iarr, 7, display);
	std::cout << std::endl;

	double	darr[7] = {1.1111, 2.2222, 3.3333, 4.4444, 5.5555, 6.6666, 7.7777};
	::iter(darr, 7, display);
	std::cout << std::endl;

	std::string	sarr[3] = {"Some", "String", "Array"};
	::iter(sarr, 3, display);
	std::cout << std::endl;

	// Fixed	farr[7] = {1.1111f, 2.2222f, 3.3333f, 4.4444f, 5.5555f, 6.6666f, 7.7777f};
	// ::iter(farr, 7, display);
	// std::cout << std::endl;
	return (0);
}
