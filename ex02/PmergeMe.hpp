/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isouaidi <isouaidi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 15:22:54 by isouaidi          #+#    #+#             */
/*   Updated: 2024/08/06 14:09:44 by isouaidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <cctype> 
#include <limits.h> 
#include <fstream>
#include <utility>
#include <deque>
#include <algorithm>
#include <ctime>
#include <iomanip>


class PmergeMe{
	private :
		int impair_v;
		
		std::vector<int> init;
		std::vector<int> max;
		std::vector<int> maxTrie;
		std::vector<int> min;
		std::vector<std::pair<int, int> > pairs;

		int impair_d;
		
		std::deque<int> init_d;
		std::deque<int> max_d;
		std::deque<int> maxTrie_d;
		std::deque<int> min_d;
		std::deque<std::pair<int, int> > pairs_d;

	public :
		PmergeMe();
		PmergeMe(const PmergeMe &instance);
		PmergeMe& operator=(const PmergeMe &instance); 
		~PmergeMe();
		
		void CheckNumbers(char **av);

		
		int AddVector(std::string list);
		void AddPairs();
		void RecursivePush(size_t i);
		void RecursiveMax();
		void InsertionSort();

		int AddVector_d(std::string list);
		void AddPairs_d();
		void RecursivePush_d(size_t i);
		void RecursiveMax_d();
		void InsertionSort_d();
		
};