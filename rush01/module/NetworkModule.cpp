/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NetworkModule.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aillia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 23:15:18 by aillia            #+#    #+#             */
/*   Updated: 2019/10/13 23:15:19 by aillia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NetworkModule.hpp"
#include <sstream>

NetworkModule::NetworkModule() {
	refresh();
}

void			NetworkModule::refresh() {
	char		buff[128];
	std::string	res[3];
	FILE*		p = popen("top -l 1 -n 0 | grep 'Networks'", "r");
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
		if (isdigit(tmp[0]))
			res[i++] = tmp;
	}
	_in_p = res[0];
	_out_p = res[1];
}

std::string		NetworkModule::getIn_p() { return(_in_p); }
std::string		NetworkModule::getOut_p() { return(_out_p); }

NetworkModule::~NetworkModule() { }

