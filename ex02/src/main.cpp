/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimmy <jimmy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 13:21:17 by jbaeza-c          #+#    #+#             */
/*   Updated: 2025/03/24 22:46:44 by jimmy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
# include <chrono>

static long long getTimeInMicroseconds()
{
	struct timeval	time;
	gettimeofday(&time, NULL);
	return (static_cast<long long>(time.tv_sec) * 1000000LL + time.tv_usec);
}

static void	loadData(int argc, char** argv, std::vector<int>& vectorData, std::list<int>& listData)
{
	for (int i = 1; i < argc; i++)
	{
		std::string	str(argv[i]);
		loadContainers(str, vectorData, listData);
	}
}


static void	sortData(std::vector<int>& vectorData, std::list<int>& listData)
{
	int	size = vectorData.size();
	long long	vectorTime = 0;
	long long	listTime = 0;
	long long	startTime = 0;
	long long	endTime = 0;

	std::cout << "Before ";
	for (int i = 0; i < size; i++)
		std::cout << " " << vectorData[i];
	std::cout << std::endl;

	startTime = getTimeInMicroseconds();
	sortVector(vectorData);
	endTime = getTimeInMicroseconds();
	vectorTime = endTime - startTime;

	startTime = getTimeInMicroseconds();
	sortList(listData);
	endTime = getTimeInMicroseconds();
	listTime = endTime - startTime;
}

int main(int argc, char **argv)
{
	if (argc <2)
	{
		std::cout << "Invalid number of arguments." << std::endl;
		return 1;
	}
	try
	{
		std::vector<int>	vectorData;
		std::list<int>		listData;

		loadData(argc, argv, vectorData, listData);
		sortData(vectorData, listData);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	
	return 0;
}