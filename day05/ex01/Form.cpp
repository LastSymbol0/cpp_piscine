/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aillia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 18:17:57 by aillia            #+#    #+#             */
/*   Updated: 2019/10/08 18:17:59 by aillia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

Form::Form() : _name("Unnamed"), _signed(false), _grade_to_sign(150), _grade_to_execute(150) {}
Form::Form(std::string name) : _name(name), _signed(false), _grade_to_sign(150), _grade_to_execute(150) {}
Form::Form(std::string name, int grade_to_sign, int grade_to_execute) : _name(name), _grade_to_sign(grade_to_sign), _grade_to_execute(grade_to_execute) {
	if (grade_to_sign < 1 || grade_to_execute < 1)
		throw GradeTooHighException();
	if (grade_to_sign > 150 || grade_to_execute > 150)
		throw GradeTooLowException();
}

Form::Form(const Form& a) : _name(a.getName()), _signed(a.getSigned()), _grade_to_sign(a.getGradeToSign()), _grade_to_execute(a.getGradeToExecute()) {}
Form::~Form() {}

std::ostream&	operator<<(std::ostream& os, const Form& a)
{
	os << "Form " << a.getName() << "(" << (a.getSigned() == true ? "Signed" : "Not Signed") << ")"<< ", has grade to sign: " << a.getGradeToSign() << "; grade to execute: " << a.getGradeToExecute();
	return (os);
}

std::string	Form::getName() const { return(_name); }
bool		Form::getSigned() const { return(_signed); }
int			Form::getGradeToSign() const { return(_grade_to_sign); }
int			Form::getGradeToExecute() const { return(_grade_to_execute); }

void		Form::beSigned(const Bureaucrat b) {
	if (b.getGrade() > getGradeToSign())
		throw GradeTooLowException();
	if (_signed)
		throw AlreadySignedException();
	_signed = true;
}

Form::GradeTooHighException::GradeTooHighException() : exception() {}
Form::GradeTooHighException::GradeTooHighException(const GradeTooHighException&) : exception() {}
Form::GradeTooHighException::~GradeTooHighException() _NOEXCEPT {}
const char* Form::GradeTooHighException::what() const _NOEXCEPT {
	return ("GradeTooHighException");
}

Form::GradeTooLowException::GradeTooLowException() : exception() {}
Form::GradeTooLowException::GradeTooLowException(const GradeTooLowException&) : exception() {}
Form::GradeTooLowException::~GradeTooLowException() _NOEXCEPT {}
const char* Form::GradeTooLowException::what() const _NOEXCEPT {
	return ("GradeTooLowException");
}

Form::AlreadySignedException::AlreadySignedException() : exception() {}
Form::AlreadySignedException::AlreadySignedException(const AlreadySignedException&) : exception() {}
Form::AlreadySignedException::~AlreadySignedException() _NOEXCEPT {}
const char* Form::AlreadySignedException::what() const _NOEXCEPT {
	return ("AlreadySignedException");
}
