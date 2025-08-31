/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    ShrubberyCreationForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aykrifa <aykrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 19:52:45 by aykrifa           #+#    #+#             */
/*   Updated: 2025/08/31 18:39:06 by aykrifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iomanip>

AForm::AForm(void)
	: _name("default"), _status(false)
	  , _sgrade(150), _xgrade(150)
{
	std::cout << "[🔧]"
		<< *this
		<< " Creation (default)!"
		<< std::endl;
}


AForm::AForm(AForm const &copy)
	:	_name(copy._name), _status(copy._status)
		, _sgrade(copy._sgrade), _xgrade(copy._xgrade)
{
	std::cout << "[🔧]"
		<< *this
		<< " Creation (copy)!"
		<< std::endl;
}

AForm::~AForm(void)
{
	std::cout << "[💥]"
		<< *this
		<< " Destruction!"
		<< std::endl;
}
