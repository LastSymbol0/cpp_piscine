/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CPUModule.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoropet <akoropet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 19:29:01 by aillia            #+#    #+#             */
/*   Updated: 2019/10/13 23:21:17 by akoropet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPUMODULE_HPP
# define CPUMODULE_HPP

#include <iostream>
#include <cstdio>

class CPUModule
{
private:
	std::string	_name;
	std::string	_speed;
	std::string	_numberCore;
	float		_idle;
	float		_user;
	float		_sys;

	CPUModule(CPUModule const & arg);
	CPUModule &	operator=(CPUModule const & arg);

public:
	CPUModule();
	~CPUModule();
	void		hardwareInfo(void);

	float		getIdle();
	float		getUser();
	float		getSys();
	void		refresh();
	std::string	getName();
	std::string	getSpeed();
	std::string	getNumberCore();

};

#endif /* CPUMODULE_HPP */
