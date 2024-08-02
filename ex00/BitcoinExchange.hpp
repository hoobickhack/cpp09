/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isouaidi <isouaidi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 13:35:10 by isouaidi          #+#    #+#             */
/*   Updated: 2024/07/31 20:26:12 by isouaidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <iterator>
#include <algorithm>

class BitcoinExchange{
	private :
	std::map<std::string,float> data;
	
	public :
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &instance);
	BitcoinExchange& operator=(const BitcoinExchange &instance);
	~BitcoinExchange();

	void AddData();
	
	void CheckData();

	void CheckInput();
		
};