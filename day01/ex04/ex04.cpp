/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex04.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aillia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 20:26:12 by aillia            #+#    #+#             */
/*   Updated: 2019/10/02 20:26:13 by aillia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(void)
{
	std::string		s = "HI THIS IS BRAIN";
	std::string		*s_ptr = &s;
	std::string&	s_ref = s;

	std::cout << *s_ptr << std::endl;
	std::cout << s_ref << std::endl;

	return (0);
}