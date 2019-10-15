/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aillia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 13:56:39 by aillia            #+#    #+#             */
/*   Updated: 2019/10/12 13:56:45 by aillia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>

class span
{
private:
	std::vector<int>	_v;
	unsigned int		_size;
	bool				_is_sort;
public:
	span();
	span(unsigned int n);
	span(const span& a);
	~span();

	span&				operator=(span& a);

	std::vector<int>	getV() const ;
	unsigned int		getSize() const ;

	void				addNumber(int n);
	int					shortestSpan();
	int					longestSpan();
};

#endif /* SPAN_HPP */
