/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimmy <jimmy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 13:23:19 by jbaeza-c          #+#    #+#             */
/*   Updated: 2025/03/15 02:19:56 by jimmy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

////////////////////////////////////////////////////////////////////////////////
////																		////
////							CONSTRUCTORS								////
////																		////
////////////////////////////////////////////////////////////////////////////////

BitcoinExchange::BitcoinExchange()
{
	loadData("data.csv");
}

BitcoinExchange::~BitcoinExchange()
{

}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
	_values = other._values;
}

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
		_values = other._values;
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

static float	parseValue(const std::string& line, size_t pos)
{
	double	value;

	errno = 0;
	value = atof(line.substr(pos + 1).c_str());

	if (value == HUGE_VAL || value == -HUGE_VAL)
		throw BitcoinExchange::ConversionFailedException();
	if (value > std::numeric_limits<float>::max() || value < -std::numeric_limits<float>::max())
	throw BitcoinExchange::ConversionFailedException();

	return static_cast<float>(value);
}

static void		validateDate(const std::string& date, const std::string& line)
{
	int	year = atoi(date.substr(0, 4).c_str());
	int	month = atoi(date.substr(5, 2).c_str());
	int	day = atoi(date.substr(8, 2).c_str());

	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
		throw BitcoinExchange::BadInputException(line);

	if (year < 2009 || year > 2025)
		throw BitcoinExchange::BadInputException(line);
	if (month < 1 || month > 12)
		throw BitcoinExchange::BadInputException(line);
	if (day < 1 || day > 31)
		throw BitcoinExchange::BadInputException(line);

	if (year == 2009 && month == 1 && day < 2)
		throw BitcoinExchange::BadInputException(line);
	if (year == 2025 && month > 3)
		throw BitcoinExchange::BadInputException(line);
	if (month == 2 && day > 28)
		throw BitcoinExchange::BadInputException(line);
	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
		throw BitcoinExchange::BadInputException(line);
}

static void		validateAmount(const float& amount)
{
	if (amount < 0)
		throw BitcoinExchange::NegativeNumberException();
	if (amount > 1000)
		throw BitcoinExchange::LargeNumberException();
}

//PRIVATE//

void	BitcoinExchange::loadData(const std::string& fileName)
{
	std::string		fName = "./tools/" + fileName;
	std::ifstream	file;

	file.open(fName.c_str());
	if (!file.is_open())
		throw BitcoinExchange::DataFileOpeningException();
	
	std::string	line;
	size_t		pos;

	std::string	key;
	float		value;

	std::getline(file, line);
	while (std::getline(file, line))
	{
		pos = line.find(',');
		if (pos == std::string::npos)
			throw BitcoinExchange::InvalidDataException();
		try
		{
			key = line.substr(0, pos);
			value = parseValue(line, pos);
			_values[key] = value;
		}
		catch(const std::exception& e)
		{
			(void) e;
			throw;
		}
	}

	file.close();
}

float	BitcoinExchange::getBtcPrice(std::string& key) const
{
	std::map<std::string, float>::const_iterator	it;

	it = _values.upper_bound(key);
	if (it != _values.begin())
		it--;

	return it->second;
}

//PUBLIC//

void	BitcoinExchange::exchange(const std::string& line)
{
	std::string	date;
	float		amount;
	float		value;

	size_t	separator = line.find('|');
	if (separator == std::string::npos)
		throw BitcoinExchange::BadInputException(line);
	
	try
	{
		date = line.substr(0, separator - 1);
		validateDate(date, line);
		amount = parseValue(line, separator + 1);
		validateAmount(amount);
		value = amount * getBtcPrice(date);
		std::cout << date << " => " << amount << " = " << value << std::endl;
	}
	catch(const std::exception& e)
	{
		(void)e;
		throw;
	}
	
}



////////////////////////////////////////////////////////////////////////////////
////																		////
////								EXCEPTIONS								////
////																		////
////////////////////////////////////////////////////////////////////////////////

const char*	BitcoinExchange::DataFileOpeningException::what(void) const throw()
{
	return ("Failed opening data file");
}

const char*	BitcoinExchange::InvalidDataException::what(void) const throw()
{
	return ("Datafile has the wrong format");
}

const char*	BitcoinExchange::ConversionFailedException::what(void) const throw()
{
	return ("Failed conversion to float value");
}

BitcoinExchange::BadInputException::BadInputException(const std::string& error)
{
	_message = "Error: bad input => " + error;
}

BitcoinExchange::BadInputException::~BadInputException() throw()
{

}

const char*	BitcoinExchange::BadInputException::what() const throw()
{
	return _message.c_str();
}

const char*	BitcoinExchange::NegativeNumberException::what(void) const throw()
{
	return ("Error: not a positive number");
}

const char*	BitcoinExchange::LargeNumberException::what(void) const throw()
{
	return ("Error: too large a number");
}
