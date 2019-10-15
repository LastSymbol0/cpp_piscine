/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aillia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 14:29:05 by aillia            #+#    #+#             */
/*   Updated: 2019/10/09 14:29:09 by aillia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>

class Form;

class Intern
{
private:
public:
	Intern();
	Intern(const Intern& a);
	~Intern();

	Intern&		operator=(Intern& a);
	Form		*makeForm(std::string type, std::string target);

	class UnknownFormTypeException : public std::exception
	{
	private:
		UnknownFormTypeException&	operator=(UnknownFormTypeException& a);
	public:
		UnknownFormTypeException();
		UnknownFormTypeException(const UnknownFormTypeException&);
		virtual ~UnknownFormTypeException() _NOEXCEPT;
		virtual const char* what() const _NOEXCEPT;
	};
};

#endif /* INTERN_HPP */
