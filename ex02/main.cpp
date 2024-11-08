// vector list
#include "PmergeMe.hpp"
#include <iostream>

int main()
{
    Pmerge merge;
    std::vector<int>& vec = merge.getVector();

    vec.push_back(1);
    vec.push_back(8);
    vec.push_back(12);
    vec.push_back(7);
    vec.push_back(81);
    vec.push_back(0);
    vec.push_back(11);
    vec.push_back(5);
    vec.push_back(50);

    std::cout << "Vector size after modifications: " << vec.size() << std::endl;

    merge.displayVector();
    merge.createPair();
    merge.displayVector();
    merge.displayDoubleVector();

    /*!SECTION
        recup input dans vector
        parcourir la liste, si next > current, pop out to char **!SECTION
        si next < current, swap et pop out 
    */
    return 0;
}
