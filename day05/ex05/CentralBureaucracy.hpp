/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CentralBureaucracy.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aillia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 17:06:38 by aillia            #+#    #+#             */
/*   Updated: 2019/10/09 17:06:39 by aillia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CENTRALBUREAUCRACY_HPP
# define CENTRALBUREAUCRACY_HPP

# include <string>
# include "OfficeBlock.hpp"
# define QUEUE_LIMIT 99999

// class OfficeBlock;
class Bureaucrat;

class CentralBureaucracy
{
private:
	OfficeBlock	_ob[20];
	std::string	_queue[QUEUE_LIMIT];
	int			_queue_count;
	int			_queue_start;

	CentralBureaucracy(const CentralBureaucracy& a);
	CentralBureaucracy&	operator=(CentralBureaucracy& a);

public:
	CentralBureaucracy();
	~CentralBureaucracy();

	void				feed(Bureaucrat *b);
	void				queueUp(std::string name);
	void				doBureaucracy();


	class QueueLimitException : public std::exception
	{
	private:
		QueueLimitException&	operator=(QueueLimitException& a);
	public:
		QueueLimitException();
		QueueLimitException(const QueueLimitException&);
		virtual ~QueueLimitException() _NOEXCEPT;
		virtual const char* what() const _NOEXCEPT;
	};

	class QueueEmptyException : public std::exception
	{
	private:
		QueueEmptyException&	operator=(QueueEmptyException& a);
	public:
		QueueEmptyException();
		QueueEmptyException(const QueueEmptyException&);
		virtual ~QueueEmptyException() _NOEXCEPT;
		virtual const char* what() const _NOEXCEPT;
	};
};

#endif /* CENTRALBUREAUCRACY_HPP */
