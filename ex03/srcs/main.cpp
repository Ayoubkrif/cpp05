/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aykrifa <aykrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 15:07:36 by aykrifa           #+#    #+#             */
/*   Updated: 2025/09/01 14:35:41 by aykrifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//🟰🔧💥
#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int	main(void)
{
	{
		Intern	random;
		AForm		*scb;
		try{
			scb = random.makeForm("PresidentialPardonForm", "target");
		}catch (std::exception &e){
			std::cerr << "cannot create form: "
				<< e.what()
				<< std::endl;
			return (1);
		}
		Bureaucrat	boss("ayoub", 1);
		boss.signForm(*scb);
		std::cout << scb->getName() << std::endl;
		boss.executeForm(*scb);
		delete scb;
	}
	return 0;
}
