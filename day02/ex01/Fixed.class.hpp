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
		/* copy construct */
		Fixed(const Fixed& a);
		~Fixed(void);

		/* assignation operator overload */
		Fixed& operator=(Fixed& a);
		Fixed operator=(Fixed a);

		int			getRawBits(void) const;
		void		setRawBits(int const raw);

		float		toFloat(void) const;
		int			toInt(void) const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& a);


#endif
