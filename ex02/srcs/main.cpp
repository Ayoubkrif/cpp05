/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aykrifa <aykrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 15:07:36 by aykrifa           #+#    #+#             */
/*   Updated: 2025/08/31 18:18:23 by aykrifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//🟰🔧💥
#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

int	main(void)
{
	{
		try {
			AForm	fxlow("fxlow", 1, 151);
		} catch (std::exception &e) {
			std::cerr << "Exception caught: "
					  << e.what()
					  << std::endl;
		}
	}

	{
		try {
			AForm	fslow("fslow", 151, 1);
		} catch (std::exception &e) {
			std::cerr << "Exception caught: "
					  << e.what()
					  << std::endl;
		}
	}

	{
		try {
			AForm	fshigh("fshigh", 0, 1);
		} catch (std::exception &e) {
			std::cerr << "Exception caught: "
					  << e.what()
					  << std::endl;
		}
	}

	{
		try {
			AForm	fxlow("f", 1, 0);
		} catch (std::exception &e) {
			std::cerr << "Exception caught: "
					  << e.what()
					  << std::endl;
		}
	}

	{
		try {
			AForm		f0("f0", 140, 50);
			Bureaucrat	boss0("boss0", 1);

			boss0.signForm(f0);
		} catch (std::exception &e) {
			std::cerr << "Exception caught: "
					  << e.what()
					  << std::endl;
		}
	}

	{
		try {
			AForm		f1("f1", 140, 50);
			Bureaucrat	b1("b1", 150);

			b1.signForm(f1);
		} catch (std::exception &e) {
			std::cerr << "Exception caught: "
					  << e.what()
					  << std::endl;
		}
	}

	{
		try {
			Bureaucrat	boss("boss", 1);
			AForm		f2("f2", 140, 50);

			boss.signForm(f2);
			boss.signForm(f2);
		} catch (std::exception &e) {
			std::cerr << "Exception caught: "
					  << e.what()
					  << std::endl;
		}
	}

	return 0;
}
