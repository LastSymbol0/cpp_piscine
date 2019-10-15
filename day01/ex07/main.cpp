/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aillia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 22:29:05 by aillia            #+#    #+#             */
/*   Updated: 2019/10/02 22:29:07 by aillia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

int		main(int ac, char **av)
{
	if (ac != 4) {
		std::cout << "Somthing wrong with argument number" << std::endl;
		return (0);
	}

	std::string filename = av[1],
					s1 = av[2],
					s2 = av[3],
					line, text;
	if (s1.empty() || s2.empty()) {
		std::cout << "Empty string" << std::endl;
		return (0);
	}

	std::ifstream ifs(filename);
	if (!ifs.is_open()) {
		std::cout << "Somthing wrong with filename" << std::endl;
		return (0);
	}

	while (getline(ifs, line))
		text += line + "\n";
	ifs.close();

	size_t	i = 0;
	while (1)
	{
		i = text.find(s1, i);
		if (i == std::string::npos)
			break ;
		text.replace(i, s2.size(), s2);
		i += s2.size();
	}

	std::ofstream ofs(filename + ".replace");
	ofs << text;
	ofs.close();
	return (0);
}
