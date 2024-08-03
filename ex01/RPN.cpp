#include "RPN.hpp"

RPN::RPN(){};

RPN::RPN(const RPN &instance){
    *this = instance;
};

RPN& RPN::operator=(const RPN &instance){
    this->stack = instance.stack;
    return(*this);
}

RPN::~RPN(){};

void RPN::CheckNumber(char *av){
    std::string nbs(av);
    for (size_t i = 0; i < nbs.size();i++){
        if((!(isdigit(nbs[i]))) && nbs[i] != '*' && nbs[i] != '/' && nbs[i] != '+' 
        && nbs[i] != '-' && nbs[i] != ' ' ){
            std::cout<< "Error : RPN take only int and opearator" << std::endl;
            return;
        }
        calcul(nbs);
    }
}

void RPN::calcul(std::string av){

    std::string token;
    std::istringstream iss(av);

    while (iss >> token) {
        if (isdigit(token[0]) || (token.size() > 1 && token[0] == '-')) {
            int tok;
			std::istringstream to(token);
			to>>tok;
            std::cout << "test " << tok << std::endl ;
            stack.push((tok));
        } else {
            // Token is an operator
            int operand2 = stack.top();
            stack.pop();
            int operand1 = stack.top();
            stack.pop();
            
            if (token == "+") stack.push(operand1 + operand2);
            else if (token == "-") stack.push(operand1 - operand2);
            else if (token == "*") stack.push(operand1 * operand2);
            else if (token == "/") stack.push(operand1 / operand2);
        }
    }

         std::cout << stack.top();
}