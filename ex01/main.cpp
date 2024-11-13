// stack
#include "RPN.hpp"

int main(int ac, char**av)
{
    if (ac == 2)
    {
        RPN rpn;
        rpn.process(av[1]);
    }
    return 0;
}

/*NOTE

> ./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
42
$> ./RPN "7 7 * 7 -"
42
$> ./RPN "1 2 * 2 / 2 * 2 4 - +"
0
$> ./RPN "(1 + 1)"
Error

-> gerer la division par 0

*/