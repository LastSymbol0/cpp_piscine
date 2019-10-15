/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aillia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 19:36:43 by aillia            #+#    #+#             */
/*   Updated: 2019/10/11 19:36:45 by aillia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "Fixed.class.hpp"
#include "Array.hpp"
#include <iostream>
#include <string>

// void	fixed_test()
// {
// 	Array<Fixed> f(10);

// 	std::cout << "My fixed:" << std::endl;
// 	for (size_t i = 0; i < 10; i++) {
// 		f[i] = static_cast<float>(i / 4.2);
// 	}
// 	for (size_t i = 0; i < 10; i++) {
// 		std::cout << f[i] << " ";
// 	}
// }

int		main()
{
	Array<std::string> a(10);
	Array<int> b(10);
	Array<double> c(10);

	std::cout << "Init" << std::endl;
	std::cout << "String\t\tInt\t\tDouble" << std::endl;
	for (size_t i = 0; i < 10; i++)
	{
		std::cout << "" << a[i];
		std::cout << "\t\t" << b[i];
		std::cout << "\t\t" << c[i] << std::endl;
	}
	std::cout << std::endl << "Rewrite" << std::endl;
	std::cout << "String\t\tInt\t\tDouble" << std::endl;
	for (size_t i = 0; i < 10; i++)
	{
		a[i] = static_cast<char>(i + 48);
		b[i] = static_cast<int>(i);
		c[i] = static_cast<double>(i) * i;
	}
	for (size_t i = 0; i < 10; i++)
	{
		std::cout << "" << a[i];
		std::cout << "\t\t" << b[i];
		std::cout << "\t\t" << c[i] << std::endl;
	}

	Array<double> cc(c);
	std::cout << std::endl << "Init new double arr by copy constructor" << std::endl;
	std::cout << "Double\t\tDouble 2" << std::endl;
	// b = c;
	for (size_t i = 0; i < 10; i++)
	{
		std::cout << "" << c[i];
		std::cout << "\t\t" << cc[i] << std::endl;
	}
	std::cout << std::endl << "Rewrite double 2" << std::endl;
	std::cout << "Double\t\tDouble 2" << std::endl;
	for (size_t i = 0; i < 10; i++) {
		cc[i] = static_cast<double>(i) * 4.2;
	}
	for (size_t i = 0; i < 10; i++)
	{
		std::cout << "" << c[i];
		std::cout << "\t\t" << cc[i] << std::endl;
	}

	std::cout << std::endl << "Init double 1 arr by assign overload" << std::endl;
	std::cout << "Double\t\tDouble 2" << std::endl;
	c = cc;
	for (size_t i = 0; i < 10; i++)
	{
		std::cout << "" << c[i];
		std::cout << "\t\t" << cc[i] << std::endl;
	}
	std::cout << "Rewrite double 1" << std::endl;
	std::cout << "Double\t\tDouble 2" << std::endl;
	for (size_t i = 0; i < 10; i++) {
		c[i] = static_cast<double>(i) * 42;
	}
	for (size_t i = 0; i < 10; i++)
	{
		std::cout << "" << c[i];
		std::cout << "\t\t" << cc[i] << std::endl;
	}

	// fixed_test();

	try	{
		a[13] = "dew";
	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	
	return (0);
}

