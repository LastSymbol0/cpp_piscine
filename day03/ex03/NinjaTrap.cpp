/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aillia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 19:45:26 by aillia            #+#    #+#             */
/*   Updated: 2019/10/04 19:45:28 by aillia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NinjaTrap.hpp"
#include <iostream>
#define GREEN "\033[32m"
#define RED "\033[31m"
#define RED_B "\033[21m"
#define YELLOW "\033[33m"
#define CYAN "\033[36m"
#define MAGENTA "\033[35m"
#define BLUE "\033[34m"
#define N "\033[0m"

NinjaTrap::NinjaTrap	(std::string name) : ClapTrap(name)
{
	_name = name;
	_hit_p = 60;
	_max_hit_p = 60;
	_energy_p = 120;
	_max_energy_p = 120;
	_level = 1;
	_melee_att_dmg = 60;
	_range_att_dmg = 5;
	_arm_dmg_reduct = 0;
	std::cout << CYAN << "[FR4G-TP <" << _name << ">]: " << MAGENTA << "(Created) " << CYAN << "It's ninja time!" << std::endl << N;
}

NinjaTrap::NinjaTrap	(const NinjaTrap& a) : ClapTrap(a)
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

NinjaTrap::~NinjaTrap(void)
{
	std::cout << CYAN << "[FR4G-TP <" << _name << ">]: " << MAGENTA << "(Destroyed) " << CYAN << "Seppuku" << std::endl << N;
}

NinjaTrap&	NinjaTrap::operator=(NinjaTrap& a)
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

void		NinjaTrap::ninjaShoebox(FragTrap& a)
{
	std::cout << RED_B << "\\\\ NinjaTrap vs FragTrap //" << std::endl << "\tFIGHT!" << std::endl << N;
	meleeAttack("frag trap");
	a.takeDamage(_melee_att_dmg);
	a.meleeAttack("ninja trap");
	takeDamage(a._melee_att_dmg);
	if (a._hit_p > _hit_p)
		std::cout << RED_B << "\\\\ FragTrap win! //" << std::endl << N;
	else
		std::cout << RED_B << "\\\\ NinjaTrap win! //" << std::endl << N;
}

void		NinjaTrap::ninjaShoebox(ScavTrap& a)
{
	std::cout << RED_B << "\\\\ NinjaTrap vs ScavTrap //" << std::endl << "\tFIGHT!" << std::endl << N;
	a.challengeNewcomer();
	rangedAttack("scav trap");
	a.takeDamage(_range_att_dmg);
	a.rangedAttack("ninja trap");
	takeDamage(a._range_att_dmg);
	if (a._hit_p > _hit_p)
		std::cout << RED_B << "\\\\ ScavTrap win! //" << std::endl << N;
	else
		std::cout << RED_B << "\\\\ NinjaTrap win! //" << std::endl << N;
}

void		NinjaTrap::ninjaShoebox(NinjaTrap& a)
{
	std::cout << RED_B << "\\\\ NinjaTrap vs NinjaTrap //" << std::endl << "\tCHILL!" << std::endl << N;
	a.beRepaired(30);
	beRepaired(30);
	std::cout << RED_B << "Nice chill!"  << std::endl << N;
}
