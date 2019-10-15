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
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

int	main()
{
	Bureaucrat b("Jack", 149);
	Bureaucrat nb("Not Jack", 2);

	PresidentialPardonForm f1("Trilian");
	PresidentialPardonForm f2("Artur Dent");
	RobotomyRequestForm r1("Marvin");
	RobotomyRequestForm r2("Marvin");
	ShrubberyCreationForm p1("Ford Prefect");
	ShrubberyCreationForm p2("You");

	// std::cout << b << std::endl << f1 << std::endl << f2 << std::endl << std::endl;
	// b.signForm(f2);
	// b.signForm(f1);

	// std::cout << std::endl << std::endl << nb << std::endl << f1 << std::endl << f2 << std::endl << std::endl;
	nb.signForm(f2);
	nb.signForm(f1);
	nb.executeForm(f1);
	nb.executeForm(f2);


	// std::cout << b << std::endl << r1 << std::endl << r2 << std::endl << std::endl;
	b.signForm(r2);
	b.signForm(r1);
	nb.executeForm(r1);
	nb.executeForm(r2);

	// std::cout << b << std::endl << p1 << std::endl << p2 << std::endl << std::endl;
	nb.signForm(p2);
	b.signForm(p1);
	b.executeForm(p1);
	nb.executeForm(p2);

	return (0);
}