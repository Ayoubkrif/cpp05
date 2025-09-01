/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aykrifa <aykrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 17:07:00 by aykrifa           #+#    #+#             */
/*   Updated: 2025/09/01 13:44:02 by aykrifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class	Bureaucrat;
class	AForm;
class	Intern
{
	public:
		Intern(void);
		Intern(Intern const &copy);
		virtual ~Intern(void);

		Intern			&operator=(Intern const &rhs);
		AForm			*makeForm(std::string form, std::string target);
	private:
	class DoesNotExistException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
}	;
