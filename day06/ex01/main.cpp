/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aillia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 21:04:15 by aillia            #+#    #+#             */
/*   Updated: 2019/10/09 21:04:17 by aillia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

struct Data {
	std::string	s1;
	int			n;
	std::string	s2;
};

Data	*deserialize(void *raw)
{
	Data			*res = new Data;
	unsigned char	*d = reinterpret_cast<unsigned char *>(raw);

	for (int i = 0; i < 8; i++) {
		res->s1 = res->s1 + static_cast<char>(d[i]);
	}

	res->n = 0;
	res->n += static_cast<int>(d[8] << 24);
	res->n += static_cast<int>(d[9] << 16);
	res->n += static_cast<int>(d[10] << 8);
	res->n += static_cast<int>(d[11]);

	for (int i = 12; i < 20; i++) {
		res->s2 = res->s2 + static_cast<char>(d[i]);
	}

	return (res);
}

void	*serialize( void )
{
	unsigned char	*d = new unsigned char[20];

	for (int i = 0; i < 8; i++) {
		d[i] = static_cast<unsigned char>(32 + (rand() % 96));
		std::cout << d[i];
	}
	std::cout << std::endl;

	unsigned int	n = rand();
	unsigned int	tmp = n;
	std::cout << n << std::endl;

	d[8] = static_cast<unsigned char>(tmp >> 24 & 0xFF);
	tmp = n;
	d[9] = static_cast<unsigned char>(tmp >> 16 & 0xFF);
	tmp = n;
	d[10] = static_cast<unsigned char>(tmp >> 8 & 0xFF);
	tmp = n;
	d[11] = static_cast<unsigned char>(tmp & 0xFF);

	for (int i = 12; i < 20; i++) {
		d[i] = static_cast<unsigned char>(32 + (rand() % 96));
		std::cout << d[i];
	}
	std::cout << std::endl;

	return (reinterpret_cast<void *>(d));
}

int		main(void)
{
	void	*data1;
	Data	*data2;

	srand(time(nullptr));
	data1 = serialize();
	data2 = deserialize(data1);

	std::cout << std::endl << "Res:" << std::endl << data2->s1 << std::endl << data2->n << std::endl << data2->s2 << std::endl;
}