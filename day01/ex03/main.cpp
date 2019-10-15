/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aillia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 20:02:05 by aillia            #+#    #+#             */
/*   Updated: 2019/10/02 20:02:07 by aillia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieHorde.hpp"
#include <iostream>

int		main(void)
{
	ZombieHorde *zombieHorde = new ZombieHorde(10);

	std::cout << "------------------------------------" << std::endl;
	zombieHorde->announce();
	return (0);
}
