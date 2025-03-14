/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbaeza-c <jbaeza-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 13:23:19 by jbaeza-c          #+#    #+#             */
/*   Updated: 2025/03/14 13:53:34 by jbaeza-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	
}

BitcoinExchange::~BitcoinExchange()
{

}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other): _values(other)
{

}

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (*this != other)
		_values = other._values;
	return *this;
}




bool	BitcoinExchange::loadData(std::string fileName)
{
	
}