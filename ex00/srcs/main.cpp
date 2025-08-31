/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aykrifa <aykrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 15:07:36 by aykrifa           #+#    #+#             */
/*   Updated: 2025/08/31 15:30:17 by aykrifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//🟰🔧💥
#include <iostream>
#include "Bureaucrat.hpp"

int	main(void)
{
	try{
		Bureaucrat	random;

		while (true)
			random.demotion();
	}catch (std::exception &e)
	{
		std::cerr << "Exception caught: "
			<< e.what()
			<< std::endl;
	}
/* ************************************************************************** */
	try{
		Bureaucrat	president("aykrifa", 1);

		while (true)
			president.promotion();
	}catch (std::exception &e)
	{
		std::cerr << "Exception caught: "
			<< e.what()
			<< std::endl;
	}
/* ************************************************************************** */
	try{
		Bureaucrat	president("aykrifa", 0);
	}catch (std::exception &e)
	{
		std::cerr << "Exception caught: "
			<< e.what()
			<< std::endl;
	}
/* ************************************************************************** */
	try{
		Bureaucrat	random("random", 151);
	}catch (std::exception &e)
	{
		std::cerr << "Exception caught: "
			<< e.what()
			<< std::endl;
	}
	return 0;
}
