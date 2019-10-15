/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HostnameModule.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoropet <akoropet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 13:50:13 by aillia            #+#    #+#             */
/*   Updated: 2019/10/13 23:21:53 by akoropet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOSTNAMEMODULE_HPP
# define HOSTNAMEMODULE_HPP

#include <iostream>
#include <unistd.h>

class HostnameModule
{
private:
	std::string		_host_name;
	std::string		_user_name;

	HostnameModule(HostnameModule const & arg);
	HostnameModule &	operator=(HostnameModule const & arg);

public:
	HostnameModule();
	~HostnameModule();

	std::string	getHost_name(void) const;
	std::string	getUser_name(void) const;
	void		setHost_name(std::string name);
	void		setUser_name(std::string name);

};

#endif /* HOSTNAMEMODULE_HPP */
