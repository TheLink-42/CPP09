/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimmy <jimmy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 00:01:55 by jimmy             #+#    #+#             */
/*   Updated: 2025/03/26 02:43:05 by jimmy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <deque>
# include <string>
# include <iostream>
# include <limits>
# include <cmath>
# include <algorithm>
# include <utility>

# define INT_MAX std::numeric_limits<int>::max()

template <bool Condition>
struct STATIC_ASSERTION;

template <>
struct STATIC_ASSERTION<true> {};

#define STATIC_ASSERT(condition) \
    typedef STATIC_ASSERTION<(bool)(condition)> STATIC_ASSERT_FAILED_##__LINE__


template <typename Container>
class PmergeMe {
	private:
		Container	container;

		STATIC_ASSERT(sizeof(typename Container::value_type) == sizeof(int));
		
		typename Container::iterator binaryInsert(Container& sorted, typename Container::iterator upperBound, int value);
   		Container generateJacobsthalSequence(int n);

	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);

		int		size() const;
		void	add(const std::string& str);
		void	add(int element);
		void	sort();
		void	displayContainer() const;
};

template <typename Container, typename NewType>
struct	ContainerTraits;

template <typename T, typename Alloc, typename NewType>
struct ContainerTraits<std::vector<T, Alloc>, NewType> {
    typedef std::vector<NewType> type;
};

template <typename T, typename Alloc, typename NewType>
struct ContainerTraits<std::deque<T, Alloc>, NewType> {
    typedef std::deque<NewType> type;
};

# include "PmergeMe.tpp"

#endif