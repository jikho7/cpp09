#include "RPN.hpp"

RPN::RPN(): _res(0){}
RPN::~RPN(){}
RPN::RPN(RPN&other){
    this->_stack = other._stack;
    this->_res = other._res;
}
RPN& RPN::operator=(RPN& other){
    if(this != &other){
        this->_stack = other._stack;
        this->_res = other._res;
    }
    return *this;
}

int RPN::process(const char* input)
{
    int nb = 0;
    for(size_t i = 0; i < std::strlen(input); i++)
    {
        if(std::isdigit(input[i]))
        {
            std::stringstream ss(&input[i]);
            ss >> nb;
            this->_stack.push(nb);
        }
        else if(input[i] == '+' || input[i] == '-' ||input[i] == '*' ||input[i] == '/')
        {
            calculate(input[i]);
        }
        else if (input[i] != ' ')
        {
            std::cerr << "Error" << std::endl;
            return 0;
        }
    }
    std::cout << this->_res << std::endl;
    return 0;
}

int RPN::calculate(const char operateur)
{
    int right = this->_stack.top();
    this->_stack.pop();
    int left = this->_stack.top();
    this->_stack.pop();

    switch(operateur)
    {
        case('+'):
            this->_res = left + right;
            break;
        case('-'):
            this->_res = left - right;
            break;            
        case('*'):
            this->_res = left * right;
            break;            
        case('/'):
            this->_res = left / right;
            break;
        default:
            break;
    }
    //std::cout << _res << std::endl;
    this->_stack.push(_res);
    return 0;
}


/* NOTE
    -> lire la string,
    -> si c = isdigit -> convertir en int et balancer dans stack
    -> si c = + - * / -> faire calacul sur 2 derniers el de la stack
*/
