/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aillia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 19:10:15 by aillia            #+#    #+#             */
/*   Updated: 2019/10/04 19:10:17 by aillia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <string>

class ClapTrap
{
private:
	
public:

	std::string		_name;
	unsigned int	_hit_p;
	unsigned int	_max_hit_p;
	unsigned int	_energy_p;
	unsigned int	_max_energy_p;
	unsigned int	_level;
	unsigned int	_melee_att_dmg;
	unsigned int	_range_att_dmg;
	unsigned int	_arm_dmg_reduct;

	ClapTrap(std::string name);
	ClapTrap	(const ClapTrap& a);
	~ClapTrap();
	ClapTrap& operator= (ClapTrap& a);

	virtual void	rangedAttack(std::string const & target);
	virtual void	meleeAttack(std::string const & target);
	virtual void	takeDamage(unsigned int amount);
	virtual void	beRepaired(unsigned int amount);
};

#endif /* CLAPTRAP_HPP */
