/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aillia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 15:02:50 by aillia            #+#    #+#             */
/*   Updated: 2019/10/08 15:02:52 by aillia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>

class Bureaucrat
{
private:
	const std::string	_name;
	int					_grade;

public:

	class GradeTooHighException : public std::exception
	{
	private:
		GradeTooHighException&	operator=(GradeTooHighException& a);
	public:
		GradeTooHighException();
		GradeTooHighException(const GradeTooHighException&);
		virtual ~GradeTooHighException() _NOEXCEPT;
		virtual const char* what() const _NOEXCEPT;
	};

	class GradeTooLowException : public std::exception
	{
	private:
		GradeTooLowException&	operator=(GradeTooLowException& a);
	public:
		GradeTooLowException();
		GradeTooLowException(const GradeTooLowException&);
		virtual ~GradeTooLowException() _NOEXCEPT;
		virtual const char* what() const _NOEXCEPT;
	};

	
	Bureaucrat();
	Bureaucrat(std::string name);
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat& a);
	~Bureaucrat();

	Bureaucrat&	operator=(Bureaucrat& a);
	Bureaucrat&	operator<<(Bureaucrat& a);

	std::string	getName() const;
	int			getGrade() const;
	void		incrementGrade();
	void		decrementGrade();
};

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& a);

#endif /* BUREAUCRAT_HPP */
