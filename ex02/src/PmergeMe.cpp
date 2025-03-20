/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimmy <jimmy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 23:50:47 by jimmy             #+#    #+#             */
/*   Updated: 2025/03/20 11:19:34 by jimmy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

////////////////////////////////////////////////////////////////////////////////
////																		////
////							CONSTRUCTORS								////
////																		////
////////////////////////////////////////////////////////////////////////////////

PmergeMe::PmergeMe(){
//	std::cout << "PmergeMe default constructor called" << std::endl;

}

PmergeMe::~PmergeMe(){
//	std::cout << "PmergeMe destructor called" << std::endl;

}

PmergeMe::PmergeMe(const PmergeMe& other){
//	std::cout << "PmergeMe copy constructor called" << std::endl;
	(void)other;
}

PmergeMe&	PmergeMe::operator=(const PmergeMe& other){
//	std::cout << "PmergeMe copy assignment operator called" << std::endl;
	if (this != &other)
		(void)other;
	return *this;
}



////////////////////////////////////////////////////////////////////////////////
////																		////
////								OVERLOADS								////
////																		////
////////////////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////////////////
////																		////
////							MEMBER FUNCTIONS							////
////																		////
////////////////////////////////////////////////////////////////////////////////

void	PmergeMe::loadContainers(std::string value)
{
	size_t	size = value.size();
	for (size_t i = 0; i < size; i++)
		if (!isdigit(value[i]))
			throw PmergeMe::InvalidInputException();
	double	number = atol(value.c_str());

	if (number == HUGE_VAL || number == -HUGE_VAL || number < 0 || number > INT_MAX)
		throw PmergeMe::InvalidInputException();
	_listContainer.push_back(static_cast<int>(number));
	_vectorContainer.push_back(static_cast<int>(number));
}

void	PmergeMe::displaySequence() const
{

}

void	PmergeMe::displayTimes() const
{

}

void	PmergeMe::sortVector()
{

}

void	PmergeMe::sortList()
{

}


////////////////////////////////////////////////////////////////////////////////
////																		////
////								EXCEPTIONS								////
////																		////
////////////////////////////////////////////////////////////////////////////////

const char*	PmergeMe::InvalidInputException::what(void) const throw()
{
	return ("Error: Invalid input: Must be positive int values");
}