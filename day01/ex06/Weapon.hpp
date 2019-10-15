/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aillia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 22:01:10 by aillia            #+#    #+#             */
/*   Updated: 2019/10/02 22:01:11 by aillia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
# define WEAPON_H
#include <string>

class Weapon
{

	private:
		std::string	type;

	public:
		Weapon();
		Weapon(std::string type);
		void				setType(std::string type);
		const std::string&	getType(void);

};

#endif
