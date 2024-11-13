#include "PmergeMe.hpp"
#include <iostream>

// ./PmergeMe "$(jot -r 3000 1 1000 | tr '\n' ' ')"         pour MAC
// ./PmergeMe "$(shuf -i 1-1000 -n 3000 | tr '\n' ' ')"

//./PmergeMe "$(shuf -i 1-1000 -n 3000 | tr '\n' ' ')"      pour LINUX



int main(int ac, char** av)
{
    if (ac == 2)
    {
        Pmerge merge;
        merge.process(av[1]);
    }
    return 0;
}