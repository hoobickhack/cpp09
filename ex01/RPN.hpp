#pragma once

#include <iostream>
#include <stack>

class RPN{
    private:
    std::stack<int> stack;

    public:

    RPN();
    RPN(const RPN &instance);
    RPN& operator=(const RPN &instance);
    ~RPN();

    void CheckNumber(char *av);
    void calcul();
};
