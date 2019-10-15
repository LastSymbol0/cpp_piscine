/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aillia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 16:19:30 by aillia            #+#    #+#             */
/*   Updated: 2019/10/10 16:19:31 by aillia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
// #include 

void	fucking_werror_unused_variable_error(Base& b1, Base& b2) {
	b1 = b2;
	b2 = b1;
}

void	identify_from_pointer(Base *p) {
	A	*a;
	B	*b;
	C	*c;

	std::cout << "Identify class: ";
	if ((a = dynamic_cast<A*>(p)))
		std::cout << "A";
	else if ((b = dynamic_cast<B*>(p)))
		std::cout << "B";
	else if ((c = dynamic_cast<C*>(p)))
		std::cout << "C";
	else
		std::cout << "wtf, man?";
	std::cout << std::endl;
}

void	identify_from_reference(Base& p) {
	std::cout << "Identify class: ";

	try {
		A&	a = dynamic_cast<A&>(p);
		fucking_werror_unused_variable_error(a, a);
		std::cout << "A";
	} catch (const std::bad_cast& e) {	}

	try {
		B&	b = dynamic_cast<B&>(p);
		fucking_werror_unused_variable_error(b, b);
		std::cout << "B";
	} catch (const std::bad_cast& e) {	}

	try {
		C&	c = dynamic_cast<C&>(p);
		fucking_werror_unused_variable_error(c, c);
		std::cout << "C";
	} catch (const std::bad_cast& e) {	}

	std::cout << std::endl;
}

Base	*generate(void) {
	int		r = rand() % 3;

	std::cout << "Generate class: " << ((r == 0) ? "A" : ((r == 1) ? "B" : "C")) << std::endl;
	if (r == 0)
		return new A();
	else if (r == 1)
		return new B();
	return new C();
}

int main()
{
	srand(time(nullptr));

	Base	*b = generate();
	identify_from_pointer(b);
	identify_from_reference(*b);
	return (0);
}