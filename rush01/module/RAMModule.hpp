/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RAMModule.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoropet <akoropet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 18:59:09 by akoropet          #+#    #+#             */
/*   Updated: 2019/10/13 23:22:58 by akoropet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAMMODULE_HPP
# define RAMMODULE_HPP

#include <iostream>
#include <cctype>

class RAMModule
{
public:
	RAMModule();
	~RAMModule();

	void		setUsed(std::string input);
	void		setWired(std::string input);
	void		setUnused(std::string input);

	std::string	getUsed(void);
	std::string	getWired(void);
	std::string	getUnused(void);

	void		refresh(void);

private:
	std::string		_used;
	std::string		_wired;
	std::string		_unused;

	RAMModule(RAMModule const & arg);
	RAMModule &	operator=(RAMModule const & arg);

};

#endif
