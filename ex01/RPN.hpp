#pragma once

#include <iostream>
#include <stack>
#include <sstream>
#include <string>
#include <cctype> 

class RPN{
    private:
    std::stack<int> stack;

    public:

    RPN();
    RPN(const RPN &instance);
    RPN& operator=(const RPN &instance);
    ~RPN();

    void CheckNumber(char *av);
    void calcul(std::string av);
};
