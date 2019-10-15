/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aillia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 18:22:35 by aillia            #+#    #+#             */
/*   Updated: 2019/10/02 18:22:36 by aillia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

class Zombie {

	private:

		static std::string	tiny_zombie_names[10];
		static std::string	zombie_types[10];
		std::string			name,
							type;
		

	public:

		Zombie(void);
		Zombie(std::string name);
		Zombie(std::string name, std::string type);

		void	announce(void);
};
