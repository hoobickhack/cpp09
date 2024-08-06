/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isouaidi <isouaidi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 15:43:48 by isouaidi          #+#    #+#             */
/*   Updated: 2024/08/06 14:38:08 by isouaidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){}

PmergeMe::PmergeMe(const PmergeMe &instance){
	*this = instance;
}

PmergeMe& PmergeMe::operator=(const PmergeMe &instance){
	this->init = instance.init;
	this->max = instance.max;
	this->min = instance.min;
	this->maxTrie = instance.maxTrie;
	this->pairs = instance.pairs;
	this->impair_v = instance.impair_v;

	this->init_d = instance.init_d;
	this->max_d = instance.max_d;
	this->min_d = instance.min_d;
	this->maxTrie_d = instance.maxTrie_d;
	this->pairs_d = instance.pairs_d;
	this->impair_d = instance.impair_d;
	return (*this);
}

PmergeMe::~PmergeMe(){}

void PmergeMe::CheckNumbers(char **av){
	std::string list(av[1]);

	for (int i = 2; av[i]; i++){
	std::string listAdd(av[i]);
	list = list + " " + listAdd;
	}
	
	for (size_t i = 0; i < list.size(); i++){
		if ((!(list[i] >= '0' && list[i] <= '9')) && list[i] != ' '){
			std::cerr << "Error: PmergeMe take only Numbers\n";
			return;
		}
	}

	//*************Vector*************	

	if (AddVector(list) == 1)
		return;
	
	std::cout << "Before : ";
	for (size_t i = 0; i < init.size(); i++){
		std::cout << init[i] << " ";
	}
	std::cout << std::endl;
	
	std::time_t startTime = std::clock();
	
	AddPairs();
	RecursivePush(0);
	RecursiveMax();
	InsertionSort();
	
	std::time_t endTime = std::clock();
	
	std::cout << "After : ";
	for (size_t i = 0; i < maxTrie.size(); ++i)
		std::cout << maxTrie[i] << " ";
	std::cout << std::endl << std::endl;

    
    float Time = float(endTime - startTime) / CLOCKS_PER_SEC * 1000.0;
    
    std::cout << "Time to process a range of " << init.size() <<" elements with std::vector :" << Time << " milliseconds" << std::endl;
	
	
	//**************Deque**************
	

	if (AddVector_d(list) == 1)
		return;
	
	// std::cout << "Before_d : ";
	// for (size_t i = 0; i < init_d.size(); i++){
	// 	std::cout << init_d[i] << " ";
	// }
	// std::cout << std::endl;
	
	std::time_t startTime_d = std::clock();

	AddPairs_d();
	RecursivePush_d(0);
	RecursiveMax_d();
	InsertionSort_d();

	std::time_t endTime_d = std::clock();

	// std::cout << "After_d : ";
	// for (size_t i = 0; i < maxTrie_d.size(); i++)
	// 	std::cout << maxTrie_d[i] << " ";
	// std::cout << std::endl;

	float Time_d = float(endTime_d - startTime_d) / CLOCKS_PER_SEC * 1000.0;
    
    std::cout << "Time to process a range of " << init_d.size() <<" elements with std::deque :" << Time_d << " milliseconds" << std::endl;
}


//*************Vector**************

int PmergeMe::AddVector(std::string list){
	std::string num_s;
	std::istringstream iss(list);

	while (iss >> num_s)
	{
		long num;
		std::istringstream (num_s) >> num;
		
		if (num > INT_MAX){
			std::cerr << "Error: Int_max\n";
			return 1;
		}

		init.push_back(num);
	}
	return 0;
}

void PmergeMe::AddPairs(){
	for (size_t i = 0; i + 1 < init.size(); i += 2) {
        pairs.push_back(std::make_pair(init[i], init[i + 1]));
    }
    
	if (init.size() % 2 != 0){
        impair_v = init.back();
	}
}

void PmergeMe::RecursivePush(size_t i){
	
	if (i >= pairs.size())
		return;
	if (pairs[i].first >= pairs[i].second){
		max.push_back(pairs[i].first);
		min.push_back(pairs[i].second);
	}
	else{
		min.push_back(pairs[i].first);
		max.push_back(pairs[i].second);
	}
	RecursivePush(i + 1);
}

void PmergeMe::RecursiveMax(){
	if (max.empty())
		return;
		
	int value = *std::min_element(max.begin(), max.end()); 
	
	max.erase(std::remove(max.begin(), max.end(), value),max.end());
	maxTrie.push_back(value);
	
	RecursiveMax();
}

void PmergeMe::InsertionSort() {
    for (size_t i = 0; i < min.size(); ++i) {
        std::vector<int>::iterator Position = std::lower_bound(maxTrie.begin(), maxTrie.end(), min[i]);
        maxTrie.insert(Position, min[i]);
    }
	if (init.size () % 2 != 0){
	    std::vector<int>::iterator Position = std::lower_bound(maxTrie.begin(), maxTrie.end(), impair_v);
        maxTrie.insert(Position, impair_v);
	}
}

//***********Deque*************

int PmergeMe::AddVector_d(std::string list){
	std::string num_s;
	std::istringstream iss(list);

	while (iss >> num_s)
	{
		long num;
		std::istringstream (num_s) >> num;
		
		if (num > INT_MAX){
			std::cerr << "Error: Int_max\n";
			return 1;
		}

		init_d.push_back(num);
	}
	return 0;
}

void PmergeMe::AddPairs_d(){
	for (size_t i = 0; i + 1 < init_d.size(); i += 2) {
        pairs_d.push_back(std::make_pair(init_d[i], init_d[i + 1]));
    }
    
	if (init_d.size() % 2 != 0){
        impair_d = init_d.back();
	}
}

void PmergeMe::RecursivePush_d(size_t i){
	
	if (i >= pairs_d.size())
		return;
	if (pairs_d[i].first >= pairs_d[i].second){
		max_d.push_back(pairs_d[i].first);
		min_d.push_back(pairs_d[i].second);
	}
	else{
		min_d.push_back(pairs_d[i].first);
		max_d.push_back(pairs_d[i].second);
	}
	RecursivePush_d(i + 1);
}

void PmergeMe::RecursiveMax_d(){
	if (max_d.empty())
		return;
		
	int value = *std::min_element(max_d.begin(), max_d.end());
		
	max_d.erase(std::remove(max_d.begin(), max_d.end(), value),max_d.end());
	maxTrie_d.push_back(value);
	
	RecursiveMax_d();
}

void PmergeMe::InsertionSort_d() {
    for (size_t i = 0; i < min.size(); ++i) {
        std::deque<int>::iterator Position = std::lower_bound(maxTrie_d.begin(), maxTrie_d.end(), min[i]);
        maxTrie_d.insert(Position, min[i]);
    }
	if (init_d.size() % 2 != 0){
	    std::deque<int>::iterator Position = std::lower_bound(maxTrie_d.begin(), maxTrie_d.end(), impair_d);
        maxTrie_d.insert(Position, impair_d);
	}
}