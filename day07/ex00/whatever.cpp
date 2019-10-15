/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aillia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 15:58:33 by aillia            #+#    #+#             */
/*   Updated: 2019/10/11 15:58:34 by aillia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
// #include "Fixed.class.hpp"

template <typename T>
void	swap(T *a, T *b)
{
	T	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
template <typename T>
T		max(T a, T b)
{
	return (a > b ? a : b);
}
template <typename T>
T		min(T a, T b)
{
	return (a < b ? a : b);
}

void	check(void) {
	int a = 5, b = 10;
	std::cout << std::endl << "Int: " << std::endl;
	std::cout << "a: " << a << ";\t\tb: " << b << std::endl;
	::swap(&a, &b);
	std::cout << "a: " << a << ";\t\tb: " << b << std::endl;
	std::cout << "\tMax: " << ::max(a, b) << std::endl << "\tMin: " << ::min(a, b) << std::endl;

	double d1 = 5.55555555, d2 = 10.1010101010;
	std::cout << std::endl << "Double: " << std::endl;
	std::cout << "d1: " << d1 << ";\td2: " << d2 << std::endl;
	::swap(&d1, &d2);
	std::cout << "d1: " << d1 << ";\td2: " << d2 << std::endl;
	std::cout << "\tMax: " << ::max(d1, d2) << std::endl << "\tMin: " << ::min(d1, d2) << std::endl;


	std::string s1 = "5", s2 = "10";
	std::cout << std::endl << "String: " << std::endl;
	std::cout << "s1: " << s1 << ";\t\ts2: " << s2 << std::endl;
	::swap(&s1, &s2);
	std::cout << "s1: " << s1 << ";\t\ts2: " << s2 << std::endl;
	std::cout << "\tMax: " << ::max(s1, s2) << std::endl << "\tMin: " << ::min(s1, s2) << std::endl;


	// Fixed f1(5.5555f), f2 (10.1010f);
	// std::cout << std::endl << "Fixed: " << std::endl;
	// std::cout << "f1: " << f1 << ";\tf2: " << f2 << std::endl;
	// ::swap(&f1, &f2);
	// std::cout << "f1: " << f1 << ";\tf2: " << f2 << std::endl;
	// std::cout << "\tMax: " << ::max(f1, f2) << std::endl << "\tMin: " << ::min(f1, f2) << std::endl;
}

int		main(void)
{
	check();
	return (0);
}