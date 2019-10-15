/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aillia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 17:48:44 by aillia            #+#    #+#             */
/*   Updated: 2019/10/04 17:48:46 by aillia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>
#define GREEN "\033[32m"
#define RED "\033[31m"
#define YELLOW "\033[33m"
#define CYAN "\033[36m"
#define MAGENTA "\033[35m"
#define MAGENTA_B "\033[45m"
#define N "\033[0m"

ScavTrap::ScavTrap	(std::string name) : ClapTrap(name)
{
	_name = name;
	_hit_p = 100;
	_max_hit_p = 100;
	_energy_p = 50;
	_max_energy_p = 50;
	_level = 1;
	_melee_att_dmg = 20;
	_range_att_dmg = 15;
	_arm_dmg_reduct = 3;
	std::cout << MAGENTA << "[SC4V-TP <" << _name << ">]: " << MAGENTA << "(Created) " << CYAN << "Look out everybody! Things are about to get awesome!" << std::endl << N;
}

ScavTrap::ScavTrap	(const ScavTrap& a) : ClapTrap(a)
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

ScavTrap::~ScavTrap(void)
{
	std::cout << MAGENTA << "[SC4V-TP <" << _name << ">]: " << MAGENTA << "(Destroyed) " << CYAN << "Brrh... So cold... brrh..." << std::endl << N;
}

ScavTrap&	ScavTrap::operator=(ScavTrap& a)
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

void	ScavTrap::challengeNewcomer()
{
	srand(time(NULL));

	switch (rand()%5)
	{
	case 0:
		std::cout << MAGENTA << "[SC4V-TP <" << _name << ">]: " << YELLOW << "(Guards the gate) "
		<< CYAN	<< "It's a VERY important duty, as I'm not to let ANYONE in through here! Unless, of course, you're here as fresh meat for the recruitment grinder!" << std::endl << N;
		break;
	case 1:
		std::cout << MAGENTA << "[SC4V-TP <" << _name << ">]: " << YELLOW << "(Jumping) "
		<< CYAN	<< "Watch as we observe the rare and beautiful Clappy Bird!" << std::endl << N;
		break;
	case 2:
		std::cout << MAGENTA << "[SC4V-TP <" << _name << ">]: " << YELLOW << "(Try to make some poetry) "
		<< CYAN	<< "Roses are red and/Violets are blue/Wait... how many syllables was that?" << std::endl << N;
		break;
	case 3:
		std::cout << MAGENTA << "[SC4V-TP <" << _name << ">]: " << YELLOW << "(~) "
		<< CYAN	<< "I'm a sexy dinosaur! Rawr!" << std::endl << N;
		break;
	case 4:
		std::cout << MAGENTA << "[SC4V-TP <" << _name << ">]: " << YELLOW << "(Sexy dinosaur) "
		<< CYAN	<< "A million baddies, and you wanna hit me? Aww!" << std::endl << N;
		break;
	default:
		break;
	}
}