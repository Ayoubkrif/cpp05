/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aykrifa <aykrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 19:52:45 by aykrifa           #+#    #+#             */
/*   Updated: 2025/09/02 09:19:39 by aykrifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern(void)
{
	std::cout << "[🔧]"
		<< "Intern creation (default)!"
		<< std::endl;
}


Intern::Intern(Intern const &copy)
{
	(void)copy;
	std::cout << "[🔧]"
		<< "intern Creation (copy)!"
		<< std::endl;
}


Intern::~Intern(void)
{
	std::cout << "[💥]"
		<< "Intern Destruction!"
		<< std::endl;
}

Intern				&Intern::operator=(Intern const &rhs)
{
	(void)rhs;
	std::cout << "[🟰]"
		<< "Intern Assignation!"
		<< std::endl;
    return *this;
}

const char				*Intern::DoesNotExistException::what() const throw()
{
	return ("form does not exist");
}

AForm *Intern::makeForm(std::string name,std::string target)
{
	int i = 0;
	static std::string forms[] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};

	while (i < 3 && name != forms[i])
		i++;
	
	std::cout << "Intern try to create "
		<< name
		<< std::endl;
	switch (i)
	{
		default:
			throw (DoesNotExistException());
		case 0:
			return (new ShrubberyCreationForm(target));
		case 1:
			return (new RobotomyRequestForm(target));
		case 2:
			return (new PresidentialPardonForm (target));
	}
}
