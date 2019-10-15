/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aillia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 20:42:23 by aillia            #+#    #+#             */
/*   Updated: 2019/10/08 20:42:24 by aillia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form("PresidentialPardonForm", 25, 5), _target(target) {}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& a) : Form(a) {}
PresidentialPardonForm::~PresidentialPardonForm() {}

void	PresidentialPardonForm::action() const{
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}