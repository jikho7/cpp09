#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <iostream>
#include <cstring>
#include <sstream>

class RPN 
{
    std::stack<int> _stack;

    public:
    RPN();
    ~RPN();
    RPN(RPN &other);
    RPN&operator=(RPN &other);

    int             process(const char* input);
    int             calculate(const char operateur);

};

#endif