/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimmy <jimmy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 00:15:01 by jimmy             #+#    #+#             */
/*   Updated: 2025/03/26 03:20:24 by jimmy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


////////////////////////////////////////////////////////////////////////////////
////																		////
////							CONSTRUCTORS								////
////																		////
////////////////////////////////////////////////////////////////////////////////

template <typename Container>
PmergeMe<Container>::PmergeMe(){
//	std::cout << "PmergeMe default constructor called" << std::endl;

}

template <typename Container>
PmergeMe<Container>::~PmergeMe(){
//	std::cout << "PmergeMe destructor called" << std::endl;

}

template <typename Container>
PmergeMe<Container>::PmergeMe(const PmergeMe& other) : container(other.container){
//	std::cout << "PmergeMe copy constructor called" << std::endl;

}

template <typename Container>
PmergeMe<Container>&	PmergeMe<Container>::operator=(const PmergeMe& other){
//	std::cout << "PmergeMe copy assignment operator called" << std::endl;
	if (this != &other)
		this->container = other.container;
	return *this;
}



////////////////////////////////////////////////////////////////////////////////
////																		////
////								OVERLOADS								////
////																		////
////////////////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////////////////
////																		////
////						PRIVATE MEMBER FUNCTIONS						////
////																		////
////////////////////////////////////////////////////////////////////////////////

template <typename Container>
Container PmergeMe<Container>::generateJacobsthalSequence(int n)
{
    Container jacobsthal;
    jacobsthal.push_back(1);
    jacobsthal.push_back(3);

    int index = 2;
    while (jacobsthal.back() < n) {
        jacobsthal.push_back(jacobsthal[index - 1] + 2 * jacobsthal[index - 2]);
        index++;
    }
    return jacobsthal;
}

template <typename Container>
typename Container::iterator PmergeMe<Container>::binaryInsert(Container& sorted, typename Container::iterator upperBound, int value)
{
    typename Container::iterator first = sorted.begin();
    typename Container::iterator last = upperBound;

    while (first != last) {
        typename Container::iterator mid = first;
        std::advance(mid, std::distance(first, last) / 2);
        if (*mid < value)
            first = ++mid;
        else
            last = mid;
    }
    return sorted.insert(first, value);
}



////////////////////////////////////////////////////////////////////////////////
////																		////
////						PUBLIC MEMBER FUNCTIONS							////
////																		////
////////////////////////////////////////////////////////////////////////////////

template <typename Container>
void	PmergeMe<Container>::displayContainer() const
{
	int	size = container.size();

	for (int i = 0; i < size; i++)
		std::cout << " " << container[i];
	std::cout << std::endl;
}

template <typename Container>
int	PmergeMe<Container>::size() const
{
	return container.size();
}

template <typename Container>
void	PmergeMe<Container>::add(int value)
{
	container.push_back(value);
}

template <typename Container>
void	PmergeMe<Container>::add(const std::string& str)
{
	size_t	size = str.size();
	for (size_t i = 0; i < size; i++)
		if (!isdigit(str[i]))
			throw std::exception();
	double	number = atol(str.c_str());

	if (number == HUGE_VAL || number == -HUGE_VAL || number < 0 || number > INT_MAX)
		throw std::exception();
	container.push_back(static_cast<int>(number));
}

template <typename Container>
void	PmergeMe<Container>::sort()
{
	typedef typename ContainerTraits<Container, std::pair<int, int> >::type PairContainer;
	typedef typename ContainerTraits<Container, bool>::type BoolContainer;

	int	size = container.size();
	if (size <= 1)
		return;
	
	int	numberOfPairs = size / 2;

	Container			winners;
    PairContainer		pairs;
	PmergeMe<Container>	newPmg;

	for (int i = 0; i < numberOfPairs; i++)
	{
		int first = container[i * 2];
		int second = container[i * 2 + 1];
		if (first < second)
			pairs.push_back(std::pair<int, int>(first, second));
		else
			pairs.push_back(std::pair<int, int>(second, first));
		newPmg.add(pairs.back().second);
	}
	if (size % 2)
		newPmg.add(container[size - 1]);
	
	newPmg.sort();
	winners = newPmg.container;

	Container 		jacobsthal = generateJacobsthalSequence(numberOfPairs);
	BoolContainer	inserted(numberOfPairs, false);
	int				jacobSize = jacobsthal.size();
	
	for (int i = 0; i < jacobSize; i++)
	{
		int index = jacobsthal[i] - 1;
		if (index >= numberOfPairs)
			break;
		int smaller = pairs[index].first;
		typename Container::iterator winnerIter = std::find(winners.begin(), winners.end(), pairs[index].second);
		binaryInsert(winners, winnerIter, smaller);
		inserted[index] = true;
	}
	for (int i = 0; i < numberOfPairs; i++)
	{
		if (!inserted[i]) {
			int smaller = pairs[i].first;
			typename Container::iterator winnerIter = std::find(winners.begin(), winners.end(), pairs[i].second);
			binaryInsert(winners, winnerIter, smaller);
		}
	}

	container = winners;
}

////////////////////////////////////////////////////////////////////////////////
////																		////
////								EXCEPTIONS								////
////																		////
////////////////////////////////////////////////////////////////////////////////