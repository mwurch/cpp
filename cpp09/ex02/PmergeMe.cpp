#include "PmergeMe.hpp"


PmergeMe::PmergeMe() {}
PmergeMe::~PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe&) {}
PmergeMe& PmergeMe::operator=(const PmergeMe&) {return *this;}

bool    PmergeMe::parseInput(char **argv, int argc)
{
	if (argc <= 2)
	{
		std::cerr << "Error: Not enough input provided" << std::endl;
		return false;
	}
	std::set<int> seenNumbers;
	int number;
	for (int index = 1; index <= argc - 1; index++)
	{
		std::istringstream ss(argv[index]);
		if (!(ss>>number) || ss.peek() != EOF || number < 0)
		{
			std::cerr << "Error: invalid input[" << argv[index] << "]" << std::endl;
			return false;
		}
		if (seenNumbers.find(number) != seenNumbers.end())
		{
			std::cerr << "Error: dublicate number[" << argv[index] << "]" << std::endl;
			return false;
		}
		_numbers.push_back(number);
		seenNumbers.insert(number);
	}
	return true;
}

void	PmergeMe::sortVec()
{
	int rest = -1, elementCount = _numbers.size();

	if ( elementCount % 2 != 0)
		rest = _numbers[elementCount-1];
	//create pairs of numbers
	std::vector< std::vector<int> >pairs;
	for (int i = 0; i < elementCount; i += 2)
	{
		if (i + 1 < elementCount)
		{
			std::vector<int>pair;
			pair.push_back(_numbers[i]);
			pair.push_back(_numbers[i + 1]);
			pairs.push_back(pair);
		}
	}
	//sort pairs by first value >> pair[first][second]
	for(std::vector<std::vector<int> >::iterator it = pairs.begin(); it != pairs.end(); it++)
	{
		if ((*it)[0] > (*it)[1])
			std::swap((*it)[0], (*it)[1]);
	}

	mergeSort(pairs, 0, pairs.size() - 1);
	insert(pairs,_sortedVec); // potential error
	//insert last value in case of odd amount of numbers
	if (rest != -1)
	{
		std::vector<int>::iterator it = std::lower_bound(_sortedVec.begin(), _sortedVec.end(), rest);
		_sortedVec.insert(it, rest);
	}
}

void	PmergeMe::sortDeq()
{
		int rest = -1, elementCount = _numbers.size();

	if ( elementCount % 2 != 0)
		rest = _numbers[elementCount-1];
	//create pairs of numbers
	std::deque<std::deque<int> >pairs;
	for (int i = 0; i < elementCount; i += 2)
	{
		if (i + 1 < elementCount)
		{
			std::deque<int>pair;
			pair.push_back(_numbers[i]);
			pair.push_back(_numbers[i + 1]);
			pairs.push_back(pair);
		}
	}
	//sort pairs by first value >> pair[first][second]
	for(std::deque<std::deque<int> >::iterator it = pairs.begin(); it != pairs.end(); it++)
	{
		if ((*it)[0] > (*it)[1])
			std::swap((*it)[0], (*it)[1]);
	}

	mergeSort(pairs, 0, pairs.size() - 1);
	insert(pairs,_sortedDeq); // potential error
	//insert last value in case of odd amount of numbers
	if (rest != -1)
	{
		std::deque<int>::iterator it = std::lower_bound(_sortedDeq.begin(), _sortedDeq.end(), rest);
		_sortedDeq.insert(it, rest);
	}
}

void	PmergeMe::sort(char **argv, int argc)
{
	if (!parseInput(argv, argc)) {return ;}
	
		struct timeval start, end;
		gettimeofday(&start, NULL);
		sortVec();
		gettimeofday(&end, NULL);
		_vecTime = (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec);

		gettimeofday(&start, NULL);
		sortDeq();
		gettimeofday(&end, NULL);
		_deqTime = (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec);
	//printing results
	printResult();
}

template<typename Pairs>
void	PmergeMe::mergeSort(Pairs& pairs, int l, int r)
{
	if (l >= r)
		return;
	int mid = l + (r - l) /2;
	mergeSort(pairs, l, mid);
	mergeSort(pairs, mid+1, r);
	merge(pairs, l, mid, r);
}

template<typename Pairs>
void	PmergeMe::merge(Pairs& pairs, int l, int m, int r)
{
	//creating tmp Container for left and right side and fill them with the numbers
	int rSize = r-m, lSize = m - l + 1;
	Pairs left(lSize);
	Pairs right(rSize);

	for (int i = 0; i < lSize; ++i)
		left[i] = pairs[l + i];
	for (int i = 0; i < rSize; ++i)
		right[i] = pairs[m + 1 + i];

	int i = 0, j = 0, pos = l;

	//sort pairs [3,4] [812, 5323] [1, 4432] >> [1, 4432] [3,4] [812, 5323]
	while (i < lSize && j < rSize)
	{
		if (left[i][0] <= right[j][0])
		{
			pairs[pos] = left[i];
			i++;
		}else {
			pairs[pos] = right[j];
			j++;
		}
		pos++;
	}
	while (i < lSize)
	{
		pairs[pos] = left[i];
		i++;
		pos++;
	}
	while (j < rSize)
	{
		pairs[pos] = right[j];
		j++;
		pos++;
	}
}

template<typename Container, typename Pairs>
void PmergeMe::insert(const Pairs& pairs, Container& sortedVec)
{
	for (typename Pairs::const_iterator it = pairs.begin(); it != pairs.end(); ++it)
	{
		sortedVec.push_back((*it)[0]);
	}

	for (typename Pairs::const_iterator it = pairs.begin(); it != pairs.end(); ++it)
	{
		if ((*it).size() > 1) {
			typename Container::iterator insertIt = std::lower_bound(sortedVec.begin(), sortedVec.end(), (*it)[1]);
			sortedVec.insert(insertIt, (*it)[1]);
		}
	}
}

void	PmergeMe::printResult()
{
	int elementCount = _numbers.size();
	std::cout << "Befor: ";
	for (std::vector<int>::iterator it = _numbers.begin(); it != _numbers.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	std::cout << "After:   ";
	for (std::vector<int>::iterator it = _sortedVec.begin(); it != _sortedVec.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	std::cout << "Time to process a range of " << elementCount << " elements with std::vector<int> : " << _vecTime << " us" << std::endl;
	std::cout << "Time to process a range of " << elementCount << " elements with std::deque<int> : " << _deqTime << " us" << std::endl;
}