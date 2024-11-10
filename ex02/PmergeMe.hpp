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
        std::vector<std::pair<int, int> >       _doubleVec;
        std::list<std::pair<int, int> >         _doubleList;
        std::vector<int>                        _bigNumberVector;
        std::vector<int>                        _smallNumberVector;
        std::list<int>                          _bigNumberList;
        std::list<int>                          _smallNumberList;
        bool                                    _even;  // pair

        std::vector<int>                        _vecTemplate;
        std::list<int>                          _listTemplate;

    public:
        Pmerge();
        ~Pmerge();
        Pmerge(const Pmerge &other);
        Pmerge &operator=(const Pmerge &other);

        // GETTER

        // METHODS
        void                                    process(char * input);
        template<typename T> void               init(char *input, T& container);
        template<typename T, typename D> void   createDoubleContainer(T&container, D& doubleContainer);
        template<typename T> void               orderPair(T& container);
        template<typename T, typename D> void   orderDoubleContainer(D& doubleContainer);
        template<typename T, typename D> void   separateNumbers(T& bigNumberContainer, T& smallNumberContainer, D& doubleContainer);
        template<typename T> void               insertSmallNumbersToMainChain(T& bigNumber, T& smallNumber);

        // DISPLAY
        template<typename T> void               displayContainer(T& container)const ;
        template<typename D> void               displayDoubleContainer(D& doubleContainer)const;
};

std::ostream &operator<<(std::ostream& os, const std::pair<int, int>& pair);
std::ostream &operator<<(std::ostream& os, const std::vector<std::pair<int, int> > &doubleVec);

#include "PmergeMe.tpp"

#endif
// NOTE pour utiliser une fonction en argument faisant partie de la classe, doit etre static (pas besoin d instance pour appel)


