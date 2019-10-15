/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aillia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 22:01:49 by aillia            #+#    #+#             */
/*   Updated: 2019/10/02 22:01:50 by aillia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

class HumanB
{
	private:
		std::string	name;
		Weapon		weapon;
	
	public:
		HumanB(std::string name);
		void	setWeapon(Weapon weapon);
		void	attack(void);
};

