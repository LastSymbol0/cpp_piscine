/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aillia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 17:56:22 by aillia            #+#    #+#             */
/*   Updated: 2019/10/01 17:56:23 by aillia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>

std::string	PhoneBook::truncate(std::string s, size_t width) {
	if (s.length() <= width)
		return (s);
	return (s.substr(0, width - 1) + ".");
}

PhoneBook::PhoneBook() {
	count = 0;
}

void	PhoneBook::add(void)
{
	std::string	in;
	if (count >= 8) {
		std::cout << "Sorry, my memory is full, I can't add more contacts." << std::endl;
		return ;
	}
	std::cout << "Input first name: ";
	std::cin >> in;
	contacts[count].setFirst_name(in);
	std::cout << "Input last name: ";
	std::cin >> in;
	contacts[count].setLast_name(in);
	std::cout << "Input nickname: ";
	std::cin >> in;
	contacts[count].setNickname(in);
	std::cout << "Input login: ";
	std::cin >> in;
	contacts[count].setLogin(in);
	std::cout << "Input postal addres: ";
	std::cin >> in;
	contacts[count].setPostal_addr(in);
	std::cout << "Input email: ";
	std::cin >> in;
	contacts[count].setEmail(in);
	std::cout << "Input phone: ";
	std::cin >> in;
	contacts[count].setPhone(in);
	std::cout << "Input birthday: ";
	std::cin >> in;
	contacts[count].setBirthday(in);
	std::cout << "Input favorite meal: ";
	std::cin >> in;
	contacts[count].setFavorite_meal(in);
	std::cout << "Input underwear color: ";
	std::cin >> in;
	contacts[count].setUnderwear_color(in);
	std::cout << "Input the Darkest secret: ";
	std::getline(std::cin >> std::ws, in);
	contacts[count].setDarkest_secret(in);
	std::cout << "Done!" << std::endl;
	count++;
}

void	PhoneBook::search(void)
{
	std::string in;
	int			index;
	std::cout << "Searching..." << std::endl;
	if (count < 1) {
		std::cout << "It looks like it's no contacts yet." << std::endl;
		return ;
	}
	std::cout << "Find " << count << " contacts:" << std::endl;
	std::cout << "+-------------------------------------------+" << std::endl;
	std::cout << "|" << std::right << std::setw(10) << "index" << "|";
	std::cout << std::right << std::setw(10) << "first name" << "|";
	std::cout << std::right << std::setw(10) << "last name" << "|";
	std::cout << std::right << std::setw(10) << "nickname" << "|" << std::endl;
	std::cout << "|----------+----------+----------+----------|" << std::endl;
	for (int i = 0; i < count; i++) {
		std::cout << "|" << std::right << std::setw(10) << i << "|";
		std::cout << std::right << std::setw(10) << truncate(contacts[i].getFirst_name(), 10) << "|";
		std::cout << std::right << std::setw(10) << truncate(contacts[i].getLast_name(), 10) << "|";
		std::cout << std::right << std::setw(10) << truncate(contacts[i].getNickname(), 10) << "|" << std::endl;
	}
	std::cout << "+-------------------------------------------+" << std::endl;
	std::cout << "Input index: ";
	std::cin >> in;
	std::istringstream iss (in);
	iss >> index;
	if (iss.fail() || index >= count) {
		std::cout << "Invalid index. Go back to main menu" << std::endl;
		return ;
	}
	std::cout << "First name: " << contacts[index].getFirst_name() << std::endl;
	std::cout << "Last name: " << contacts[index].getLast_name() << std::endl;
	std::cout << "Nickname: " << contacts[index].getNickname() << std::endl;
	std::cout << "Login: " << contacts[index].getLogin() << std::endl;
	std::cout << "Postal addres: " << contacts[index].getPostal_addr() << std::endl;
	std::cout << "Email: " << contacts[index].getEmail() << std::endl;
	std::cout << "Phone: " << contacts[index].getPhone() << std::endl;
	std::cout << "Birthday: " << contacts[index].getBirthday() << std::endl;
	std::cout << "Favorite meal: " << contacts[index].getFavorite_meal() << std::endl;
	std::cout << "Underwear color: " << contacts[index].getUnderwear_color() << std::endl;
	std::cout << "The Darkest secret: " << contacts[index].getDarkest_secret() << std::endl;
}
