/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aillia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 20:39:45 by aillia            #+#    #+#             */
/*   Updated: 2019/10/04 20:39:55 by aillia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUPERTRAP_HPP
# define SUPERTRAP_HPP
# include "NinjaTrap.hpp"
# include "FragTrap.hpp"

class SuperTrap: virtual public NinjaTrap, virtual public FragTrap
{

private:
	/* data */

public:
	SuperTrap(std::string name);
	SuperTrap(const SuperTrap& a);
	~SuperTrap();
	SuperTrap&	operator=(SuperTrap& a);

};

#endif /* SUPERTRAP_HPP */
