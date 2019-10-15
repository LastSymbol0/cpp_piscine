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
#include "Intern.hpp"
#include <iostream>

int	main()
{
	Bureaucrat b("Jack", 149);
	Bureaucrat nb("Not Jack", 2);

	Intern intern;

	Form *f1;

	try {
		f1 = intern.makeForm("presidential pardon", "Artur");
		nb.signForm(*f1);
		nb.executeForm(*f1);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	// std::cout << std::endl << std::endl << nb << std::endl << f1 << std::endl << f2 << std::endl << std::endl;

	return (0);
}