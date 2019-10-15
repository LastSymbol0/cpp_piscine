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

class Fixed
{
	private:
		int					val;
		static const int	_bits;

	public:
		Fixed(void);
		/* copy construct */
		Fixed(const Fixed& a);
		~Fixed(void);

		/* assignation operator overload */
		Fixed& operator= (Fixed& a);

		int			getRawBits(void) const;
		void		setRawBits(int const raw);
};

#endif
