/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OfficeBlock.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aillia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 16:11:21 by aillia            #+#    #+#             */
/*   Updated: 2019/10/09 16:11:23 by aillia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "OfficeBlock.hpp"
#include "Form.hpp"
#include "Intern.hpp"
#include "Bureaucrat.hpp"

#include <iostream>

OfficeBlock::OfficeBlock() : _intern(nullptr), _signer(nullptr), _executor(nullptr) {}
OfficeBlock::OfficeBlock(Intern *intern, Bureaucrat *signer, Bureaucrat *execurtor) : _intern(intern), _signer(signer), _executor(execurtor) {}
OfficeBlock::~OfficeBlock() {}


void			OfficeBlock::setIntern(Intern *intern) { _intern = intern; }
void			OfficeBlock::setSigner(Bureaucrat *signer) { _signer = signer; }
void			OfficeBlock::setExecutor(Bureaucrat *executor) { _executor = executor; }

Bureaucrat		*OfficeBlock::getSigner() const { return(_signer); }
Bureaucrat		*OfficeBlock::getExecutor() const { return(_executor); }

void			OfficeBlock::doBureaucracy(std::string type, std::string target) {
	if (!_intern)
		_intern = new Intern();
	if (!_signer || !_executor)
		throw NotEnoughHandsException();
	Form *f;
	f = _intern->makeForm(type, target);
	_signer->signForm(*f);
	_executor->executeForm(*f);
}


OfficeBlock::NotEnoughHandsException::NotEnoughHandsException() : exception() {}
OfficeBlock::NotEnoughHandsException::NotEnoughHandsException(const NotEnoughHandsException&) : exception() {}
OfficeBlock::NotEnoughHandsException::~NotEnoughHandsException() _NOEXCEPT {}
const char* OfficeBlock::NotEnoughHandsException::what() const _NOEXCEPT {
	return ("NotEnoughHandsException");
}