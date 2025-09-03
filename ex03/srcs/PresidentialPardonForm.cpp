/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aykrifa <aykrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 19:52:45 by aykrifa           #+#    #+#             */
/*   Updated: 2025/09/03 11:44:08 by aykrifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include <iomanip>
#include <ostream>

PresidentialPardonForm::PresidentialPardonForm(void)
	:	AForm("PresidentialPardonForm", 25, 5), _target("default")
{
	std::cout << "[🔧]"
		<< *this
		<< " Creation (default)!"
		<< std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const target)
	:	AForm("PresidentialPardonForm", 25, 5),
			_target(target)
{
	std::cout << "[🔧]"
		<< *this
		<< " Creation (parameter)!"
		<< std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &copy)
	:	AForm(copy._name, copy._sgrade, copy._xgrade),
			_target(copy._target)
{
	std::cout << "[🔧]"
		<< *this
		<< " Creation (copy)!"
		<< std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << "[💥]"
		<< *this
		<< " Destruction!"
		<< std::endl;
}

PresidentialPardonForm		&PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs)
{
	std::cout << "[🟰]"
		<< *this
		<< " Asignation!"
		<< std::endl;
	this->_target = rhs._target;
    return *this;
}

void					PresidentialPardonForm::action(void) const
{
	std::cout << _target
		<< "has been pardoned by Zaphod Beeblebrox"
		<< std::endl;
}
