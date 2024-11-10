#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <iostream>
#include <ostream>
#include <list>
#include <sstream>
#include <cstring>
#include <ctime>

class Pmerge
{
        std::vector<int>                    _a;
        std::vector<std::pair<int, int> >   _doubleVec;
        std::list<std::pair<int, int> >     _doubleList;
        std::list<int>                      _bigNumberList;
        std::list<int>                      _smallNumberList;
        bool                                _even;  // pair

        std::vector<int>                    _vecTemplate;
        std::list<int>                      _listTemplate;

    public:
        Pmerge();
        ~Pmerge();
        Pmerge(const Pmerge &other);
        Pmerge &operator=(const Pmerge &other);

        // METHODS
        void                                process(char * input);
        void                                createDoubleVector();
        void                                orderDoubleVector();
        void                                createBigNumberList();
        void                                createSmallNumberList();
        void                                insertSmallNumbersToMainChain();

        // DISPLAY
        void                                displayVector() const;
        void                                displayDoubleVector() const;
        void                                displayList(std::list<int>& list) const;
        
        // TEMPLATES
        template<typename T, typename D> void   createDoubleContainer(T&container, D& doubleContainer);
        template<typename T, typename D> void   orderDoubleContainer(D& doubleContainer);
        template<typename T> void               orderPair(T& container);
        template<typename T> void               displayContainer(T& container)const ;
        template<typename T> void               init(char *input, T& container);
        template<typename D> void               displayDoubleContainer(D& doubleContainer)const;
       //template<typename T> void               separateBigNumbers(D& doubleContainer);
};

std::ostream &operator<<(std::ostream& os, const std::pair<int, int>& pair);
std::ostream &operator<<(std::ostream& os, const std::vector<std::pair<int, int> > &doubleVec);

#include "PmergeMe.tpp"

#endif

