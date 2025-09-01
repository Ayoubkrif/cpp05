/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aykrifa <aykrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 19:52:45 by aykrifa           #+#    #+#             */
/*   Updated: 2025/09/01 12:49:57 by aykrifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iomanip>

Bureaucrat::Bureaucrat(void): _name("default"), _grade(150)
{
	std::cout << "[🔧]"
		<< "Bureaucrat "
		<< _name
		<< " Creation (default)!"
		<< std::endl;
}


Bureaucrat::Bureaucrat(Bureaucrat const &copy):	_name(copy._name), _grade(copy._grade)
{
	std::cout << "[🔧]"
		<< *this
		<< " Creation (copy)!"
		<< std::endl;
	if (this->_grade > 150)
		throw GradeTooLowException();
	if (this->_grade < 1)
		throw GradeTooHighException();
}

Bureaucrat::Bureaucrat(std::string const name, unsigned int grade): _name(name), _grade(grade)
{
	std::cout << "[🔧]"
		<< *this
		<< " Creation (parameter)!"
		<< std::endl;
	if (this->_grade > 150)
		throw GradeTooLowException();
	if (this->_grade < 1)
		throw GradeTooHighException();
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "[💥]"
		<< *this
		<< " Destruction!"
		<< std::endl;
}

Bureaucrat				&Bureaucrat::operator=(Bureaucrat const &rhs)
{
	std::cout << "[🟰]"
		<< *this
		<< " Assignation!"
		<< std::endl;
	this->_grade = rhs._grade;
    return *this;
}

std::string const		&Bureaucrat::getName(void) const
{
    return (this->_name);
}

unsigned int			Bureaucrat::getGrade(void) const
{
    return (this->_grade);
}

void					Bureaucrat::promotion(void)
{
	std::cout << "[📈]"
		<< *this
		<< " Promoted"
		<< std::endl;
    if (this->_grade <= 1)
        throw GradeTooHighException();
    this->_grade--;
}

void					Bureaucrat::demotion(void)
{
	std::cout << "[📉]"
		<< *this
		<< " Demoted!"
		<< std::endl;
    if (this->_grade >= 150)
        throw GradeTooLowException();
    this->_grade++;
}

const char				*Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Bureaucrat grade is too high!");
}
 
const char				*Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Bureaucrat grade is too low!");
}

std::ostream			&operator<<(std::ostream &lhs, Bureaucrat const &rhs)
{
	lhs << rhs.getName()
		<< " bureaucrat grade "
		<< std::setw(3) << rhs.getGrade()
		<< ".";
	return (lhs);
}

#include "AForm.hpp"

void					Bureaucrat::signForm(AForm &f)
{
	try{
		std::cout << *this
			<< " is trying to sign "
			<< f
			<< std::endl;
		f.beSigned(*this);
	std::cout << getName()
		<< " signed "
		<< f.getName()
		<< std::endl;
	}catch(std::exception &e){
		std::cerr << "Cannot sign "
			<< f
			<< " because: "
			<< e.what()
			<< std::endl;
	};
}

void				Bureaucrat::executeForm(AForm const &f) const
{
	try{
		std::cout << *this
			<< " is trying to execute "
			<< f
			<< std::endl;
		f.execute(*this);
	std::cout << getName()
		<< " executed "
		<< f.getName()
		<< std::endl;
	}catch(std::exception &e){
		std::cerr << "Cannot execute "
			<< f
			<< " because: "
			<< e.what()
			<< std::endl;
	};
}
