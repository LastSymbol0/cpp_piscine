/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aillia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 19:51:09 by aillia            #+#    #+#             */
/*   Updated: 2019/10/02 19:51:10 by aillia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

class ZombieHorde {

	private:

		Zombie	*zombies;
		int		zombies_count;

	public:

		ZombieHorde(int n);
		~ZombieHorde();

		void	announce(void);
};
