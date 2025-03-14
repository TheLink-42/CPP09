/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbaeza-c <jbaeza-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 13:21:17 by jbaeza-c          #+#    #+#             */
/*   Updated: 2025/03/13 13:37:55 by jbaeza-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyFind.hpp"
#include <iostream>
#include <vector>
#include <list>

int main()
{
	std::vector<int>	vec;
	std::list<int>		lst;

	for (int i = 0; i < 20; i++)
	{
		vec.push_back(i);
		lst.push_back(i);
	}
	try
	{
		std::cout << *easyFind(vec, 10) << std::endl;
		std::cout << "Test 1 completed successfully" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		std::cout << *easyFind(vec, 20) << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		std::cout << "Test 2 completed successfully" << std::endl;
	}

	try
	{
		std::cout << *easyFind(lst, 10) << std::endl;
		std::cout << "Test 3 completed successfully" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::cout << *easyFind(lst, 20) << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		std::cout << "Test 4 completed successfully" << std::endl;
	}

	return 0;
}