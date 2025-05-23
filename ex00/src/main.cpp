/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimmy <jimmy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 13:21:17 by jbaeza-c          #+#    #+#             */
/*   Updated: 2025/03/15 02:15:43 by jimmy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"




int main(int argc, char **argv)
{
	std::ifstream	file;
	std::string		line;

	if (argc != 2)
	{
		std::cerr << "Error: invalid number of arguments." << std::endl;
		return 1;
	}
	
	try
	{
		BitcoinExchange	btc;
		file.open(argv[1]);
		if (!file.is_open())
		{
			std::cerr << "Error: could not open file." << std::endl;
			return 2;
		}
	
		std::getline(file, line);
		while (std::getline(file, line))
		{
			try
			{
				btc.exchange(line);
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << std::endl;
			}
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return -1;
	}
	


	return 0;
}