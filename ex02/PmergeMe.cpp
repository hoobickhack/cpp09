/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isouaidi <isouaidi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 15:43:48 by isouaidi          #+#    #+#             */
/*   Updated: 2024/08/05 19:16:16 by isouaidi         ###   ########.fr       */
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
	if (AddVector(list) == 1)
		return;
	
	std::cout << "Before : ";
	for (size_t i = 0; i < init.size(); i++){
		std::cout << init[i] << " ";
	}
	std::cout << std::endl;
	
	AddPairs();
	RecursivePush(0);
	InsertionSort();
	
	std::cout << "After : ";
	for (size_t i = 0; i < max.size(); i++)
		std::cout << max[i] << " ";
	std::cout << std::endl;
}

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

void PmergeMe::InsertionSort() {
    for (size_t i = 0; i < min.size(); ++i) {
        std::vector<int>::iterator Position = std::lower_bound(max.begin(), max.end(), min[i]);
        max.insert(Position, min[i]);
    }
	if (impair_v){
	    std::vector<int>::iterator Position = std::lower_bound(max.begin(), max.end(), impair_v);
        max.insert(Position, impair_v);
	}
}