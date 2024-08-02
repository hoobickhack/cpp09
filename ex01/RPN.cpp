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
        if(!(isdigit(nbs[i])) || nbs[i] == '*' || nbs[i] == '/' || nbs[i] == '+' 
        || nbs[i] == '-' || nbs[i] == ' ' )
            std::cout<< "no";
    }
}