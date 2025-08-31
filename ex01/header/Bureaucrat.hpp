/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aykrifa <aykrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 17:07:00 by aykrifa           #+#    #+#             */
/*   Updated: 2025/08/31 16:32:15 by aykrifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class	Form;
class	Bureaucrat
{
	public:
		Bureaucrat(void);
		Bureaucrat(Bureaucrat const &copy);
		Bureaucrat(std::string const name, unsigned int grade);
		~Bureaucrat(void);

		Bureaucrat			&operator=(Bureaucrat const &rhs);
		std::string const	&getName(void) const;
		unsigned int		getGrade(void) const;
		void				promotion(void);
		void				demotion(void);
		void				signForm(Form &f);

	private:
		std::string const	_name;
		unsigned int		_grade;

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
}	;

std::ostream			&operator<<(std::ostream &lhs, Bureaucrat const &rhs);
