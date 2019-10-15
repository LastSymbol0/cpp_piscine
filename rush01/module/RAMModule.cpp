/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RAMModule.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoropet <akoropet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 18:59:19 by akoropet          #+#    #+#             */
/*   Updated: 2019/10/13 22:45:39 by akoropet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RAMModule.hpp"
#include <sstream>

RAMModule::RAMModule() { refresh(); }

RAMModule::~RAMModule() {  }

void			RAMModule::refresh(void) {
	char		buff[128];
	FILE*		p = popen("top -l 1 -n 0 | grep 'PhysMem'", "r");
	std::string	input = "";

	if (!p)
		throw std::runtime_error("popen() failed!");
	if (fgets(buff, 128 , p) == NULL)
		return ;
	int i = 0;
	while (!isdigit(buff[i]))
		i++;
	while (isdigit(buff[i]))
		input.push_back(buff[i++]);
	setUsed(input);
	input = "";
	while (!isdigit(buff[i]))
		i++;
	while (isdigit(buff[i]))
		input.push_back(buff[i++]);
	setWired(input);
	input = "";
	while (!isdigit(buff[i]))
		i++;
	while (isdigit(buff[i]))
		input.push_back(buff[i++]);
	setUnused(input);
	pclose(p);
}

std::string		RAMModule::getUsed(void) { return _used; }
std::string		RAMModule::getWired(void) { return _wired; }
std::string		RAMModule::getUnused(void) { return _unused; }

void			RAMModule::setUsed(std::string input) { _used = input; }
void			RAMModule::setWired(std::string input) { _wired = input; }
void			RAMModule::setUnused(std::string input) { _unused = input; }
