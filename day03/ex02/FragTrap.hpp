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

# include "ClapTrap.hpp"
# include <string>

class FragTrap: public ClapTrap
{
private:

public:
	FragTrap(std::string name);
	FragTrap(const FragTrap& a);
	~FragTrap(void);
	FragTrap& operator= (FragTrap& a);

	void	vaulthunter_dot_exe(std::string const & target);
};

#endif /* FRAGTRAP_HPP */
