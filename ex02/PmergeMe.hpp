#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <iostream>
#include <ostream>
#include <list>
#include <sstream>
#include <cstring>

class Pmerge
{
        std::vector<int>                    _a;
        std::vector<std::pair<int, int> >   _doubleVec;
        std::list<int>                      _bigNumberList;
        std::list<int>                      _smallNumberList;

    public:
        Pmerge();
        ~Pmerge();
        Pmerge(const Pmerge &other);
        Pmerge &operator=(const Pmerge &other);

        std::vector<int>&                   getRefVector();
        std::vector<std::pair<int, int> >&  getRefDoubleVec();
        std::list<int>&                     getRefBigNumberList();
        std::list<int>&                     getRefSmallNumberList();
        // METHODS
        void                                process(char * input);
        void                                initVector(char * input);
        void                                orderPair();
        void                                createDoubleVector();
        void                                orderDoubleVector();
        void                                createBigNumberList();
        void                                createSmallNumberList();
        // DISPLAY
        void                                displayVector() const;
        void                                displayDoubleVector() const;
        void                                displayList(std::list<int>& list) const;



};

std::ostream &operator<<(std::ostream& os, const std::pair<int, int>& pair);
std::ostream &operator<<(std::ostream& os, const std::vector<std::pair<int, int> > &doubleVec);

#endif

