/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aillia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 19:10:10 by aillia            #+#    #+#             */
/*   Updated: 2019/10/04 19:10:11 by aillia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>
#define GREEN "\033[32m"
#define RED "\033[31m"
#define YELLOW "\033[33m"
#define CYAN "\033[36m"
#define MAGENTA "\033[35m"
#define BLUE "\033[34m"
#define N "\033[0m"

ClapTrap::ClapTrap(std::string name)
{
	_name = name;
	_hit_p = 100;
	_max_hit_p = 100;
	_energy_p = 100;
	_max_energy_p = 100;
	_level = 1;
	_melee_att_dmg = 30;
	_range_att_dmg = 20;
	_arm_dmg_reduct = 5;
	std::cout << YELLOW << "[ClapTrap <" << _name << ">]: " << MAGENTA << "(Created) " << std::endl << N;
}

ClapTrap::~ClapTrap()
{
	std::cout << YELLOW << "[ClapTrap <" << _name << ">]: " << MAGENTA << "(Destroyed) " << std::endl << N;
}

ClapTrap::ClapTrap	(const ClapTrap& a)
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

ClapTrap&	ClapTrap::operator=(ClapTrap& a)
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

void	ClapTrap::rangedAttack(std::string const & target) {
	std::cout << YELLOW << "[ClapTrap <" << _name << ">]: " << YELLOW
	<< "(Range attack; damage: " << _range_att_dmg << ", target: " << target << ") " << CYAN
	<< "Hot potato!" << std::endl << N;
}

void	ClapTrap::meleeAttack(std::string const & target) {
	std::cout << YELLOW << "[ClapTrap <" << _name << ">]: " << YELLOW
	<< "(Melee attack; damage: " << _melee_att_dmg << ", target: " << target <<	") " << CYAN
	<< "Heyyah!" << std::endl << N;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	(_hit_p > (amount - _arm_dmg_reduct)) ? (_hit_p -= amount - _arm_dmg_reduct) : _hit_p = 0;

	std::cout << YELLOW << "[ClapTrap <" << _name << ">]: " << RED
	<< "(Take damage: -" << amount << ", now have:" << _hit_p << ")" << CYAN
	<< " Ow hohoho, that hurts! Yipes!" << std::endl << N;
	if (_hit_p == 0)
		std::cout << YELLOW << "[ClapTrap <" << _name << ">]: " << CYAN << "Crit-i-cal!" << std::endl << N;
}

void	 ClapTrap::beRepaired(unsigned int amount) {
	_hit_p + amount > _max_hit_p ? _hit_p = _max_hit_p : _hit_p += amount;

	std::cout << YELLOW << "[ClapTrap <" << _name << ">]: " << GREEN
	<< "(Repaired on: " << amount << ", now have:" << _hit_p << ")" << CYAN
	<< " Sweet life juice!" << std::endl << N;
}