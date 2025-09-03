/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aykrifa <aykrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 15:07:36 by aykrifa           #+#    #+#             */
/*   Updated: 2025/09/03 10:56:19 by aykrifa          ###   ########.fr       */
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
#include "Intern.hpp"

int	main(void)
{
	std::srand(std::time(NULL));
	{
		Intern	random;
		AForm		*scb;
		try
		{
			scb = random.makeForm("RobotomyRequestForm", "target");
		}
		catch (std::exception &e)
		{
			std::cerr << "cannot create form: "
				<< e.what()
				<< std::endl;
			return (1);
		}
		try
		{
			Bureaucrat	boss("ayoub", 1);
			boss.signForm(*scb);
			std::cout << scb->getName() << std::endl;
			boss.executeForm(*scb);
			delete scb;
		}
		catch (std::exception &e)
		{
			delete scb;
		}
	}
	{
		Intern	random;
		AForm		*scb;
		try
		{
			scb = random.makeForm("ShrubberyCreationForm", "target");
		}
		catch (std::exception &e)
		{
			std::cerr << "cannot create form: "
				<< e.what()
				<< std::endl;
			return (1);
		}
		try
		{
			Bureaucrat	boss("ayoub", 1);
			boss.signForm(*scb);
			std::cout << scb->getName() << std::endl;
			boss.executeForm(*scb);
			delete scb;
		}
		catch (std::exception &e)
		{
			delete scb;
		}
	}
	{
		Intern	random;
		AForm		*scb;
		try
		{
			scb = random.makeForm("PresidentialPardonForm", "target");
		}
		catch (std::exception &e)
		{
			std::cerr << "cannot create form: "
				<< e.what()
				<< std::endl;
			return (1);
		}
		try
		{
			Bureaucrat	boss("ayoub", 1);
			boss.signForm(*scb);
			std::cout << scb->getName() << std::endl;
			boss.executeForm(*scb);
			delete scb;
		}
		catch (std::exception &e)
		{
			delete scb;
		}
	}
	{
		Intern	random;
		AForm		*scb;
		try
		{
			scb = random.makeForm("kkboud1", "target");
		}
		catch (std::exception &e)
		{
			std::cerr << "cannot create form: "
				<< e.what()
				<< std::endl;
			return (1);
		}
		try
		{
			Bureaucrat	boss("ayoub", 1);
			boss.signForm(*scb);
			std::cout << scb->getName() << std::endl;
			boss.executeForm(*scb);
			delete scb;
		}
		catch (std::exception &e)
		{
			delete scb;
		}
	}
	return 0;
}
