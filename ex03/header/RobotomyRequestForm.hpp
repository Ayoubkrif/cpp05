/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aykrifa <aykrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 17:07:00 by aykrifa           #+#    #+#             */
/*   Updated: 2025/09/03 11:41:53 by aykrifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "AForm.hpp"

class	Bureaucrat;
class	RobotomyRequestForm	:	public AForm
{
	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(RobotomyRequestForm const &copy);
		RobotomyRequestForm(std::string const target);
		virtual ~RobotomyRequestForm(void);

		RobotomyRequestForm				&operator=(RobotomyRequestForm const &rhs);
		virtual void					action(void) const;
	private:
		std::string						_target;
}	;
