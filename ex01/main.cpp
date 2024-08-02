#include "RPN.hpp"
#include <iostream>

int main(int ac, char **av)
{
    RPN ilyes; 
    if (ac == 2)
        ilyes.CheckNumber(av[1]);
}