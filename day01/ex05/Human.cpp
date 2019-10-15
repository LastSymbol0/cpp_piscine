/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aillia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 21:23:05 by aillia            #+#    #+#             */
/*   Updated: 2019/10/02 21:23:07 by aillia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

const Brain&	Human::getBrain() const {
	return (brain);
}

std::string		Human::identify() const {
	return (brain.identify());
}

