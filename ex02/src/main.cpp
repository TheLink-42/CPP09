/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimmy <jimmy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 13:21:17 by jbaeza-c          #+#    #+#             */
/*   Updated: 2025/03/20 11:17:32 by jimmy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>


int main(int argc, char **argv)
{
	if (argc <2)
	{
		std::cout << "Invalid number of arguments." << std::endl;
		return 1;
	}
	try
	{
		PmergeMe	algorithm;
		for (int i = 1; i < argc; i++)
		{
			std::string	str(argv[i]);
			algorithm.loadContainers(str);
		}

		std::cout << "Before: ";
		algorithm.displaySequence();

		algorithm.sortVector();
		algorithm.sortList();

		std::cout << "After: ";
		algorithm.displaySequence();

		algorithm.displayTimes();
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	
	return 0;
}