/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NetworkModule.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aillia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 23:15:23 by aillia            #+#    #+#             */
/*   Updated: 2019/10/13 23:15:24 by aillia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NETWORKMODULE_HPP
# define NETWORKMODULE_HPP

# include <string>

class NetworkModule
{
private:
	std::string _in_p;
	std::string _out_p;
		NetworkModule(NetworkModule const & arg);
	NetworkModule &	operator=(NetworkModule const & arg);
public:
	NetworkModule();
	~NetworkModule();

	void			refresh();

	std::string		getIn_p();
	std::string		getOut_p();
};

#endif /* NETWORKMODULE_HPP */
