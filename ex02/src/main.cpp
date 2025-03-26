/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimmy <jimmy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 13:21:17 by jbaeza-c          #+#    #+#             */
/*   Updated: 2025/03/26 02:49:43 by jimmy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <sys/time.h>

static long long getTimeInMicroseconds()
{
	struct timeval	time;
	gettimeofday(&time, NULL);
	return (static_cast<long long>(time.tv_sec) * 1000000LL + time.tv_usec);
}

static void	loadData(int argc, char** argv, PmergeMe<std::vector<int> >& vectorContainer, PmergeMe<std::deque<int> >& dequeContainer)
{
	for (int i = 1; i < argc; i++)
	{
		std::string	str(argv[i]);
		vectorContainer.add(str);
		dequeContainer.add(str);
	}
}


static void	sortData(PmergeMe<std::vector<int> >& vectorContainer, PmergeMe<std::deque<int> >& dequeContainer)
{
	long long	vectorTime = 0;
	long long	dequeTime = 0;
	long long	startTime = 0;
	long long	endTime = 0;

	double		vTime = 0.0;
	double		dTime = 0.0;

	std::cout << "Before ";
	vectorContainer.displayContainer();

	startTime = getTimeInMicroseconds();
	vectorContainer.sort();
	endTime = getTimeInMicroseconds();
	vectorTime = endTime - startTime;

	startTime = getTimeInMicroseconds();
	dequeContainer.sort();
	endTime = getTimeInMicroseconds();
	dequeTime = endTime - startTime;

	vTime = static_cast<double>(vectorTime) / 1000;
	dTime = static_cast<double>(dequeTime) / 1000;

	std::cout << "After ";
	vectorContainer.displayContainer();

	std::cout << "Time to process a range of " << vectorContainer.size() << " elements with std::vector: " << vTime << " ms" << std::endl;
	std::cout << "Time to process a range of " << vectorContainer.size() << " elements with std::deque: " << dTime << " ms" << std::endl;
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
		PmergeMe<std::vector<int> >	vectorContainer;
		PmergeMe<std::deque<int> > dequeContainer;

		loadData(argc, argv, vectorContainer, dequeContainer);
		sortData(vectorContainer, dequeContainer);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	
	return 0;
}