/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aykrifa <aykrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 17:07:00 by aykrifa           #+#    #+#             */
/*   Updated: 2025/08/31 23:04:10 by aykrifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "AForm.hpp"

class	Bureaucrat;
class	ShrubberyCreationForm	:	public AForm
{
	public:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(ShrubberyCreationForm const &copy);
		ShrubberyCreationForm(std::string const target);
		virtual ~ShrubberyCreationForm(void);

		ShrubberyCreationForm			&operator=(ShrubberyCreationForm const &rhs);
		virtual void					execute(Bureaucrat const &executor) const;
	private:
		std::string						_target;
}	;
