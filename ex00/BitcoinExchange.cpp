/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isouaidi <isouaidi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 14:10:17 by isouaidi          #+#    #+#             */
/*   Updated: 2024/08/05 19:14:03 by isouaidi         ###   ########.fr       */
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
		{	if (line.size() > 11 && line[10] == ','){
			std::string date = line.substr(0,10);
			std::string int_string = line.substr(11,line.size());
			for (size_t i = 0; i < int_string.size(); i++)
			{
				if (!((int_string[i] >= '0' && int_string[i] <= '9') || int_string[i] == '.') || int_string[0] == '.')
				{
					std::cout<< "Error : Multiplier take only Float or Int";
					std::cout<< line << std::endl;
					return;
				}
			}
			float num;
			std::istringstream iss(int_string);
			iss >> num;

			this->data[date] = num;	
		}
		else{
			std::cout<< "Error : Format data.csv \"YYYY-MM-DD,Multiplier\"\n";
			return;
		}
		}
	}
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
	
		if (year_n < 2009 || year_n > 9998)
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
	{
		std::cout << "Error: the are not \"date | value \" in first line on input" << std::endl;
		return;
	}
	while (std::getline(file, line))
	{
		if (line != "date | value"){
			
		
		// *************Check Char*******************
		if ((line[4] != '-' || line[7] != '-' || line[10] != ' '
			|| line[11] != '|' || line [12] != ' ' ) ){
				std::cout << "Error : Wrong character |";
				std::cout << line << "|" << std::endl;
				continue;
			}
	
		for (int i = 0; i < 4; i++){
			if (!(line[i] >= '0' && line[i] <= '9') ){
				std::cout << "Error : Wrong character |";
				std::cout << line << "|" << std::endl;
				continue;
			}
		}
		
		for (int i = 5; i < 7; i++){
			if (!(line[i] >= '0' && line[i] <= '9') ){
				std::cout << "Error : Wrong character |";
				std::cout << line << "|" << std::endl;
				continue;
			}	
		}

		for (int i = 8; i < 10; i++){
			if (!(line[i] >= '0' && line[i] <= '9') ){
				std::cout << "Error : Wrong character |";
				std::cout << line << "|" << std::endl;
				continue;
			}
		}
		
		for (size_t i = 13; i < line.size(); i++){
			if ((i == 13 || i == line.size()-1 ) && line[i] == '.' ){
				std::cout << "Error : Wrong character |";
				std::cout << line << "|" << std::endl;
				continue;
			}
			if (!((line[i] >= '0' && line[i] <= '9' ) || line[i] == '.' ) ){
				if ((i == 13 && line[i] == '-')){
					std::cout << "Error : Only positif numbers | ";
				}
				else 
					std::cout << "Error : Wrong character |";
				std::cout << line << " |" << std::endl;
				continue;
			}
		}

		if (line.size() == 13 ){
			std::cout << "Error : Enter the multiplier | ";
			std::cout << line << "|" << std::endl;
			continue;
		}
		if (line.size() > 13 ){
			std::string year = line.substr(0,4);
			std::string month = line.substr(5,2);
			std::string day = line.substr(8,2);
			std::string mul = line.substr(13, line.size() - 13);


			float mul_n;
			std::istringstream mull(mul);
			mull>>mul_n;

			if ((mul_n < 0 || mul_n > 1000) )
			{
				std::cout << "Error : Input Multiplier between 0 and 1000\n";
				continue;
			}
			
			int year_n;
			std::istringstream iss(year);
			iss >> year_n;

			int month_n;
			std::istringstream mss(month);
			mss >> month_n;
		
			int day_n;
			std::istringstream dss(day);
			dss >> day_n;
			if ((year_n < 2009 || year_n > 9998))
			{
				std::cout << "Error : Bad year |";
				std::cout << line << "|" << std::endl;
				continue;
			}

			else if ((month_n < 1 || month_n > 12) )
			{
				std::cout << "Error : Bad Month |";
				std::cout << line << "|" << std::endl;
				continue;
			}

			if (month == "02"){
				if ((day_n < 1 || day_n > 28) ){	
				std::cout << "Error : Bad Day |";
				std::cout << line << "|" << std::endl;
				continue;
				}
			}
			
			else if (month == "04" || month == "06" || month == "09" || month == "11"){
				if ((day_n < 1 || day_n > 30) ){	
				std::cout << "Error : Bad Day |";
				std::cout << line << "|" << std::endl;
				continue;
				}
			} 

			else{
				if ((day_n < 1 || day_n > 31) ){	
				std::cout << "Error : Bad Day |";
				std::cout << line << "|" << std::endl;
				continue;
				}
			}
			
		}
		else{
			std::cout<< "Error : Format input.txt \"YYYY-MM-DD | Multiplier\"\n";
			continue;
		}
		PrintResult(line);
		}
	}
}

void BitcoinExchange::PrintResult(std::string line){
	
		std::string mul = line.substr(13, line.size() - 13);


		float mul_n;
		std::istringstream mull(mul);
		mull>>mul_n;

		std::string date = line.substr(0, 10);

		std::map<std::string, float>::iterator it = data.upper_bound(date);
		
		if (it == data.begin()){
			std::cout << "Error : Date min 2009-01-02\n";
			return;
		}
		it --;
		std::cout << it->first  << " => "<< mul_n  << " => "  << it->second * mul_n << std::endl;
}
