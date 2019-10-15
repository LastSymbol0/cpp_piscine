/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aillia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 15:56:13 by aillia            #+#    #+#             */
/*   Updated: 2019/10/04 15:56:14 by aillia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "SuperTrap.hpp"
#include "NinjaTrap.hpp"
#include <iostream>

int	main(void)
{
	FragTrap fragtrap("fragtrap");

	fragtrap.rangedAttack("frog");
	fragtrap.meleeAttack("you");
	fragtrap.takeDamage(20);
	fragtrap.takeDamage(120);
	fragtrap.beRepaired(50);
	fragtrap.beRepaired(120);
	fragtrap.vaulthunter_dot_exe("refrigerator");

	ScavTrap scavtrap("scavtrap");
	scavtrap.rangedAttack("Badass");
	scavtrap.meleeAttack("fragtrap");
	scavtrap.takeDamage(20);
	scavtrap.takeDamage(120);
	scavtrap.beRepaired(50);
	scavtrap.beRepaired(120);
	scavtrap.challengeNewcomer();

	NinjaTrap ninjatrap("ninjatrap");
	ninjatrap.rangedAttack("Badass");
	ninjatrap.meleeAttack("fragtrap");
	ninjatrap.takeDamage(20);
	ninjatrap.takeDamage(120);
	ninjatrap.beRepaired(50);
	ninjatrap.beRepaired(120);

	NinjaTrap new_ninja("new_ninja");
	ninjatrap.ninjaShoebox(scavtrap);
	ninjatrap.ninjaShoebox(fragtrap);
	ninjatrap.ninjaShoebox(new_ninja);
	ninjatrap.ninjaShoebox(fragtrap);

	std::cout << std::endl;
	SuperTrap supertrap("supertrap");
	supertrap.rangedAttack("frog");
	supertrap.meleeAttack("you");
	supertrap.vaulthunter_dot_exe("stone table");
	supertrap.ninjaShoebox(ninjatrap);

	return (0);
}
