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

int	main(void)
{
	FragTrap claptrap("claptrap");

	claptrap.rangedAttack("frog");
	claptrap.meleeAttack("you");
	claptrap.takeDamage(20);
	claptrap.takeDamage(120);
	claptrap.beRepaired(50);
	claptrap.beRepaired(120);
	claptrap.vaulthunter_dot_exe("refrigerator");
}
