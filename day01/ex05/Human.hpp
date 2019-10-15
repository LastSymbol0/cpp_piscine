/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aillia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 21:23:10 by aillia            #+#    #+#             */
/*   Updated: 2019/10/02 21:23:12 by aillia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

class Human
{
	private:
		const Brain	brain;

	public:
		std::string		identify()	const;
		const Brain&	getBrain()	const;
};
