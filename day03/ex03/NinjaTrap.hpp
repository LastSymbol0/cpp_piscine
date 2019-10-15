/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aillia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 19:45:32 by aillia            #+#    #+#             */
/*   Updated: 2019/10/04 19:45:34 by aillia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NINJATRAP_HPP
# define NINJATRAP_HPP

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class NinjaTrap: public ClapTrap
{
private:

public:
	NinjaTrap(std::string name);
	NinjaTrap(const NinjaTrap& a);
	~NinjaTrap();
	NinjaTrap&	operator=(NinjaTrap& a);

	void	ninjaShoebox(FragTrap& a);
	void	ninjaShoebox(ScavTrap& a);
	void	ninjaShoebox(NinjaTrap& a);
};


#endif /* NINJATRAP_HPP */
