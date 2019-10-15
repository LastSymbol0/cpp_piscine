/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aillia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 22:01:42 by aillia            #+#    #+#             */
/*   Updated: 2019/10/02 22:01:44 by aillia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name)
{
	this->name = name;
}

void	HumanB::setWeapon(Weapon weapon)
{
	this->weapon = weapon;
}

void	HumanB::attack(void)
{
	std::cout << name << " attacks with his " << weapon.getType() << std::endl;
}