/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aykrifa <aykrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 17:07:00 by aykrifa           #+#    #+#             */
/*   Updated: 2025/08/31 18:35:21 by aykrifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "AForm.hpp"

class	Bureaucrat;
class	RobotomyRequestForm	:	public AForm
{
	public:
		virtual void		execute(Bureaucrat const &executor) const;
}	;
