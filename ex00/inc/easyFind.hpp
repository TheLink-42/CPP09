/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyFind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbaeza-c <jbaeza-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 11:54:03 by jimmy             #+#    #+#             */
/*   Updated: 2025/03/13 13:37:18 by jbaeza-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <exception>

class	NotFoundException: public std::exception
{
	public:
		virtual const char* what() const throw()
		{
			return ("Not found");
		}
};	

template <typename Container>
typename Container::iterator easyFind(Container& container, int value);

# include "easyFind.tpp"

#endif