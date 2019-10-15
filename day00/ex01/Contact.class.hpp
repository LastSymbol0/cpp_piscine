/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aillia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 17:56:39 by aillia            #+#    #+#             */
/*   Updated: 2019/10/01 17:56:41 by aillia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

class Contact
{
	private:
		std::string	first_name,
					last_name,
					nickname,
					login,
					postal_addr,
					email,
					phone,
					birthday,
					favorite_meal,
					underwear_color,
					darkest_secret;
	
	public:
	
		Contact();
		std::string getFirst_name();
		void setFirst_name(std::string first_name);
		std::string getLast_name();
		void setLast_name(std::string last_name);
		std::string getNickname();
		void setNickname(std::string nickname);
		std::string getLogin();
		void setLogin(std::string login);
		std::string getPostal_addr();
		void setPostal_addr(std::string postal_addr);
		std::string getEmail();
		void setEmail(std::string email);
		std::string getPhone();
		void setPhone(std::string phone);
		std::string getBirthday();
		void setBirthday(std::string birthday);
		std::string getFavorite_meal();
		void setFavorite_meal(std::string favorite_meal);
		std::string getUnderwear_color();
		void setUnderwear_color(std::string underwear_color);
		std::string getDarkest_secret();
		void setDarkest_secret(std::string darkest_secret);
};
