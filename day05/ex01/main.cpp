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
#include <iostream>

int	main()
{
	Bureaucrat b("Jack", 149);
	Bureaucrat nb("Not Jack", 2);
	Form f1;
	Form f2("Some paper", 1, 3);

	std::cout << b << std::endl << f1 << std::endl << f2 << std::endl << std::endl;
	b.signForm(f2);
	b.signForm(f1);

	std::cout << std::endl << std::endl << nb << std::endl << f1 << std::endl << f2 << std::endl << std::endl;
	nb.signForm(f2);
	nb.signForm(f1);
	nb.incrementGrade();
	nb.signForm(f2);

	return (0);
}