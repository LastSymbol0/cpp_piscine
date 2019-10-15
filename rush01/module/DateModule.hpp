/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DateModule.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoropet <akoropet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 13:50:34 by aillia            #+#    #+#             */
/*   Updated: 2019/10/13 23:21:27 by akoropet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATEMODULE_HPP
# define DATEMODULE_HPP

#include <iostream>

class DateModule
{
private:
	std::string	_date;
	std::string	_time;

	DateModule(DateModule const & arg);
	DateModule &	operator=(DateModule const & arg);

public:
	DateModule();
	~DateModule();

	void			refresh(void);

	std::string		getDate() const;
	std::string		getTime() const;
	void			setTime(std::string input);
	void			setDate(std::string input);
};

#endif /* DATEMODULE_HPP */
