/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aillia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 17:48:49 by aillia            #+#    #+#             */
/*   Updated: 2019/10/04 17:48:51 by aillia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include <string>
#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
private:

public:
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap& a);
	~ScavTrap(void);
	ScavTrap& operator= (ScavTrap& a);

	void	challengeNewcomer(void);
};

#endif /* SCAVTRAP_HPP */
