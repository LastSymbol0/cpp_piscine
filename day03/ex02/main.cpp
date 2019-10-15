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
	fragtrap.~FragTrap();

	ScavTrap scavtrap("scavtrap");
	scavtrap.rangedAttack("Badass");
	scavtrap.meleeAttack("fragtrap");
	scavtrap.takeDamage(20);
	scavtrap.takeDamage(120);
	scavtrap.beRepaired(50);
	scavtrap.beRepaired(120);
	scavtrap.challengeNewcomer();
	return (0);
}
