/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aillia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 22:01:04 by aillia            #+#    #+#             */
/*   Updated: 2019/10/02 22:01:06 by aillia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon()
{
	this->type = "None";
}

Weapon::Weapon(std::string type)
{
	this->type = type;
}

void				Weapon::setType(std::string type)
{
	this->type = type;
}

const std::string&	Weapon::getType(void)
{
	return (type);
}
