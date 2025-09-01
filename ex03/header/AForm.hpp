/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aykrifa <aykrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 17:07:00 by aykrifa           #+#    #+#             */
/*   Updated: 2025/08/31 23:48:01 by aykrifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class	Bureaucrat;
class	AForm
{
	public:
		AForm(void);
		AForm(AForm const &copy);
		AForm(std::string const name, unsigned int sgrade, unsigned int xgrade);
		virtual ~AForm(void);

		AForm				&operator=(AForm const &rhs);
		std::string const	&getName(void) const;
		bool				getStatus(void) const;
		unsigned int		getSGrade(void) const;
		unsigned int		getXGrade(void) const;
		void				beSigned(Bureaucrat const &b);
		virtual void		execute(Bureaucrat const & executor) const = 0;

	protected:
		std::string const	_name;
		bool				_status;
		unsigned int		_sgrade;
		unsigned int		_xgrade;

	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

	class AlreadySignedException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

	class NotSignedException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
}	;

std::ostream			&operator<<(std::ostream &lhs, AForm const &rhs);
