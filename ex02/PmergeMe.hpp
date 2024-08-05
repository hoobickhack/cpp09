/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isouaidi <isouaidi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 15:22:54 by isouaidi          #+#    #+#             */
/*   Updated: 2024/08/05 18:51:46 by isouaidi         ###   ########.fr       */
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


class PmergeMe{
	private :
		int impair_v;
		
		std::vector<int> init;
		std::vector<int> max;
		std::vector<int> min;
		std::vector<std::pair<int, int> > pairs;

	public :
		PmergeMe();
		PmergeMe(const PmergeMe &instance);
		PmergeMe& operator=(const PmergeMe &instance); 
		~PmergeMe();
		
		void CheckNumbers(char **av);
		int AddVector(std::string list);
		void AddPairs();
		void RecursivePush(size_t i);
		void InsertionSort();
		
};