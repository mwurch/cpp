#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <set>
#include <sstream>
#include <cstdio>
#include <sys/time.h>

class PmergeMe
{
	private:
		std::vector<int>							_sortedVec;
		std::vector<int>							_numbers;
		std::deque<int>								_sortedDeq;
		double												_vecTime;
		double												_deqTime;

		bool	parseInput(char **argv, int argc);
		void	sortVec();
		void	sortDeq();
		template<typename Pairs>
		void	mergeSort(Pairs& pairs, int l, int r);
		template<typename Pairs>
		void 	merge(Pairs& pairs, int l, int m, int r);
		template<typename Container, typename Pairs>
		void insert(const Pairs& pairs, Container& sortedVec);
		PmergeMe&	operator=(const PmergeMe&);
		PmergeMe(const PmergeMe&);
		void	printResult();

	public:
		PmergeMe();
		~PmergeMe();
		void	sort(char** argv, int argc);
};