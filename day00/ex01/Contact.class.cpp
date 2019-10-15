/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aillia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 17:56:39 by aillia            #+#    #+#             */
/*   Updated: 2019/10/01 17:56:41 by aillia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.class.hpp"
// #include <string>

	Contact::Contact() { };

	std::string Contact::getFirst_name() {return this->first_name;}
	void Contact::setFirst_name(std::string first_name) {this->first_name = first_name;}

	std::string Contact::getLast_name() {return this->last_name;}
	void Contact::setLast_name(std::string last_name) {this->last_name = last_name;}

	std::string Contact::getNickname() {return this->nickname;}
	void Contact::setNickname(std::string nickname) {this->nickname = nickname;}

	std::string Contact::getLogin() {return this->login;}
	void Contact::setLogin(std::string login) {this->login = login;}

	std::string Contact::getPostal_addr() {return this->postal_addr;}
	void Contact::setPostal_addr(std::string postal_addr) {this->postal_addr = postal_addr;}

	std::string Contact::getEmail() {return this->email;}
	void Contact::setEmail(std::string email) {this->email = email;}

	std::string Contact::getPhone() {return this->phone;}
	void Contact::setPhone(std::string phone) {this->phone = phone;}

	std::string Contact::getBirthday() {return this->birthday;}
	void Contact::setBirthday(std::string birthday) {this->birthday = birthday;}

	std::string Contact::getFavorite_meal() {return this->favorite_meal;}
	void Contact::setFavorite_meal(std::string favorite_meal) {this->favorite_meal = favorite_meal;}

	std::string Contact::getUnderwear_color() {return this->underwear_color;}
	void Contact::setUnderwear_color(std::string underwear_color) {this->underwear_color = underwear_color;}

	std::string Contact::getDarkest_secret() {return this->darkest_secret;}
	void Contact::setDarkest_secret(std::string darkest_secret) {this->darkest_secret = darkest_secret;}
