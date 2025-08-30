/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aykrifa <aykrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 19:52:45 by aykrifa           #+#    #+#             */
/*   Updated: 2025/08/30 20:22:01 by aykrifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void): _name("default"), _grade(150)
{
}


Bureaucrat::Bureaucrat(Bureaucrat const &copy):	_name(copy._name), _grade(copy._grade)
{
}

Bureaucrat::Bureaucrat(std::string const name, unsigned int grade): _name(name), _grade(grade)
{
	if (this->_grade > 150)
		;
}
		/*~Bureaucrat(void);*/
		/**/
		/*Bureaucrat			&operator=(Bureaucrat const &rhs);*/
		/*std::string const	&getName(void) const;*/
		/*unsigned int		getGrade(void) const;*/
		/*void				promotion(void);*/
		/*void				demotion(void);*/
