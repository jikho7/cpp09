#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <iostream>
#include <ostream>

class Pmerge
{
    public:
        Pmerge();
        ~Pmerge();
        Pmerge(const Pmerge &other);
        Pmerge &operator=(const Pmerge &other);

        std::vector<int>&                   getVector();
        std::vector<std::pair<int, int> >&  getDoubleVec();
        void                                createPair();
        void                                displayVector() const;
        void                                displayDoubleVector() const;
        void                                orderPair();
        void                                createDoubleVector();

    private:
        std::vector<int>                    _a;
        std::vector<std::pair<int, int> >   _doubleVec;
};

std::ostream &operator<<(std::ostream& os, const std::pair<int, int>& pair);
std::ostream &operator<<(std::ostream& os, const std::vector<std::pair<int, int> > &doubleVec);

#endif

