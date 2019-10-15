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

#include "CentralBureaucracy.hpp"
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
	CentralBureaucracy central;

	for (int i = 0; i < 20; i++) {
		central.feed(new Bureaucrat("Hermes Conrad", 37));
		central.feed(new  Bureaucrat("Bobby Bobson", 23));
	}
	try {
		for (int i = 0; i < 20; i++) {
			central.queueUp("Artur Dent");
			central.queueUp("Zaphod Beeblebrox");
			central.queueUp("Ford");
			central.queueUp("You");
			central.queueUp("Marvin");
		}
		central.doBureaucracy();
		central.doBureaucracy();
		central.doBureaucracy();
		central.doBureaucracy();
		central.doBureaucracy();
		central.doBureaucracy();
		central.doBureaucracy();
		central.doBureaucracy();
		central.doBureaucracy();
		central.doBureaucracy();
		central.doBureaucracy();
		central.doBureaucracy();
		central.doBureaucracy();
	} catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	

}