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

#include "OfficeBlock.hpp"
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"
#include <iostream>

int main()
{
	Intern idiotOne;
	Bureaucrat hermes = Bureaucrat("Hermes Conrad", 37);
	Bureaucrat bob = Bureaucrat("Bobby Bobson", 23);

	OfficeBlock ob;
	ob.setIntern(&idiotOne);
	ob.setSigner(&bob);
	ob.setExecutor(&hermes);
	try {
		ob.doBureaucracy("robotomy request", "Pigley");
	} catch (OfficeBlock::NotEnoughHandsException::NotEnoughHandsException& e) {
		std::cerr << "Wow, i know this exeption! This is " << e.what() << std::endl;
	} catch (std::exception& e) {
		std::cerr << "Shit, i don't know this exeption :( " << e.what() << std::endl;
	}
}