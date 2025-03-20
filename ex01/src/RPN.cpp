/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimmy <jimmy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 17:38:50 by jimmy             #+#    #+#             */
/*   Updated: 2025/03/20 10:26:04 by jimmy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

////////////////////////////////////////////////////////////////////////////////
////																		////
////							CONSTRUCTORS								////
////																		////
////////////////////////////////////////////////////////////////////////////////

RPN::RPN(){
//	std::cout << "RPN default constructor called" << std::endl;

}

RPN::~RPN(){
//	std::cout << "RPN destructor called" << std::endl;

}

RPN::RPN(const RPN& other){
//	std::cout << "RPN copy constructor called" << std::endl;
	_values = other._values;
}

RPN&	RPN::operator=(const RPN& other){
//	std::cout << "RPN copy assignment operator called" << std::endl;
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

bool	isOperator(int c)
{
	return (c == '+' || c == '-' || c == '*' || c == '/');
}



//PRIVATE//

void	RPN::pushValue(int value)
{
	_values.push(value);
}

int		RPN::pullValue()
{
	int	value = _values.top();
	_values.pop();

	return value;
}

size_t	RPN::size() const
{
	return _values.size();
}

void	RPN::operation(int operation)
{
	if (size() < 2)
		throw RPN::EmptyStackException();
	
	int	secondValue = pullValue();
	int	firstValue = pullValue();
	long	value;
	switch(operation)
	{
		case '+':
			value = static_cast<long>(firstValue) + secondValue;
			break;

		case '-':
			value = static_cast<long>(firstValue) - secondValue;
			break;
		
		case '*':
			value = static_cast<long>(firstValue) * secondValue;
			break;

		case '/':
			if (secondValue == 0)
				throw RPN::InvalidDivisionException();
			value = static_cast<long>(firstValue) / secondValue;
			break;
		default:
			throw RPN::InvalidInputException();
	}
	if (value < MIN_INT || value > MAX_INT)
		throw RPN::OverflowOperationException();
	pushValue(static_cast<int>(value));
}

//PUBLIC//

int	RPN::algorithm(const std::string& mathExpression)
{
	size_t	len = mathExpression.size();

	for(size_t i = 0; i < len; i++)
	{
		if (isspace(mathExpression[i]))
			continue;
		else if (isdigit(mathExpression[i]))
			pushValue(mathExpression[i] - '0');
		else if (isOperator(mathExpression[i]))
			operation(mathExpression[i]);
		else
			throw RPN::InvalidInputException();
	}
	if (size() > 1)
		throw RPN::NonPolishNotationException();
	return (pullValue());
}


////////////////////////////////////////////////////////////////////////////////
////																		////
////								EXCEPTIONS								////
////																		////
////////////////////////////////////////////////////////////////////////////////

const char*	RPN::InvalidInputException::what(void) const throw()
{
	return ("Error: mathematical expression contains invalid characters");
}

const char*	RPN::OverflowOperationException::what(void) const throw()
{
	return ("Error: one of the operations overflowed int limits");
}

const char*	RPN::InvalidDivisionException::what(void) const throw()
{
	return ("Error: tried to divide by 0");
}

const char*	RPN::EmptyStackException::what(void) const throw()
{
	return ("Error: tried to execute operations without enough numbers");
}

const char*	RPN::NonPolishNotationException::what(void) const throw()
{
	return ("Error: mathematical expression is not in reversed polish notation");
}