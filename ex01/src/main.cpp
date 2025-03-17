/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimmy <jimmy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 13:21:17 by jbaeza-c          #+#    #+#             */
/*   Updated: 2025/03/16 14:35:20 by jimmy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>


int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Invalid number of arguments. Please, introduce a mathematical expression" << std::endl;
		return 1;
	}
	try
	{
		RPN rpn;
		std::string	mathExpression(argv[1]);
		std::cout << rpn.algorithm(mathExpression) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	
	return 0;
}