/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aykrifa <aykrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 15:07:36 by aykrifa           #+#    #+#             */
/*   Updated: 2025/09/02 09:40:19 by aykrifa          ###   ########.fr       */
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

int	main(void)
{
	std::srand(std::time(NULL));
	{
		AForm		*scb = new ShrubberyCreationForm("Jardin_of_the_betarde");
		AForm		*scc = new ShrubberyCreationForm("Jardin_of_the_gigachad");
		Bureaucrat	boss("ayoub", 200);
		boss.signForm(*scb);
		*scc = *scb;
		boss.signForm(*scc);
		std::cout << scc->getName() << std::endl;
		std::cout << scb->getName() << std::endl;
		boss.executeForm(*scc);
		boss.executeForm(*scb);
		delete scc;
		delete scb;
	}
	return 0;
}
