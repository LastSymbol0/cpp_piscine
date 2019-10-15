/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aillia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 18:22:29 by aillia            #+#    #+#             */
/*   Updated: 2019/10/02 18:22:30 by aillia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

std::string		Zombie::tiny_zombie_names[10] = {"Sophia",
												"Emma",
												"Isabella",
												"Olivia",
												"Ava",
												"Emily",
												"Abigail",
												"Mia",
												"Madison",
												"Elizabeth"};

std::string		Zombie::zombie_types[10] = {"QA",
											"Junior Developer",
											"Middle Developer",
											"Senior Developer",
											"Software Engineer",
											"Back-end Developer",
											"Front-end Developer",
											"Game Developer",
											"Game Designer",
											"Project Manager"};

Zombie::Zombie(void)
{
	this->name = this->tiny_zombie_names[rand() % 10];
	this->type = this->zombie_types[rand() % 10];
	announce();
}

Zombie::Zombie(std::string name)
{
	this->name = name;
	this->type = this->zombie_types[rand() % 10];
	announce();
}

Zombie::Zombie(std::string name, std:: string type)
{
	this->name = name;
	this->type = type;
	announce();
}

void	Zombie::announce(void)
{
	std::cout << "<" << this->name << " (" << this->type << ")> Braiiiiiiinnnssss..." << std::endl;
}
