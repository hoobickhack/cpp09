/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isouaidi <isouaidi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 14:10:17 by isouaidi          #+#    #+#             */
/*   Updated: 2024/07/31 20:38:12 by isouaidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>

BitcoinExchange::BitcoinExchange(){}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &instance){
	*this = instance; 
}
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &instance){
	this->data = instance.data;
	return(*this);
}
BitcoinExchange::~BitcoinExchange(){}

void BitcoinExchange::AddData(){
	std::ifstream file("data.csv");

	if (!file){
		std::cout << "Error, Open to file" << std::endl;
		return ;
	}
	
	std::string line;
	while (std::getline(file, line))
	{
		if (line != "date,exchange_rate")
		{
			std::string date = line.substr(0,10);
			std::string int_string = line.substr(11,line.size());
			float num;
			std::istringstream iss(int_string);
			iss >> num;
			this->data[date] = num;	
		}
	}
	// std::map<std::string,float>::iterator it = data.begin();
	
	// for (; it != data.end(); ++it)
	// {
	// 	 std::cout << it->first << " => " << it->second << std::endl;
	// }
	CheckData();
	CheckInput();
}

void	BitcoinExchange::CheckData(){
	std::map<std::string,float>::iterator it = data.begin();
	
	for (; it != data.end(); ++it)
	{
		std::string line = it->first;
		std::string year = line.substr(0,4);
		std::string month = line.substr(5,2);
		std::string day = line.substr(8,2);
		
		int year_n;
		std::istringstream iss(year);
		iss >> year_n;
		
		int month_n;
		std::istringstream mss(month);
		mss >> month_n;

		int day_n;
		std::istringstream dss(day);
		dss >> day_n;

		// *************Check Char*******************
		
		if (line[4] != '-' || line[7] != '-'){
				std::cout << "Error : Wrong character |";
				std::cout << it->first << " => " << it->second << "|" << std::endl;
				return;
			}
	
		for (int i = 0; i < 4; i++){
			if (!(line[i] >= '0' && line[i] <= '9')){
				std::cout << "Error : Wrong character |";
				std::cout << it->first << " => " << it->second << "|" << std::endl;
				return;
			}
		}
		
		for (int i = 5; i < 7; i++){
			if (!(line[i] >= '0' && line[i] <= '9')){
				std::cout << "Error : Wrong character |";
				std::cout << it->first << " => " << it->second << "|" << std::endl;
				return;
			}	
		}

		for (int i = 8; i < 10; i++){
			if (!(line[i] >= '0' && line[i] <= '9')){
				std::cout << "Error : Wrong character |";
				std::cout << it->first << " => " << it->second << "|" << std::endl;
				return;
			}	
		}

		
		
		//************Check Numbers****************
	
		if (year_n < 2009 || year_n > 9999)
		{
			std::cout << "Error : Bad year |";
			std::cout << it->first << " => " << it->second << "|" << std::endl;
			return;
		}

		else if (month_n < 1 || month_n > 12)
		{
			std::cout << "Error : Bad Month |";
			std::cout << it->first << " => " << it->second << "|" << std::endl;
			return;
		}

		if (month == "02"){
			if (day_n < 1 || day_n > 28){	
			std::cout << "Error : Bad Day |";
			std::cout << it->first << " => " << it->second << "|" << std::endl;
			return;
			}
		}
		
		else if (month == "04" || month == "06" || month == "09" || month == "11"){
			if (day_n < 1 || day_n > 30){	
			std::cout << "Error : Bad Day |";
			std::cout << it->first << " => " << it->second << "|" << std::endl;
			return;
			}
		} 

		else{
			if (day_n < 1 || day_n > 31){	
			std::cout << "Error : Bad Day |";
			std::cout << it->first << " => " << it->second << "|" << std::endl;
			return;
			}
		}
		
	}
}

void BitcoinExchange::CheckInput(){
	
	std::ifstream file("input.txt");

	if (!file){
		std::cout << "Error, Open to file" << std::endl;
		return ;
	}
	

	std::string line;
	std::getline(file, line); 
	if (line != "date | value")
	std::cout << "ok";
	while (std::getline(file, line))
	{
		if (line != "date | value"){
			
		// std::string line = line;
		std::string year = line.substr(0,4);
		std::string month = line.substr(5,2);
		std::string day = line.substr(8,2);
		
		int year_n;
		std::istringstream iss(year);
		iss >> year_n;
		
		int month_n;
		std::istringstream mss(month);
		mss >> month_n;

		int day_n;
		std::istringstream dss(day);
		dss >> day_n;

		// *************Check Char*******************
		
		if (line[4] != '-' || line[7] != '-' || line[10] != ' '
			|| line[11] != '|' || line [12] != ' ' ){
				std::cout << "Error : Wrong character |";
				std::cout << line << "|" << std::endl;
				// return;
			}
	
		for (int i = 0; i < 4; i++){
			if (!(line[i] >= '0' && line[i] <= '9')){
				std::cout << "Error : Wrong character |";
				std::cout << line << "|" << std::endl;
				// return;
			}
		}
		
		for (int i = 5; i < 7; i++){
			if (!(line[i] >= '0' && line[i] <= '9')){
				std::cout << "Error : Wrong character |";
				std::cout << line << "|" << std::endl;
				// return;
			}	
		}

		for (int i = 8; i < 10; i++){
			if (!(line[i] >= '0' && line[i] <= '9')){
				std::cout << "Error : Wrong character |";
				std::cout << line << "|" << std::endl;
				// return;
			}	
		}

		
		
		//************Check Numbers****************
	
		if (year_n < 2009 || year_n > 9999)
		{
			std::cout << "Error : Bad year |";
			std::cout << line << "|" << std::endl;
			// return;
		}

		else if (month_n < 1 || month_n > 12)
		{
			std::cout << "Error : Bad Month |";
			std::cout << line << "|" << std::endl;
			// return;
		}

		if (month == "02"){
			if (day_n < 1 || day_n > 28){	
			std::cout << "Error : Bad Day |";
			std::cout << line << "|" << std::endl;
			// return;
			}
		}
		
		else if (month == "04" || month == "06" || month == "09" || month == "11"){
			if (day_n < 1 || day_n > 30){	
			std::cout << "Error : Bad Day |";
			std::cout << line << "|" << std::endl;
			// return;
			}
		} 

		else{
			if (day_n < 1 || day_n > 31){	
			std::cout << "Error : Bad Day |";
			std::cout << line << "|" << std::endl;
			// return;
			}
		}
		
		}
	}
}
