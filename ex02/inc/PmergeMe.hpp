/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimmy <jimmy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 23:50:28 by jimmy             #+#    #+#             */
/*   Updated: 2025/03/20 11:17:53 by jimmy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <list>
# include <vector>
# include <string>
# include <cmath>
# include <limits>

# define INT_MAX std::numeric_limits<int>::max()

class PmergeMe {
	private:
		std::list<int>		_listContainer;
		std::vector<int>	_vectorContainer;



	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);

		void	loadContainers(std::string value);
		void	displaySequence() const;
		void	displayTimes() const;
		void	sortList();
		void	sortVector();

		class InvalidInputException : public std::exception{
			public:
				virtual const char *what() const throw();
		};

};

#endif