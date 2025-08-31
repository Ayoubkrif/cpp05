/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aykrifa <aykrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 17:07:00 by aykrifa           #+#    #+#             */
/*   Updated: 2025/08/31 17:19:40 by aykrifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class	Bureaucrat;
class	Form
{
	public:
		Form(void);
		Form(Form const &copy);
		Form(std::string const name, unsigned int sgrade, unsigned int xgrade);
		~Form(void);

		Form			&operator=(Form const &rhs);
		std::string const	&getName(void) const;
		bool				getStatus(void) const;
		unsigned int		getSGrade(void) const;
		unsigned int		getXGrade(void) const;
		void				beSigned(Bureaucrat const &b);

	private:
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
}	;

std::ostream			&operator<<(std::ostream &lhs, Form const &rhs);
