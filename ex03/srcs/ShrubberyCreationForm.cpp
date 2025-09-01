/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aykrifa <aykrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 19:52:45 by aykrifa           #+#    #+#             */
/*   Updated: 2025/09/01 14:24:40 by aykrifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void)
	:	AForm("ShrubberyCreationForm", 145, 137), _target("default")
{
	std::cout << "[🔧]"
		<< *this
		<< " Creation (default)!"
		<< std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const target)
	:	AForm("ShrubberyCreationForm", 145, 137),
			_target(target)
{
	std::cout << "[🔧]"
		<< *this
		<< " Creation (parameter)!"
		<< std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &copy)
	:	AForm(copy._name, copy._sgrade, copy._xgrade),
			_target(copy._target)
{
	std::cout << "[🔧]"
		<< *this
		<< " Creation (copy)!"
		<< std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << "[💥]"
		<< *this
		<< " Destruction!"
		<< std::endl;
}

ShrubberyCreationForm		&ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs)
{
	std::cout << "[🟰]"
		<< *this
		<< " Asignation!"
		<< std::endl;
	this->_status = rhs._status;
	this->_sgrade = rhs._sgrade;
	this->_xgrade = rhs._xgrade;
	this->_target = rhs._target;
    return *this;
}

#include <fstream>
#include <cstring>

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (!this->getSGrade())
		throw (NotSignedException());
	if (executor.getGrade() > this->getXGrade())
		throw (GradeTooLowException());

	std::ofstream Outputfs((_target + "_shrubbery").c_str());

	if (!Outputfs.is_open())
		throw (std::runtime_error("Cannot open '" + _target + "_shrubbery': " + std::strerror(errno)));

	Outputfs << "  A       A  " << std::endl;
	Outputfs << " /v\\     /v\\ " << std::endl;
	Outputfs << "/vvv\\   /vvv\\" << std::endl;
	Outputfs << "  !       !  " << std::endl;
}
