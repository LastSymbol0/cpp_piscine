/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aillia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 20:42:03 by aillia            #+#    #+#             */
/*   Updated: 2019/10/08 20:42:04 by aillia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("RobotomyRequestForm", 72, 45), _target(target) {}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& a) : Form(a) {}
RobotomyRequestForm::~RobotomyRequestForm() {}

void	RobotomyRequestForm::action() const {
	std::cout << "*somedrilling noises*";
	if (rand() % 2 == 1) 
		std::cout << _target << " has been robotomized successfully" << std::endl;
	else
		std::cout << _target << " hasn't been robotomized successfully" << std::endl;	
}