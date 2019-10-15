/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aillia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 18:17:49 by aillia            #+#    #+#             */
/*   Updated: 2019/10/08 18:17:52 by aillia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <string>

class Bureaucrat;

class Form
{
private:
	const std::string	_name;
	bool				_signed;
	const int			_grade_to_sign;
	const int			_grade_to_execute;

	Form&				operator=(Form& a);

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

	class AlreadySignedException : public std::exception
	{
	private:
		AlreadySignedException&	operator=(AlreadySignedException& a);
	public:
		AlreadySignedException();
		AlreadySignedException(const AlreadySignedException&);
		virtual ~AlreadySignedException() _NOEXCEPT;
		virtual const char* what() const _NOEXCEPT;
	};

	Form();
	Form(std::string name);
	Form(std::string name, int grade_to_sign, int grade_to_execute);
	Form(const Form& a);
	~Form();

	Form&		operator<<(Form& a);

	std::string	getName() const;
	bool		getSigned() const;
	int			getGradeToSign() const;
	int			getGradeToExecute() const;

	void		beSigned(const Bureaucrat b);
};

std::ostream&	operator<<(std::ostream& os, const Form& a);

#endif /* FORM_HPP */
