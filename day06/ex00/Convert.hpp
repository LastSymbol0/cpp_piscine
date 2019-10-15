/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aillia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 19:15:14 by aillia            #+#    #+#             */
/*   Updated: 2019/10/09 19:15:17 by aillia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_HPP
# define CONVERT_HPP

#include <string>

class Convert
{
private:
	int		_n;
	char	_c;
	float	_f;
	double	_d;
	bool	_nan_inf;
	bool	_flt_imp;
	bool	_int_imp;

	void	start_char(std::string s);
	void	start_int(std::string s);
	void	start_float(std::string s);
	void	start_double(std::string s);
	void	start_nan(std::string s);
	void	start_inf(std::string s);
public:
	Convert(std::string s);

	void		print() const;
	void		print_nan_inf() const;

	class ConvertStringFormatException : public std::exception
	{
	private:
		ConvertStringFormatException&	operator=(ConvertStringFormatException& a);
	public:
		ConvertStringFormatException();
		ConvertStringFormatException(const ConvertStringFormatException&);
		virtual ~ConvertStringFormatException() _NOEXCEPT;
		virtual const char* what() const _NOEXCEPT;
	};
};



#endif /* CONVERT_HPP */
