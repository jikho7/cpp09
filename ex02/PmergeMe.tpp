#include "PmergeMe.hpp"

template<typename T> void Pmerge::init(char *input, T& container)
{
    std::string str(input);     // convertion char * to std::string
    std::stringstream ss(str);

    int intNumber;
    while (ss >> intNumber)     // strgingstream >> operator skip automatiquement les espaces, tab, new ligne
    {
        container.push_back(intNumber);
        this->_even = !this->_even; // even to odds to even...
    }
}

template<typename T> void Pmerge::display(T& container) const // T == std::vector<int> ou std::list<int>
{
    if(container.empty())
        std::cout << "Vector is empty" << std::endl;
    for(typename T::const_iterator it = container.begin(); it != container.end(); ++it) // typename dit que T::const_iterator est un type
    {
        std::cout << *it << std::endl;
    }
}

template<typename T> void Pmerge::orderPair(T& container) // tyename T == std::vector<int> || std::list<int>
{
    for(typename T::iterator it = container.begin(); it != container.end(); ++it)
    {
        //std::cout << "it : " << *it << std::endl;
        typename T::iterator nextIt = it; // car (it + 1) non valide pour list, == (it + 1) de vector
        ++nextIt;
        if(nextIt != container.end() && *it > *nextIt)
        {
            std::swap(*it, *nextIt);
            //std::cout << "swap done : " << " it : " << *it << " it + 1 :" << *(it + 1) << std::endl;
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
    // if(!this->_even)
    // {
    //     //std::cout << "even : " << this->_even << std::endl;
    //     this->_doubleVec.push_back(std::make_pair(-1, *(this->_a.end() - 1)));
    // }
}

void Pmerge::displayDoubleVector() const
{
    std::cout << "Display double Vector" << std::endl;
    for(std::vector<std::pair<int, int> >::const_iterator it = this->_doubleVec.begin(); it != this->_doubleVec.end(); ++it)
    {
        std::cout << *it << std::endl;
    }
}