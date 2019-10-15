/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OSModule.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoropet <akoropet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 13:49:52 by aillia            #+#    #+#             */
/*   Updated: 2019/10/13 23:22:33 by akoropet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OSMODULE_HPP
# define OSMODULE_HPP

#include <iostream>

class OSModule
{
private:
	std::string	_os;
	std::string	_version;

	OSModule(OSModule const & arg);
	OSModule &	operator=(OSModule const & arg);

public:
	OSModule();
	~OSModule();
int 	GetOSVersionComponent(int component);

	std::string	getOS(void) const;
	std::string	getVersion(void) const;
	void		setOS(std::string input);
	void		setVersion(std::string input);
};

#endif /* OSMODULE_HPP */
