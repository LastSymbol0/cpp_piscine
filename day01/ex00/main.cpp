/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aillia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 17:05:01 by aillia            #+#    #+#             */
/*   Updated: 2019/10/02 17:05:03 by aillia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"

void	ponyLive(Pony pony)
{
	pony.eat(2);
	pony.sleep(3);
	pony.jump();
	pony.jump();
	pony.jump();
	pony.jump();
	pony.eat(2);
	pony.sleep(3);
	pony.jump();
	pony.jump();
	pony.jump();
	pony.run();
	pony.run();
	pony.run();
	pony.run();
	pony.eat(2);
	pony.sleep(3);
	pony.jump();
	pony.jump();
	pony.jump();
	pony.jump();
	pony.jump();
	pony.jump();
	pony.eat(2);
	pony.sleep(3);
	pony.jump();
	pony.jump();
	pony.jump();
	pony.jump();
	pony.jump();
	pony.jump();
	pony.eat(2);
	pony.sleep(3);
	pony.jump();
	pony.jump();
	pony.jump();
	pony.jump();
	pony.jump();
}

void	ponyOnTheHeap(std::string name, std::string owner)
{
	Pony *pony = new Pony(name, owner);

	ponyLive(*pony);
	delete pony;
}

void	ponyOnTheStack()
{
	Pony pony;

	ponyLive(pony);
}

int	main(void)
{
	ponyOnTheHeap("Twilight", "Hasbro Studios");
	ponyOnTheStack();
	return (0);
}
