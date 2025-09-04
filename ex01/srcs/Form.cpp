/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aykrifa <aykrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 19:52:45 by aykrifa           #+#    #+#             */
/*   Updated: 2025/09/04 09:23:41 by aykrifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iomanip>

Form::Form(void)
	: _name("default"), _status(false)
	  , _sgrade(150), _xgrade(150)
{
	std::cout << "[🔧]"
		<< *this
		<< " Creation (default)!"
		<< std::endl;
}


Form::Form(Form const &copy)
	:	_name(copy._name), _status(copy._status)
		, _sgrade(copy._sgrade), _xgrade(copy._xgrade)
{
	std::cout << "[🔧]"
		<< *this
		<< " Creation (copy)!"
		<< std::endl;
}

Form::Form(std::string const name, unsigned int sgrade, unsigned int xgrade)
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

Form::~Form(void)
{
	std::cout << "[💥]"
		<< *this
		<< " Destruction!"
		<< std::endl;
}

Form				&Form::operator=(Form const &rhs)
{
	std::cout << "[🟰]"
		<< *this
		<< " Assignation!"
		<< std::endl;
	this->_status = rhs._status;
    return *this;
}

std::string const		&Form::getName(void) const
{
    return (this->_name);
}

bool					Form::getStatus(void) const
{
    return (this->_status);
}

unsigned int			Form::getSGrade(void) const
{
    return (this->_sgrade);
}

unsigned int			Form::getXGrade(void) const
{
    return (this->_xgrade);
}

const char				*Form::GradeTooHighException::what() const throw()
{
	return ("form grade is too high!");
}
 
const char				*Form::GradeTooLowException::what() const throw()
{
	return ("form grade is too low!");
}

const char				*Form::AlreadySignedException::what() const throw()
{
	return ("form is already signed");
}

std::ostream &operator<<(std::ostream &lhs, Form const &rhs)
{
    lhs << "Form: " 
        << rhs.getName()
        << std::setw(10) << (rhs.getStatus() ? " signed" : " not signed");
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

void					Form::beSigned(Bureaucrat const &b)
{
	if (b.getGrade() > getSGrade())
		throw (GradeTooLowException());
	if (getStatus())
		throw (AlreadySignedException());
	this->_status = true;
}
