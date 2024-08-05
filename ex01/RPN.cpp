/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isouaidi <isouaidi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 15:14:43 by isouaidi          #+#    #+#             */
/*   Updated: 2024/08/05 15:14:46 by isouaidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {};

RPN::RPN(const RPN &instance)
{
    *this = instance;
};

RPN &RPN::operator=(const RPN &instance)
{
    this->stack = instance.stack;
    return (*this);
}

RPN::~RPN() {};

void RPN::CheckNumber(char *av)
{
    std::string nbs(av);
    for (size_t i = 0; i < nbs.size(); i++)
    {
        if ((!(isdigit(nbs[i]))) && nbs[i] != '*' && nbs[i] != '/' && nbs[i] != '+' && nbs[i] != '-' && nbs[i] != ' ')
        {
            std::cout << "Error : RPN take only int and opearator" << std::endl;
            return;
        }
    }
    calcul(nbs);
}

void RPN::calcul(std::string av)
{

    std::string token;
    std::istringstream iss(av);

    while (iss >> token)
    {

        if (isdigit(token[0]) || (token.size() > 1 && token[0] == '-'))
        {
            long tok;
            std::istringstream to(token);
            to >> tok;
            stack.push((tok));
        }
        else if (token.size() == 1 && (token[0] == '-' || token[0] == '+' || token[0] == '*' || token[0] == '/'))
        {
            if (stack.size() < 2)
            {
                std::cout << "Error: Missing operand" << std::endl;
                return;
            }

            long operand2 = stack.top();
            stack.pop();
            long operand1 = stack.top();
            stack.pop();

            if (token == "+")
                stack.push(operand1 + operand2);
            else if (token == "-")
                stack.push(operand1 - operand2);
            else if (token == "*")
                stack.push(operand1 * operand2);
            else if (token == "/")
            {
                if (operand2 == 0)
                {
                    std::cout << "Errorr: /0 not authorized" << std::endl;
                    return;
                }
                stack.push(operand1 / operand2);
            }


        }
    }

    if (stack.size() == 1 && stack.top() < INT_MAX && stack.top() > INT_MIN)
    {
        std::cout << stack.top() << std::endl;
    }
    else
        std::cout << "Erreur RPN" << std::endl;
}
