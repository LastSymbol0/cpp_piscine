/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorDisplay.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aillia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 13:25:06 by aillia            #+#    #+#             */
/*   Updated: 2019/10/13 13:25:08 by aillia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMONITORDISPLAY_HPP
# define IMONITORDISPLAY_HPP

// #include "IMonitorModule.hpp"
#include "HostnameModule.hpp"
#include "OSModule.hpp"
#include "DateModule.hpp"
#include "CPUModule.hpp"
#include "RAMModule.hpp"
#include "NetworkModule.hpp"

class IMonitorDisplay
{
private:
public:
	HostnameModule	_hostname_m;
	OSModule		_os_m;
	DateModule		_date_m;
	CPUModule		_cpu_m;
	RAMModule		_ram_m;
	NetworkModule	_net_m;

	IMonitorDisplay(/* args */);
	~IMonitorDisplay();

	virtual void	draw() = 0;
	virtual void	draw_os() = 0;
	virtual void	draw_hostname() = 0;
	virtual void	draw_date() = 0;
	virtual void	draw_cpu() = 0;
	virtual void	draw_ram() = 0;
	virtual void	draw_net() = 0;
};


#endif /* IMONITORDISPLAY_HPP */
