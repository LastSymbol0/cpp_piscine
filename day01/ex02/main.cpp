/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aillia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 19:21:42 by aillia            #+#    #+#             */
/*   Updated: 2019/10/02 19:21:44 by aillia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieEvent.hpp"

int		main(void)
{
	ZombieEvent	evt;
	Zombie		zombie_stack;
	Zombie		*zombie_heap;

	zombie_heap = evt.newZombie("AlreadyDead888");
	delete zombie_heap;

	zombie_heap = evt.randomChump();
	delete zombie_heap;

	evt.setZombieType("DevOps");
	zombie_heap = evt.newZombie("John Willis");
	delete zombie_heap;

	zombie_heap = evt.randomChump();
	delete zombie_heap;

	zombie_heap = evt.randomChump();
	delete zombie_heap;

	zombie_heap = evt.randomChump();
	delete zombie_heap;

	zombie_heap = evt.randomChump();
	delete zombie_heap;
	return (0);
}
