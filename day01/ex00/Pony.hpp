/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aillia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 16:35:25 by aillia            #+#    #+#             */
/*   Updated: 2019/10/02 16:35:27 by aillia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

class Pony {
	
	private:

		std::string	name;
		std::string	owner;
		int			age;
		short		nuber_of_legs;

	public:

		Pony(std::string name, std::string owner);
		Pony();

		void	jump(void);
		void	run(void);
		void	eat(int time);
		void	sleep(int time);
		void	greeting(void);
};