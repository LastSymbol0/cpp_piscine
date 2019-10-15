/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aillia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 17:46:19 by aillia            #+#    #+#             */
/*   Updated: 2019/10/03 17:46:21 by aillia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_CLASS_HPP
# define FIXED_CLASS_HPP

# include <iostream>

class Fixed
{
	private:
		int					val;
		static const int	_bits;

	public:
		Fixed(void);
		Fixed(const int n);
		Fixed(const float n);
		Fixed(const Fixed& a);
		~Fixed(void);

		// math
		Fixed& operator=(Fixed& a);
		Fixed operator=(Fixed a);
		Fixed operator+(Fixed a);
		Fixed operator-(Fixed a);
		Fixed operator*(Fixed a);
		Fixed operator/(Fixed a);
		Fixed operator++(void);
		Fixed operator++(int);
		Fixed operator--(void);
		Fixed operator--(int);

		// bool
		bool operator==(Fixed a);
		bool operator!=(Fixed a);
		bool operator>(Fixed a);
		bool operator>(const Fixed a) const;
		bool operator>=(Fixed a);
		bool operator<(Fixed a);
		bool operator<(const Fixed a) const;
		bool operator<=(Fixed a);

		int				getRawBits(void) const;
		void			setRawBits(int const raw);

		float			toFloat(void) const;
		int				toInt(void) const;

		static Fixed&		min(Fixed& a, Fixed& b);
		const static Fixed&	min(Fixed const& a, Fixed const& b);
		static Fixed&		max(Fixed& a, Fixed& b);
		const static Fixed&	max(Fixed const& a, Fixed const& b);
};

std::ostream& operator<<(std::ostream& os, const Fixed& a);



#endif
