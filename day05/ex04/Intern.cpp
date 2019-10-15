/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aillia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 14:29:12 by aillia            #+#    #+#             */
/*   Updated: 2019/10/09 14:29:14 by aillia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

Intern::Intern() {}
Intern::Intern(const Intern& a) { (void)a; }
Intern::~Intern() {}

Intern&		Intern::operator=(Intern& a) { (void)a; return (*this); }

Form		*Intern::makeForm(std::string type, std::string target) {
	if (type == "presidential pardon") {
		std::cout << "Intern creates presidential pardon form" << std::endl;
		return new PresidentialPardonForm(target);
	}
	else if (type == "robotomy request") {
		std::cout << "Intern creates robotomy request form" << std::endl;
		return new RobotomyRequestForm(target);
	}
	else if (type == "shrubbery creation") {
		std::cout << "Intern creates shrubbery creation form" << std::endl;
		return new ShrubberyCreationForm(target);
	}
	std::cout << "Intern don't know this type of form: " << type << std::endl;
	throw UnknownFormTypeException();
	return nullptr;
}

Intern::UnknownFormTypeException::UnknownFormTypeException() : exception() {}
Intern::UnknownFormTypeException::UnknownFormTypeException(const UnknownFormTypeException&) : exception() {}
Intern::UnknownFormTypeException::~UnknownFormTypeException() _NOEXCEPT {}
const char* Intern::UnknownFormTypeException::what() const _NOEXCEPT {
	return ("UnknownFormTypeException");
}