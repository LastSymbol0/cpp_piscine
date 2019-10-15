/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aillia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 16:50:50 by aillia            #+#    #+#             */
/*   Updated: 2019/10/02 16:50:51 by aillia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"
#include <iostream>

Pony::Pony(std::string name, std::string owner)
{
	this->age = 0;
	this->nuber_of_legs = 4;
	this->name = name;
	this->owner = owner;
	greeting();
}

Pony::Pony()
{
	this->age = 0;
	this->nuber_of_legs = 4;
	this->name = "unnamed";
	this->owner = "nature";
	greeting();
}

void	Pony::jump()
{
	if (this->nuber_of_legs != 4 || this->age >= 27)
		std::cout << "Are you kidding me?" << std::endl;
	else if ((rand() % 50) == 42) {
		this->nuber_of_legs--;
		std::cout << "Ooops.." << std::endl;
	}
	else
		std::cout << "Jump!" << std::endl;
	
}

void	Pony::run()
{
	if (this->nuber_of_legs != 4 || this->age >= 27)
		std::cout << "Are you kidding me?" << std::endl;
	else if ((rand() % 50) == 42) {
		this->nuber_of_legs--;
		std::cout << "Ooops.." << std::endl;
	}
	else
		std::cout << "It's hard, but I have enought legs" << std::endl;
}

void	Pony::eat(int time)
{
	this->age += time;
	std::cout << "Tasty!" << std::endl;
}

void	Pony::sleep(int time)
{
	this->age += time;
	std::cout << "Hrrhrr.. Hrrrrrrrr..." << std::endl;
}

void	Pony::greeting(void)
{
	std::cout << "Hello, I'm " << this->name << " pony, " << this->age << " y. o. My owner is a " << this->owner << std::endl;
}

