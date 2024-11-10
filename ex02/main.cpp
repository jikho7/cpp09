#include "PmergeMe.hpp"
#include <iostream>

int main(int ac, char** av)
{
    if (ac == 2)
    {
        Pmerge merge;
        merge.process(av[1]);
    }
    return 0;
}

/*NOTE
    - add counter to compare
*/