/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aillia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 15:55:56 by aillia            #+#    #+#             */
/*   Updated: 2019/10/04 15:55:57 by aillia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>
#define GREEN "\033[32m"
#define RED "\033[31m"
#define YELLOW "\033[33m"
#define CYAN "\033[36m"
#define MAGENTA "\033[35m"
#define N "\033[0m"

const std::string s[11] = {
	"Step right up, to the Bulletnator 9000!",
	"I am a tornado of death and bullets!",
	"Stop me before I kill again, except don't!",
	"Hehehehe, mwaa ha ha ha, MWAA HA HA HA!",
	"I'm on a roll!",
	"Unts unts unts unts!",
	"Ha ha ha! Fall before your robot overlord!",
	"Can't touch this!",
	"Ha! Keep 'em coming!",
	"There is no way this ends badly!",
	"This is why I was built!",
};

FragTrap::FragTrap	(std::string name)
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
	std::cout << "[FR4G-TP <" << _name << ">]: " << MAGENTA << "(Created) " << CYAN << "This time it'll be awesome, I promise!" << std::endl << N;
}

FragTrap::FragTrap	(const FragTrap& a)
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

FragTrap::~FragTrap(void)
{
	std::cout << "[FR4G-TP <" << _name << ">]: " << MAGENTA << "(Destroyed) " << CYAN << "Extra ouch!" << std::endl << N;
}

FragTrap&	FragTrap::operator=(FragTrap& a)
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

void	FragTrap::rangedAttack(std::string const & target) {
	std::cout << "[FR4G-TP <" << _name << ">]: " << YELLOW
	<< "(Range attack; damage: " << _range_att_dmg << ", target: " << target << ") " << CYAN
	<< "Eat bomb, baddie!" << std::endl << N;
}

void	FragTrap::meleeAttack(std::string const & target) {
	std::cout << "[FR4G-TP <" << _name << ">]: " << YELLOW
	<< "(Melee attack; damage: " << _melee_att_dmg << ", target: " << target <<	") " << CYAN
	<< "Take that!" << std::endl << N;
}

void	FragTrap::takeDamage(unsigned int amount) {
	(_hit_p > (amount - _arm_dmg_reduct)) ? (_hit_p -= amount - _arm_dmg_reduct) : _hit_p = 0;

	std::cout << "[FR4G-TP <" << _name << ">]: " << RED
	<< "(Take damage: -" << amount << ", now have:" << _hit_p << ")" << CYAN
	<< " Hit me, baby!" << std::endl << N;
	if (_hit_p == 0)
		std::cout << "[FR4G-TP <" << _name << ">]: " << CYAN << "I can't feel my fingers! Gah! I don't have any fingers!" << std::endl << N;
}

void	 FragTrap::beRepaired(unsigned int amount) {
	_hit_p + amount > _max_hit_p ? _hit_p = _max_hit_p : _hit_p += amount;

	std::cout << "[FR4G-TP <" << _name << ">]: " << GREEN
	<< "(Repaired on: " << amount << ", now have:" << _hit_p << ")" << CYAN
	<< " Sweet life juice!" << std::endl << N;
}

void	FragTrap::vaulthunter_dot_exe(std::string const & target)
{
	if (_energy_p < 25) {
		std::cout << "[FR4G-TP <" << _name << ">]: " << YELLOW << "(Vaulthunter.EXE activated; not enought energy: 25 needed, " << _energy_p << " left)" << CYAN << "My assets... frozen!" << std::endl << N;
		return ;
	}
	_energy_p -= 25;
	srand(time(NULL));
	std::cout << "[FR4G-TP <" << _name << ">]: " << YELLOW << "(Vaulthunter.EXE activated; 25 energy points lost, " << _energy_p << " left) "  << CYAN << s[rand() % 11] << std::endl << N;
	if (rand() % 2 == 1)
		rangedAttack(target);
	else
		meleeAttack(target);
}
