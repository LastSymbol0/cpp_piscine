/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aillia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 15:02:57 by aillia            #+#    #+#             */
/*   Updated: 2019/10/08 15:02:58 by aillia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

Bureaucrat::Bureaucrat() : _name("Unnamed"), _grade(150) {}
Bureaucrat::Bureaucrat(std::string name) : _name(name), _grade(150) {}
Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) {
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	_grade = grade;;
}

Bureaucrat::Bureaucrat(const Bureaucrat& a) : _name(a._name), _grade(a._grade) {}
Bureaucrat::~Bureaucrat() {}

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& a)
{
	os << "Bureaucrat " << a.getName() << ", has grade " << a.getGrade();
	return (os);
}

Bureaucrat&	Bureaucrat::operator=(Bureaucrat& a)
{
	_grade = a._grade;
	return (*this);
}

std::string	Bureaucrat::getName() const { return(_name); }
int			Bureaucrat::getGrade() const { return(_grade); }

void		Bureaucrat::incrementGrade() {
	if (_grade - 1 < 1)
		throw GradeTooHighException();
	_grade--;
}

void		Bureaucrat::decrementGrade() {
	if (_grade + 1 > 150)
		throw GradeTooLowException();
	_grade++;
}

void		Bureaucrat::signForm(Form &f) const {
	try {
		f.beSigned(*this);
		std::cout <<  "Bureaucrat " << getName() << " signs form: " << f.getName() << std::endl;
	} catch(const std::exception& e) {
		std::cerr <<  "Bureaucrat " << getName() << " cannot sign form: " << f.getName() << ". Reason: "  << e.what() << std::endl;
	}

}

void		Bureaucrat::executeForm(Form const & form) const {
	try {
		std::cout <<  "Bureaucrat " << getName() << " executes form: " << form.getName() << std::endl;
		form.execute(*this);
	} catch(const std::exception& e) {
		std::cerr <<  "Bureaucrat " << getName() << " cannot execute form: " << form.getName() << ". Reason: "  << e.what() << std::endl;
	}
}


Bureaucrat::GradeTooHighException::GradeTooHighException() : exception() {}
Bureaucrat::GradeTooHighException::GradeTooHighException(const GradeTooHighException&) : exception() {}
Bureaucrat::GradeTooHighException::~GradeTooHighException() _NOEXCEPT {}
const char* Bureaucrat::GradeTooHighException::what() const _NOEXCEPT {
	return ("GradeTooHighException");
}

Bureaucrat::GradeTooLowException::GradeTooLowException() : exception() {}
Bureaucrat::GradeTooLowException::GradeTooLowException(const GradeTooLowException&) : exception() {}
Bureaucrat::GradeTooLowException::~GradeTooLowException() _NOEXCEPT {}
const char* Bureaucrat::GradeTooLowException::what() const _NOEXCEPT {
	return ("GradeTooLowException");
}

