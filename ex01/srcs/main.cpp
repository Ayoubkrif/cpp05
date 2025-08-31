/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aykrifa <aykrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 15:07:36 by aykrifa           #+#    #+#             */
/*   Updated: 2025/08/31 16:47:07 by aykrifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//🟰🔧💥
#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	{
		try {
			Form	fxlow("fxlow", 1, 151);
		} catch (std::exception &e) {
			std::cerr << "Exception caught: "
					  << e.what()
					  << std::endl;
		}
	}

	{
		try {
			Form	fslow("fslow", 151, 1);
		} catch (std::exception &e) {
			std::cerr << "Exception caught: "
					  << e.what()
					  << std::endl;
		}
	}

	{
		try {
			Form	fshigh("fshigh", 0, 1);
		} catch (std::exception &e) {
			std::cerr << "Exception caught: "
					  << e.what()
					  << std::endl;
		}
	}

	{
		try {
			Form	fxlow("f", 1, 0);
		} catch (std::exception &e) {
			std::cerr << "Exception caught: "
					  << e.what()
					  << std::endl;
		}
	}

	{
		try {
			Form		f0("f0", 140, 50);
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
			Form		f1("f1", 140, 50);
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
			Form		f2("f2", 140, 50);

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
