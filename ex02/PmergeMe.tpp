#include "PmergeMe.hpp"

template<typename T> void Pmerge::init(char *input, T& container)
{
    std::string str(input);         // convertion char * to std::string
    std::stringstream ss(str);
    int intNumber;
    std::set<int> uniqueNumbers;    // set ne permet pas les doublons :)
    while (ss >> intNumber)         // strgingstream >> operator skip automatiquement les espaces, tab, new ligne
    {
        if (uniqueNumbers.insert(intNumber).second) // insert returns a pair, second is true iif insertion ok
        {
            container.push_back(intNumber);
            this->_even = !this->_even; // even to odds to even...
            this->_nbOfElements++;
        }
    }
}

template<typename T> void Pmerge::displayContainer(T& container) const                  // T == std::vector<int> ou std::list<int>
{
    if(container.empty())
        std::cout << "Container is empty" << std::endl;
    for(typename T::const_iterator it = container.begin(); it != container.end(); ++it) // typename dit que T::const_iterator est un type
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

template<typename T> void Pmerge::orderPair(T& container)        // typename T == std::vector<int> || std::list<int>
{
    for(typename T::iterator it = container.begin(); it != container.end(); ++it)
    {
        typename T::iterator nextIt = it;                       // car (it + 1) non valide pour list, == (it + 1) de vector
        ++nextIt;
        if(nextIt != container.end() && *it > *nextIt)
        {
            std::swap(*it, *nextIt);
            it++;
        }
        else if (nextIt != container.end() && *it < *nextIt)
            it++;
    }
}

template<typename T, typename D>
void Pmerge::createDoubleContainer(T& container, D& doubleContainer)
{
    for(typename T::iterator it = container.begin(); it != container.end(); ++it)
    {
        typename T::iterator nextIt = it;
        ++nextIt;
        if(nextIt != container.end())
        {
            doubleContainer.push_back(std::make_pair(*it, *nextIt));
            ++it;
        }
    }
    if(!this->_even)
    {
        typename T::iterator itt = container.end();
        --itt;
        doubleContainer.push_back(std::make_pair(-1, *itt));
    }
}

template<typename D>
void Pmerge::displayDoubleContainer(D &doubleContainer) const
{
    for(typename D::const_iterator it = doubleContainer.begin(); it != doubleContainer.end(); ++it)
    {
        std::cout << *it << std::endl;
    }
}

template<typename T, typename D>
void Pmerge::orderDoubleContainer(D& doubleContainer)
{
    T mainChain; // std::vector<int> || std::list<int>
    // 1ere etape: parcours doubleContainer, prend it->second(big number) et rempli de maniere triee mainChain grace a lower_bound
    for(typename D::iterator it = doubleContainer.begin(); it != doubleContainer.end(); ++it)
    {
        int bigNumber = it->second;
        typename T::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), bigNumber); // lower_bund : élément clé de l'algo merge insertion.
        mainChain.insert(pos, bigNumber);
    }
    D sortedDoubleContainer;
    // Reintegrate small numbers to pair
    for (typename T::iterator mainIt = mainChain.begin(); mainIt != mainChain.end(); ++mainIt)
    {
        for (typename D::iterator it = doubleContainer.begin(); it != doubleContainer.end(); ++it)
        {
            if (it->second == *mainIt)
            {
                sortedDoubleContainer.push_back(*it); // ajoute la pair complete (41 72) 
                break; //TODO eviter doublon TESTER AVEC 2 MEMES NOMBRE DANS INPUT
            }
        }
    }
    doubleContainer = sortedDoubleContainer;
}

template<typename T, typename D> void Pmerge::separateNumbers(T& bigNumberContainer, T& smallNumberContainer, D& doubleContainer)
{
    smallNumberContainer.clear();   // avoir une base propre, eviter doublon
    bigNumberContainer.clear();
    for(typename D::iterator it = doubleContainer.begin(); it != doubleContainer.end(); ++it)
    {
        bigNumberContainer.push_back(it->second);
        smallNumberContainer.push_back(it->first);
    }
}

template<typename T> void Pmerge::insertSmallNumbersToMainChain(T& bigNumber, T& smallNumber)
{
    for(typename T::iterator it = smallNumber.begin(); it != smallNumber.end(); ++it)
    {
        if (*it >= 0)
        {
            typename T::iterator pos = lower_bound(bigNumber.begin(), bigNumber.end(), *it);
            bigNumber.insert(pos, *it);
        }
    }
}
