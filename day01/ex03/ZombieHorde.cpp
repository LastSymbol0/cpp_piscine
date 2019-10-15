/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aillia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 19:51:01 by aillia            #+#    #+#             */
/*   Updated: 2019/10/02 19:51:03 by aillia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieHorde.hpp"

ZombieHorde::ZombieHorde(int n)
{
	this->zombies_count = n;
	this->zombies = new Zombie[n];
}

ZombieHorde::~ZombieHorde()
{
	delete [] this->zombies;
}

void	ZombieHorde::announce(void)
{
	for (int i = 0; i < this->zombies_count; i++) {
		this->zombies[i].announce();
	}
}
