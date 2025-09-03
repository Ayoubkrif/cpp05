/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aykrifa <aykrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 19:52:45 by aykrifa           #+#    #+#             */
/*   Updated: 2025/09/03 15:49:29 by aykrifa          ###   ########.fr       */
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

AForm* createShrubbery(std::string const &target) {
    return new ShrubberyCreationForm(target);
}

AForm* createPresidential(std::string const &target) {
    return new PresidentialPardonForm(target);
}

AForm* createRobotomy(std::string const &target) {
    return new RobotomyRequestForm(target);
}

AForm *Intern::makeForm(std::string name,std::string target)
{
	static std::string forms[] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
	static AForm* (*formConstructors[])(std::string const &) =
	{
		createShrubbery,
		createRobotomy,
		createPresidential
	};

	std::cout << "Intern try to create "
		<< name
		<< std::endl;
	for (int i = 0; i < 3 ; i++)
	{
		if (name == forms[i])
			return (formConstructors[i](target));
	}
	throw (DoesNotExistException());
}
