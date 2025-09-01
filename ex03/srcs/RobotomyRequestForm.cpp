/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aykrifa <aykrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 19:52:45 by aykrifa           #+#    #+#             */
/*   Updated: 2025/09/01 14:38:11 by aykrifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm(void)
	:	AForm("RobotomyRequestForm", 72, 45), _target("default")
{
	std::cout << "[🔧]"
		<< *this
		<< " Creation (default)!"
		<< std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const target)
	:	AForm("RobotomyRequestForm", 72, 45),
			_target(target)
{
	std::cout << "[🔧]"
		<< *this
		<< " Creation (parameter)!"
		<< std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &copy)
	:	AForm(copy._name, copy._sgrade, copy._xgrade),
			_target(copy._target)
{
	std::cout << "[🔧]"
		<< *this
		<< " Creation (copy)!"
		<< std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << "[💥]"
		<< *this
		<< " Destruction!"
		<< std::endl;
}

RobotomyRequestForm		&RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs)
{
	std::cout << "[🟰]"
		<< *this
		<< " RobotomyRequests Asignation!"
		<< std::endl;
	this->_status = rhs._status;
	this->_sgrade = rhs._sgrade;
	this->_xgrade = rhs._xgrade;
	this->_target = rhs._target;
    return *this;
}

void					RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > this->getXGrade())
		throw (GradeTooLowException());
	if (!this->getSGrade())
		throw (NotSignedException());

	static int counter = 0;

	std::cout << "* Drilling noises *"
		<< std::endl
		<<  "Robotomisation on "
		<< this->_target
		<< (++counter % 2 ? " succeed !" : " failed !")
		<< std::endl;
}
