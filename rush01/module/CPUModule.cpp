/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CPUModule.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoropet <akoropet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 19:28:54 by aillia            #+#    #+#             */
/*   Updated: 2019/10/13 22:45:19 by akoropet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CPUModule.hpp"
#include <cstdio>
#include <string>
#include <sstream>
#include <iostream>

CPUModule::CPUModule() {
	refresh();
}

float			CPUModule::getIdle() { return(_idle); }
float			CPUModule::getUser() { return(_user); }
float			CPUModule::getSys() { return(_sys); }
std::string		CPUModule::getName() { return _name.substr(0, _name.length() - 1); }
std::string		CPUModule::getSpeed() { return _speed.substr(0, _speed.length() - 1); }
std::string		CPUModule::getNumberCore() { return _numberCore; }

void		CPUModule::refresh() {
	char		buff[128];
	float		res[3];
	FILE*		p = popen("top -l 1 -n 0 | grep 'CPU usage'", "r");
	if (!p)
		throw std::runtime_error("popen() failed!");
	if (fgets(buff, 128 , p) == NULL)
		return ;

	pclose(p);
	std::string	sbuff(buff), tmp;
	std::stringstream ss;
	ss << sbuff;
	int i = 0;
	while (!ss.eof()) {
		ss >> tmp;
		if (std::stringstream(tmp) >> res[i])
			i++;
	}
	_idle = res[0];
	_user = res[1];
	_sys = res[2];
	hardwareInfo();
}

void		CPUModule::hardwareInfo(void) {
	char		buff1[128];
	char		buff2[128];
	char		buff3[128];
	std::string input = "";
	FILE*		f1 = popen("system_profiler SPHardwareDataType | grep 'Processor Name:'", "r");
	FILE*		f2 = popen("system_profiler SPHardwareDataType | grep 'Processor Speed:'", "r");
	FILE*		f3 = popen("system_profiler SPHardwareDataType | grep 'Total Number of Cores:'", "r");

	if (fgets(buff1, 128 , f1) == NULL)
		return ;
	input = buff1;
	for (int i = 0; buff1[i]; ++i) {
		if (buff1[i] == ':') {
			input.erase(0, i + 2);
			_name = input;
			break ;
		}
	}
	if (fgets(buff2, 128 , f2) == NULL)
		return ;
	input = buff2;
	for (int i = 0; buff2[i]; ++i) {
		if (buff2[i] == ':') {
			input.erase(0, i + 2);
			_speed = input;
			break ;
		}
	}
	if (fgets(buff3, 128 , f3) == NULL)
		return ;
	input = buff3;
	for (int i = 0; buff3[i]; ++i) {
		if (buff3[i] == ':') {
			input.erase(0, i + 2);
			_numberCore = input;
			break ;
		}
	}
	pclose(f1);
	pclose(f2);
	pclose(f3);
}



CPUModule::~CPUModule() {}
