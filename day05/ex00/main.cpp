/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aillia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 15:03:06 by aillia            #+#    #+#             */
/*   Updated: 2019/10/08 15:03:07 by aillia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int	main()
{
	Bureaucrat b("Jack", 149);
	Bureaucrat nb("Not Jack", 2);

	try {
		b.decrementGrade();
		b.decrementGrade();
		b.decrementGrade();
	} catch (std::exception& e) {
		std::cout << b << "\t\tException: " << e.what() << std::endl;
	}

	try {
		nb.incrementGrade();
		nb.incrementGrade();
		nb.incrementGrade();
	} catch (std::exception& e) {
		std::cout << nb << "\tException: " << e.what() << std::endl;
	}

	try {
		Bureaucrat a("Jack", 151);
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
	try {
		Bureaucrat na("Not Jack",-54);
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}


}