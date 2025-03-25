/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimmy <jimmy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 23:50:47 by jimmy             #+#    #+#             */
/*   Updated: 2025/03/25 12:30:16 by jimmy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"


////////////////////////////////////////////////////////////////////////////////
////																		////
////							MEMBER FUNCTIONS							////
////																		////
////////////////////////////////////////////////////////////////////////////////

void	loadContainers(std::string value, std::vector<int>& vectorData, std::list<int>& listData)
{
	size_t	size = value.size();
	for (size_t i = 0; i < size; i++)
		if (!isdigit(value[i]))
			throw std::exception();
	double	number = atol(value.c_str());

	if (number == HUGE_VAL || number == -HUGE_VAL || number < 0 || number > INT_MAX)
		throw std::exception();
	listData.push_back(static_cast<int>(number));
	vectorData.push_back(static_cast<int>(number));
}


void	sortVector(std::vector<int>& vectorData)
{
	int size = vectorData.size();
	if (size <= 1)
		return;

	std::vector<std::pair<int, int> >	pairs;
	std::vector<int>					winners;
	int									halfSize = size / 2;

	pairs.reserve(halfSize);
	winners.reserve(halfSize + size % 2);

	for (int i = 0; i < halfSize; i++)
	{
		int first =vectorData[2 * i];
		int second =vectorData[2 * i + 1];
		if (first < second)
			pairs.push_back(std::pair<int, int>(first, second));
		else
			pairs.push_back(std::pair<int, int>(second, first));
		winners.push_back(pairs.back().second);
	}
	if (size % 2)
		winners.push_back(vectorData[size - 1]);

	sortVector(winners);

	//Sort pairs based on winners order
	//Jacobsthal number
	//Insert losers (pairs[].first)
}



////////////////////////////////////////////////////////////////////////////////
////																		////
////								EXCEPTIONS								////
////																		////
////////////////////////////////////////////////////////////////////////////////
/*
const char*	PmergeMe::InvalidInputException::what(void) const throw()
{
	return ("Error: Invalid input: Must be positive int values");
}*/