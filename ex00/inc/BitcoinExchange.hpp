/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimmy <jimmy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 13:10:11 by jbaeza-c          #+#    #+#             */
/*   Updated: 2025/03/15 02:09:49 by jimmy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <string>
# include <fstream>
# include <exception>
# include <cmath>
# include <limits>
# include <iomanip>
# include <iostream>



class BitcoinExchange
{
	private:
		std::map<std::string, float>	_values;

		void	loadData(const std::string& fileName);
		float	getBtcPrice(std::string& key) const;

	public:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);

		void	exchange(const std::string& data);

		class DataFileOpeningException : public std::exception{
			public:
				virtual const char *what() const throw();
		};
		class InvalidDataException : public std::exception{
			public:
				virtual const char *what() const throw();
		};
		class ConversionFailedException : public std::exception{
			public:
				virtual const char *what() const throw();
		};
		class BadInputException : public std::exception{
			private:
				std::string _message;
			public:
				explicit BadInputException(const std::string& error);
				virtual ~BadInputException() throw();
				virtual const char *what() const throw();
		};
		class NegativeNumberException : public std::exception{
			public:
				virtual const char *what() const throw();
		};
		class LargeNumberException : public std::exception{
			public:
				virtual const char *what() const throw();
		};
};

#endif