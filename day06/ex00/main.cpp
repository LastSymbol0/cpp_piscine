/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aillia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 18:44:31 by aillia            #+#    #+#             */
/*   Updated: 2019/10/09 18:44:33 by aillia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include <string>
#include "Convert.hpp"
// void	from_int(std::string)

int		main(int ac, char **av)
{
	if (ac != 2) {
		std::cerr << "Input only 1 argument plz" << std::endl;
		return (0);
	}
	try {
		Convert convert(av[1]);
		convert.print();		
	} catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
