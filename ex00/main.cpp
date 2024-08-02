/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isouaidi <isouaidi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 15:19:27 by isouaidi          #+#    #+#             */
/*   Updated: 2024/07/31 19:02:36 by isouaidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	BitcoinExchange btc;
	if(ac == 2)
	{
		std::string input(av[1]);
		if (input == "input.txt")
			btc.AddData();
		else
			std::cout << "Error: btc take \"input.txt\"" << std::endl;
	}
	else
		std::cout << "Error: btc take \"input.txt\"" << std::endl;
}