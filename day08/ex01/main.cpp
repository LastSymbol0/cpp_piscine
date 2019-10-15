/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aillia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 13:56:48 by aillia            #+#    #+#             */
/*   Updated: 2019/10/12 13:56:52 by aillia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"
#include <iostream>

int		main()
{
	span s(1000000);

	try {
		std::cout << "shortestSpan: " << s.shortestSpan() << std::endl;
		s.addNumber(12);
		std::cout << "longestSpan: " << s.longestSpan() << std::endl;
	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	
	srand(time(NULL));
	for (size_t i = 0; i < 1000000; i++){
		s.addNumber(rand());
	}
	std::cout << std::endl;
	std::cout << "shortestSpan: " << s.shortestSpan() << std::endl;
	std::cout << "longestSpan: " << s.longestSpan() << std::endl;
	
	return (0);
}

