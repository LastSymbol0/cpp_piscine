/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aillia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 19:21:31 by aillia            #+#    #+#             */
/*   Updated: 2019/10/02 19:21:33 by aillia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "Zombie.hpp"

class ZombieEvent {

	private:

		std::string		type;

	public:

		ZombieEvent(void);

		void	setZombieType(std::string type);
		Zombie* newZombie(std::string name);
		Zombie* randomChump(void);

};