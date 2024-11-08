// vector list
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

    /*!SECTION
        recup input dans vector
        parcourir la liste, si next > current, pop out to char **!SECTION
        si next < current, swap et pop out 
    */