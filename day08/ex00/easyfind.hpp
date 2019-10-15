/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aillia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 11:54:25 by aillia            #+#    #+#             */
/*   Updated: 2019/10/12 11:54:39 by aillia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdexcept>
#include <vector>

// template<template<class ...> class T, typename i>
// typename T<i>::iterator	easyfind(T<i> container, i n) {
// 	// typename T<int>::iterator it;
// 	if (container.empty())
// 		throw std::logic_error("Empty container");
// 	typename T<i>::iterator iter;
// 	iter = container.begin();
// 	iter--;
// 	while (++iter != container.end())
// 		if (*iter == n)
// 			return (iter);
// 	return (iter);
// }

template<class T>
typename T::iterator	easyfind(T container, int n) {
	if (container.empty())
		throw std::logic_error("Empty container exception");
	typename T::iterator iter;
	iter = container.begin();
	iter--;
	while (++iter != container.end())
		if (*iter == n)
			return iter;
	return container.end();
}
