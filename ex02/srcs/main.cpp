/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aykrifa <aykrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 15:07:36 by aykrifa           #+#    #+#             */
/*   Updated: 2025/09/03 11:34:59 by aykrifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//🟰🔧💥
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

AForm* createShrubbery(std::string const &target) {
    return new ShrubberyCreationForm(target);
}

AForm* createPresidential(std::string const &target) {
    return new PresidentialPardonForm(target);
}

AForm* createRobotomy(std::string const &target) {
    return new RobotomyRequestForm(target);
}

int	main(void)
{
	static AForm* (*formConstructors[])(std::string const &) =
	{
		createShrubbery,
		createPresidential,
		createRobotomy
	};
	std::srand(std::time(NULL));
	std::cout << "/*"
		<< "=========================================================================="
		<< "=========================================================================="
		<< "*/"
		<< std::endl;
	std::cout << "TEST SIGN ❌"
		<< std::endl;
	std::cout << "/*"
		<< "=========================================================================="
		<< "=========================================================================="
		<< "*/"
		<< std::endl;
	for (int i = 0; i < 3; i++)
	{
		try
		{
			Bureaucrat	b("Random", 150);
			AForm		*scb = formConstructors[i]("Target"); 

			b.signForm(*scb);
			b.executeForm(*scb);
			delete scb;
		}
		catch (std::exception &e)
		{
			std::cerr << "exception caught : "
				<< e.what()
				<< std::endl;
		}
	}
	std::cout << "/*"
		<< "=========================================================================="
		<< "=========================================================================="
		<< "*/"
		<< std::endl;
	std::cout << "TEST SIGN ✅ EXEC ✅"
		<< std::endl;
	std::cout << "/*"
		<< "=========================================================================="
		<< "=========================================================================="
		<< "*/"
		<< std::endl;
	for (int i = 0; i < 3; i++)
	{
		try
		{
			Bureaucrat	b("ayoub", 1);
			AForm		*scb = formConstructors[i]("Target"); 

			b.signForm(*scb);
			b.executeForm(*scb);
			delete scb;
		}
		catch (std::exception &e)
		{
			std::cerr << "exception caught : "
				<< e.what()
				<< std::endl;
		}
	}
	std::cout << "/*"
		<< "=========================================================================="
		<< "=========================================================================="
		<< "*/"
		<< std::endl;
	std::cout << "TEST SIGN ✅ EXEC ❌"
		<< std::endl;
	std::cout << "/*"
		<< "=========================================================================="
		<< "=========================================================================="
		<< "*/"
		<< std::endl;
	for (int i = 0; i < 3; i++)
	{
		try
		{
			Bureaucrat	b("ayoub", 1);
			Bureaucrat	b2("random", 150);
			AForm		*scb = formConstructors[i]("Target"); 

			b.signForm(*scb);
			b2.executeForm(*scb);
			delete scb;
		}
		catch (std::exception &e)
		{
			std::cerr << "exception caught : "
				<< e.what()
				<< std::endl;
		}
	}
	std::cout << "/*"
		<< "=========================================================================="
		<< "=========================================================================="
		<< "*/"
		<< std::endl;
	std::cout << "TEST EXEC NO SIGN"
		<< std::endl;
	std::cout << "/*"
		<< "=========================================================================="
		<< "=========================================================================="
		<< "*/"
		<< std::endl;
	for (int i = 0; i < 3; i++)
	{
		try
		{
			Bureaucrat	b("ayoub", 1);
			AForm		*scb = formConstructors[i]("Target"); 

			b.executeForm(*scb);
			delete scb;
		}
		catch (std::exception &e)
		{
			std::cerr << "exception caught : "
				<< e.what()
				<< std::endl;
		}
	}
	return 0;
}
