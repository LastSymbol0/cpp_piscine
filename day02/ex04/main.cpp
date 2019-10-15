/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aillia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 21:52:44 by aillia            #+#    #+#             */
/*   Updated: 2019/10/03 21:52:46 by aillia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.class.hpp"

# define PLUS_MINUS(a) a == '+' || a == '-'
# define MULT_DIV(a) a == '*' || a == '/'
# define DIGIT(a) a >= '0' && a <= '9'

Fixed	expr(std::string s);

int i;

Fixed	get_nbr(std::string s)
{
	Fixed res((int)(s[i++] - 48));

	while (DIGIT(s[i]))
		res = Fixed(10) * res + s[i++] - '0';
	return (res);
}

Fixed	bracket(std::string s)
{
	Fixed res;

	if (DIGIT(s[i]))
		return (get_nbr(s));
	if (s[i] == '(') {
		i++;
		Fixed res = expr(s);
		i++;
		return (res);
	}
	if (s[i] == '-') {
		i++;
		return (bracket(s) * -1);
	}
	return (res);
}

Fixed	term(std::string s)
{
	Fixed	res;

	res = bracket(s);
	while (MULT_DIV(s[i]))
		switch (s[i])
		{
			case '*':
				i++;
				res = res * bracket(s);
				break ;
			case '/':
				i++;
				res = res / bracket(s);
				break ;
			default:
				break ;
		}
	return (res);
}

Fixed	expr(std::string s)
{
	Fixed	res;

	res = term(s);
	while (PLUS_MINUS(s[i]))
		switch (s[i])
		{
			case '+':
				i++;
				res = res + term(s);
				break ;
			case '-':
				i++;
				res = res - term(s);
				break ;
			default:
				break ;
		}
	return (res);
}

int		main(int ac, char **av)
{
	i = 0;

	if (ac != 2)
		std::cout << "Wrong argument number" << std::endl;
	else
		std::cout << expr(av[1]) << std::endl;
	return (0);
}