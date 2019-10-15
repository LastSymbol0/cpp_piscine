/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aillia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 17:55:31 by aillia            #+#    #+#             */
/*   Updated: 2019/10/01 17:55:38 by aillia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int	main(int ac, char *av[])
{
	if (ac < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
		for (int i = 1; i < ac; i++)
		{
			for (size_t j = 0; j < strlen(av[i]); j++)
				av[i][j] = toupper(av[i][j]);
			std::cout << av[i];
		}
	std::cout << std::endl;
	return (0);
}
