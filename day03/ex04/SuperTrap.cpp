/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aillia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 20:39:39 by aillia            #+#    #+#             */
/*   Updated: 2019/10/04 20:39:41 by aillia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SuperTrap.hpp"
#include <iostream>
#define GREEN "\033[32m"
#define RED "\033[31m"
#define RED_B "\033[21m"
#define YELLOW "\033[33m"
#define CYAN "\033[36m"
#define MAGENTA "\033[35m"
#define BLUE "\033[34m"
#define N "\033[0m"

SuperTrap::SuperTrap	(std::string name) : ClapTrap(name), NinjaTrap(name), FragTrap(name) 
{
	this->_name = name;
	_hit_p = FragTrap::_hit_p;
	_max_hit_p = FragTrap::_max_hit_p;
	_energy_p = NinjaTrap::_energy_p;
	_max_energy_p = NinjaTrap::_max_energy_p;
	_level = 1;
	_melee_att_dmg = NinjaTrap::_melee_att_dmg;
	_range_att_dmg = FragTrap::_range_att_dmg;
	_arm_dmg_reduct = FragTrap::_arm_dmg_reduct;
	std::cout << CYAN << "[SuperTrap <" << _name << ">]: " << MAGENTA << "(Created) " << CYAN << "It's a trap! Super trap!" << std::endl << N;
}

SuperTrap::SuperTrap	(const SuperTrap& a) : ClapTrap(a), NinjaTrap(a), FragTrap(a) 
{
	_name = a._name;
	_hit_p = a._hit_p;
	_max_hit_p = a._max_hit_p;
	_energy_p = a._energy_p;
	_max_energy_p = a._max_energy_p;
	_level = a._level;
	_melee_att_dmg = a._melee_att_dmg;
	_range_att_dmg = a._range_att_dmg;
	_arm_dmg_reduct = a._arm_dmg_reduct;
}

SuperTrap::~SuperTrap(void)
{
	std::cout << CYAN << "[SuperTrap <" << _name << ">]: " << MAGENTA << "(Destroyed) " << CYAN << "Seppuku" << std::endl << N;
}

SuperTrap&	SuperTrap::operator=(SuperTrap& a)
{
	_name = a._name;
	_hit_p = a._hit_p;
	_max_hit_p = a._max_hit_p;
	_energy_p = a._energy_p;
	_max_energy_p = a._max_energy_p;
	_level = a._level;
	_melee_att_dmg = a._melee_att_dmg;
	_range_att_dmg = a._range_att_dmg;
	_arm_dmg_reduct = a._arm_dmg_reduct;
	return (*this);
}