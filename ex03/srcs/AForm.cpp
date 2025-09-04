/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aykrifa <aykrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 19:52:45 by aykrifa           #+#    #+#             */
/*   Updated: 2025/09/04 09:34:59 by aykrifa          ###   ########.fr       */
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

AForm::AForm(std::string const name, unsigned int sgrade, unsigned int xgrade)
	:_name(name), _status(false)
	 , _sgrade(sgrade), _xgrade(xgrade)
{
	std::cout << "[🔧]"
		<< *this
		<< " Creation (parameter)!"
		<< std::endl;
	if (this->_sgrade > 150)
		throw GradeTooLowException();
	if (this->_sgrade < 1)
		throw GradeTooHighException();
	if (this->_xgrade > 150)
		throw GradeTooLowException();
	if (this->_xgrade < 1)
		throw GradeTooHighException();
}

AForm::~AForm(void)
{
	std::cout << "[💥]"
		<< *this
		<< " Destruction!"
		<< std::endl;
}

AForm				&AForm::operator=(AForm const &rhs)
{
	std::cout << "[🟰]"
		<< *this
		<< " Assignation!"
		<< std::endl;
	this->_status = rhs._status;
    return *this;
}

std::string const		&AForm::getName(void) const
{
    return (this->_name);
}

bool					AForm::getStatus(void) const
{
    return (this->_status);
}

unsigned int			AForm::getSGrade(void) const
{
    return (this->_sgrade);
}

unsigned int			AForm::getXGrade(void) const
{
    return (this->_xgrade);
}

const char				*AForm::GradeTooHighException::what() const throw()
{
	return ("form grade is too high!");
}
 
const char				*AForm::GradeTooLowException::what() const throw()
{
	return ("form grade is too low!");
}

const char				*AForm::AlreadySignedException::what() const throw()
{
	return ("form is already signed");
}

const char				*AForm::NotSignedException::what() const throw()
{
	return ("form is not signed");
}

std::ostream &operator<<(std::ostream &lhs, AForm const &rhs)
{
    lhs << "AForm " 
        << rhs.getName()
        << " SIGNED:"
        << (rhs.getStatus() ? "✅" : "❌");
    if (!rhs.getStatus())
    {
        lhs << " S:"
            << std::setw(3) << rhs.getSGrade();
    }
    lhs << " X:"
		<< std::setw(3) << rhs.getXGrade()
		<< ".";
    return lhs;
}

void					AForm::beSigned(Bureaucrat const &b)
{
	if (this->getStatus())
		throw (AlreadySignedException());
	if (b.getGrade() > this->getSGrade())
		throw (GradeTooLowException());
	this->_status = true;
}

void					AForm::execute(Bureaucrat const &executor) const
{
	if (!this->getStatus())
		throw (NotSignedException());
	if (executor.getGrade() > this->getXGrade())
		throw (GradeTooLowException());
	action();
}
