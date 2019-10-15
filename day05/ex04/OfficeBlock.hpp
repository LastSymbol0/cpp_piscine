/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OfficeBlock.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aillia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 16:11:12 by aillia            #+#    #+#             */
/*   Updated: 2019/10/09 16:11:13 by aillia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OFFICEBLOCK_HPP
# define OFFICEBLOCK_HPP

# include <string>

class Intern;
class Bureaucrat;

class OfficeBlock
{
private:
	Intern		*_intern;
	Bureaucrat	*_signer;
	Bureaucrat	*_executor;

	OfficeBlock(const OfficeBlock &);
	OfficeBlock& operator=(OfficeBlock &);

public:
	OfficeBlock();
	OfficeBlock(Intern *intern, Bureaucrat *signer, Bureaucrat *execurtor);
	~OfficeBlock();

	void			setIntern(Intern *intern);
	void			setSigner(Bureaucrat *signer);
	void			setExecutor(Bureaucrat *executor);

	void			doBureaucracy(std::string type, std::string target);

	class NotEnoughHandsException : public std::exception
	{
	private:
		NotEnoughHandsException&	operator=(NotEnoughHandsException& a);
	public:
		NotEnoughHandsException();
		NotEnoughHandsException(const NotEnoughHandsException&);
		virtual ~NotEnoughHandsException() _NOEXCEPT;
		virtual const char* what() const _NOEXCEPT;
	};
};

#endif /* OFFICEBLOCK_HPP */
