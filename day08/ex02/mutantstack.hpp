/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantstack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aillia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 15:07:30 by aillia            #+#    #+#             */
/*   Updated: 2019/10/12 15:07:34 by aillia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <vector>
#include <stack>

template<typename T>
class MutantStack : public std::stack<T>
{
private:
	std::vector<T>	_stack;
public:
	MutantStack() {}
	MutantStack(const MutantStack& a) { swap(a); }
	MutantStack&	operator=(MutantStack& a) { swap(a); return (*this); }
	~MutantStack()	{ _stack.clear(); }

	std::vector<T>	getStack() const { return (_stack); }

	T				top() const { return (_stack.back()); }
	bool			empty() const { return (_stack.empty());}
	size_t			size() const { return (_stack.size()); }

	void			push(T n) { _stack.push_back(n); }
	void			pop() { _stack.pop_back(); }
	void			swap(MutantStack& a) { _stack.swap(a.getStack()); }

	typedef typename std::vector<T>::const_iterator iterator;

	iterator		begin() const { return (_stack.begin()); }
	iterator		end() const { return (_stack.end()); }
};

#endif /* MUTANTSTACK_HPP */
