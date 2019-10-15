/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aillia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 11:55:47 by aillia            #+#    #+#             */
/*   Updated: 2019/10/12 11:55:48 by aillia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <list>
#include <deque>
#include <iostream>
#include "easyfind.hpp"

int		main(void)
{
	std::list<int>				l;
	std::vector<int>			v;
	std::deque<int>				d;
	std::vector<int>			empty;

	std::list<int>::iterator	li;
	std::vector<int>::iterator	vi;
	std::deque<int>::iterator	di;
	std::vector<int>::iterator	incorrect;


	for (int i = 0; i < 100; i++) {
		l.push_back(i);
		v.push_back(i);
		d.push_back(i);
	}
	li = easyfind(l, 32);
	vi = easyfind(v, 42);
	di = easyfind(d, 32);
	std::cout << *li << std::endl << *vi << std::endl << *di << std::endl;

	try {
		incorrect = easyfind(v, 128);
		std::cout << *incorrect << std::endl;
		easyfind(empty, 42);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return (0);
}
