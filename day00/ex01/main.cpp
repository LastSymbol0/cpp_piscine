/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aillia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 17:55:59 by aillia            #+#    #+#             */
/*   Updated: 2019/10/01 17:56:03 by aillia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.h"

int			main(void)
{
	std::string	command;
	PhoneBook	phonebook;

	while (command != "EXIT")
	{
		std::cin >> command;
		if (command == "ADD")
			phonebook.add();
		else if (command == "SEARCH")
			phonebook.search();
	}
	return (0);
}
