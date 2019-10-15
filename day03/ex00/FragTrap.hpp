/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aillia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 15:56:02 by aillia            #+#    #+#             */
/*   Updated: 2019/10/04 15:56:03 by aillia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include <string>

class FragTrap
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
	FragTrap(std::string name);
	FragTrap(const FragTrap& a);
	~FragTrap(void);

	FragTrap& operator= (FragTrap& a);

	void	rangedAttack(std::string const & target);
	void	meleeAttack(std::string const & target);
	void	takeDamage(unsigned int amount);
	void	 beRepaired(unsigned int amount);

	void	vaulthunter_dot_exe(std::string const & target);
};

#endif /* FRAGTRAP_HPP */
