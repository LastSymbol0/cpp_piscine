/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aillia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 17:56:22 by aillia            #+#    #+#             */
/*   Updated: 2019/10/01 17:56:23 by aillia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.class.hpp"

class PhoneBook
{
	private:

		int		count;
		Contact	contacts[8];

		std::string	truncate(std::string s, size_t width);

	public:

		PhoneBook();

		void	add(void);
		void	search(void);
};

