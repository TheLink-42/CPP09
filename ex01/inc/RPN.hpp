/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimmy <jimmy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 17:38:52 by jimmy             #+#    #+#             */
/*   Updated: 2025/03/16 14:24:15 by jimmy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <stack>
# include <string>
# include <limits>

# define MAX_INT std::numeric_limits<int>::max()
# define MIN_INT std::numeric_limits<int>::min()

class RPN {
	private:
		std::stack<int>	_values;

		void		pushValue(int value);
		int			pullValue();
		void		operation(int operation);
		size_t		size() const;

	public:
		RPN();
		~RPN();
		RPN(const RPN& other);
		RPN& operator=(const RPN& other);

		int	algorithm(const std::string& mathExpression);

		class InvalidInputException : public std::exception{
			public:
				virtual const char *what() const throw();
		};
		class OverflowOperationException : public std::exception{
			public:
				virtual const char *what() const throw();
		};
		class InvalidDivisionException : public std::exception{
			public:
				virtual const char *what() const throw();
		};
		class EmptyStackException : public std::exception{
			public:
				virtual const char *what() const throw();
		};
		class NonPolishNotationException : public std::exception{
			public:
				virtual const char *what() const throw();
		};
};

#endif