/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CentralBureaucracy.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aillia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 17:06:33 by aillia            #+#    #+#             */
/*   Updated: 2019/10/09 17:06:34 by aillia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CentralBureaucracy.hpp"

CentralBureaucracy::CentralBureaucracy() { _queue_count = 0; _queue_start = 0;}
CentralBureaucracy::~CentralBureaucracy() {}

void				CentralBureaucracy::feed(Bureaucrat *b) {
	for (int i = 0; i < 20; i++) {
		if (!_ob[i].getSigner()) {
			_ob[i].setSigner(b);
			break ;
		}
		if (!_ob[i].getExecutor()) {
			_ob[i].setExecutor(b);
			break ;
		}
	}
}

void				CentralBureaucracy::queueUp(std::string name) {
	if (_queue_count + _queue_start >= QUEUE_LIMIT)
		throw QueueLimitException();
	_queue[_queue_start + _queue_count++] = name;
}

void				CentralBureaucracy::doBureaucracy() {
	std::string types[4] = {"presidential pardon", "robotomy request", "shrubbery creation", "undefined"};

	if (_queue_count == 0)
		throw QueueEmptyException();
	for (int i = 0; i < (rand() % _queue_count); i++) {
		_ob[i % 20].doBureaucracy(types[rand() % 3], _queue[_queue_start + i]);
		_queue_start = i + 1;
	}
	_queue_count -= _queue_start;
}

CentralBureaucracy::QueueLimitException::QueueLimitException() : exception() {}
CentralBureaucracy::QueueLimitException::QueueLimitException(const QueueLimitException&) : exception() {}
CentralBureaucracy::QueueLimitException::~QueueLimitException() _NOEXCEPT {}
const char* CentralBureaucracy::QueueLimitException::what() const _NOEXCEPT {
	return ("QueueLimitException");
}

CentralBureaucracy::QueueEmptyException::QueueEmptyException() : exception() {}
CentralBureaucracy::QueueEmptyException::QueueEmptyException(const QueueEmptyException&) : exception() {}
CentralBureaucracy::QueueEmptyException::~QueueEmptyException() _NOEXCEPT {}
const char* CentralBureaucracy::QueueEmptyException::what() const _NOEXCEPT {
	return ("QueueEmptyException");
}