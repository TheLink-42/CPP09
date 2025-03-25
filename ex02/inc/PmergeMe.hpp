/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimmy <jimmy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 23:50:28 by jimmy             #+#    #+#             */
/*   Updated: 2025/03/24 22:08:17 by jimmy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <list>
# include <vector>
# include <string>
# include <cmath>
# include <limits>
# include <utility>
# include <sys/time.h>

# define INT_MAX std::numeric_limits<int>::max()

void	loadContainers(const std::string& str, std::vector<int>& vectorData, std::list<int>& listData);
void	sortVector(std::vector<int>& vectorData);
void	sortList(std::list<int>& listData);

#endif