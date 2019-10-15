/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DateModule.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoropet <akoropet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 13:50:41 by aillia            #+#    #+#             */
/*   Updated: 2019/10/13 17:46:15 by akoropet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DateModule.hpp"

DateModule::DateModule() {
	char	buf[20];
	time_t thisTime = time(NULL);
	tm* timeinfo = localtime(&thisTime);

	strftime(buf, 20, "%X", timeinfo);
	setTime(buf);
	strftime(buf, 20, "%a %b %d %Y", timeinfo);
	setDate(buf);
}

DateModule::~DateModule() {}

void			DateModule::refresh(void) {
	char	buf[20];
	time_t thisTime = time(NULL);
	tm* timeinfo = localtime(&thisTime);

	strftime(buf, 20, "%X", timeinfo);
	setTime(buf);
}

std::string		DateModule::getDate(void) const { return _date; }
std::string		DateModule::getTime(void) const { return _time; }
void			DateModule::setDate(std::string input) { _date = input; }
void			DateModule::setTime(std::string input) { _time = input; }
