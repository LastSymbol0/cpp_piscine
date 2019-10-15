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

class ScavTrap
{
private:
	std::string		_name;
	unsigned int	_hit_p;
	unsigned int	_max_hit_p;
	unsigned int	_energy_p;
	unsigned int	_max_energy_p;
	unsigned int	_level;
	unsigned int	_melee_att_dmg;
	unsigned int	_range_att_dmg;
	unsigned int	_arm_dmg_reduct;

public:
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap& a);
	~ScavTrap(void);

	ScavTrap& operator= (ScavTrap& a);

	void	rangedAttack(std::string const & target);
	void	meleeAttack(std::string const & target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

	void	challengeNewcomer(void);
};



#endif /* SCAVTRAP_HPP */
