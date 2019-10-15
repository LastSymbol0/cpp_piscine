/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HostnameModule.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoropet <akoropet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 13:50:09 by aillia            #+#    #+#             */
/*   Updated: 2019/10/13 15:17:29 by akoropet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HostnameModule.hpp"

HostnameModule::HostnameModule() {
	char			tempHost[256];
	char*			tempUser;

	try {
		tempUser = getlogin();
		if (!(tempUser))
			throw std::logic_error("User name cannot be found.");
		std::string		userName(tempUser);
		setUser_name(tempUser);
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	try {
		if (gethostname(tempHost, 256))
			throw std::logic_error("Host name cannot be found.");
		std::string		hostName(tempHost);
		setHost_name(hostName);
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
}

HostnameModule::~HostnameModule() {}

std::string		HostnameModule::getHost_name(void) const { return _host_name; }
std::string		HostnameModule::getUser_name(void) const { return _user_name; }
void			HostnameModule::setHost_name(std::string name) { _host_name = name; }
void			HostnameModule::setUser_name(std::string name) { _user_name = name; }

