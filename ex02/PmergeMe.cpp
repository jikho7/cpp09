#include "PmergeMe.hpp"

Pmerge::Pmerge(): _even(true){}

Pmerge::~Pmerge(){}

Pmerge::Pmerge(const Pmerge &other)
{
    this->_a = other._a;
    this->_doubleVec = other._doubleVec;
    this->_bigNumberList = other._bigNumberList;
    this->_smallNumberList = other._smallNumberList;
}

Pmerge &Pmerge::operator=(const Pmerge &other)
{
    if(this != &other)
    {
        this->_a = other._a;
        this->_doubleVec = other._doubleVec;
        this->_bigNumberList = other._bigNumberList;
        this->_smallNumberList = other._smallNumberList;
    }
    return *this;
}

// GETTERS

// METHODS
void Pmerge::process(char * input)
{
    initVector(input);
    orderPair();
    
    createDoubleVector();
    orderDoubleVector();

    createBigNumberList();
    //displayList(this->_bigNumberList);
    createSmallNumberList();
    //displayList(this->_smallNumberList);

    insertSmallNumbersToMainChain();
    std::cout << "after insertion " << std::endl;
    displayList(this->_bigNumberList);
}

void Pmerge::initVector(char *input)
{
    std::string str(input);     // convertion char * to std::string
    std::stringstream ss(str);

    int intNumber;
    while (ss >> intNumber)     // strgingstream >> operator skip automatiquement les espaces, tab, new ligne
    {
        this->_a.push_back(intNumber);
        this->_even = !this->_even; // even to odds to even...
    }
}

void Pmerge::orderPair()
{
    for(std::vector<int>::iterator it = this->_a.begin(); it != this->_a.end(); ++it)
    {
        //std::cout << "it : " << *it << std::endl;
        if((it + 1) != this->_a.end() && *it > *(it + 1))
        {
            std::swap(*it, *(it + 1));
            //std::cout << "swap done : " << " it : " << *it << " it + 1 :" << *(it + 1) << std::endl;
            it++;
        }
        else if ((it + 1) != this->_a.end() && *it < *(it + 1))
            it++;
    }
}

void Pmerge::createDoubleVector()
{
    for(std::vector<int>::iterator it = this->_a.begin(); it != this->_a.end(); ++it)
    {
        if((it + 1) != this->_a.end())
        {
            this->_doubleVec.push_back(std::make_pair(*it, *(it + 1)));
            ++it;
        }
    }
    if(!this->_even)
    {
        //std::cout << "even : " << this->_even << std::endl;
        this->_doubleVec.push_back(std::make_pair(-1, *(this->_a.end() - 1)));
    }
}

void Pmerge::orderDoubleVector()
{
    std::vector<int> mainChain;
    // sorting mainchain with big numbers
    for (std::vector<std::pair<int, int> >::iterator it = this->_doubleVec.begin(); it != this->_doubleVec.end(); ++it)
    {
        int value = it->second;
        std::vector<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), value); // lower_bund : élément clé de l'algo merge insertion.
        mainChain.insert(pos, value);
    }

    std::vector<std::pair<int, int> > sortedDoubleVec;
    // Reintegrate small numbers to pair
    for (size_t i = 0; i < mainChain.size(); ++i)
    {
        for (std::vector<std::pair<int, int> >::iterator it = this->_doubleVec.begin(); it != this->_doubleVec.end(); ++it)
        {
            if (it->second == mainChain[i]) // comparing big numbers pair/vector
            {
                sortedDoubleVec.push_back(*it);
                break; // eviter doublon
            }
        }
    }
    this->_doubleVec = sortedDoubleVec;
}

void Pmerge::createBigNumberList()
{
    this->_bigNumberList.clear(); // avoir une base propre, eviter doublon
    for(std::vector<std::pair<int, int> >::iterator it = this->_doubleVec.begin(); it != this->_doubleVec.end(); ++it)
    {
        this->_bigNumberList.push_back(it->second);
    }
}
void Pmerge::createSmallNumberList()
{
    this->_smallNumberList.clear(); // avoir une base propre, eviter doublon
    for(std::vector<std::pair<int, int> >::iterator it = this->_doubleVec.begin(); it != this->_doubleVec.end(); ++it)
    {
        if (it->first != -1) // odds number list (-1, number)
            this->_smallNumberList.push_back(it->first);
    }
}

void Pmerge::insertSmallNumbersToMainChain()
{
    for(std::list<int>::iterator it = this->_smallNumberList.begin(); it != this->_smallNumberList.end(); ++it)
    {
        std::list<int>::iterator pos = lower_bound(this->_bigNumberList.begin(), this->_bigNumberList.end(), *it);
        this->_bigNumberList.insert(pos, *it);
    }
}

// DISPLAY
void Pmerge::displayVector() const
{
    if(this->_a.empty())
        std::cout << "Vector is empty" << std::endl;
    for(std::vector<int>::const_iterator it = this->_a.begin(); it != this->_a.end(); ++it)
    {
        std::cout << *it << std::endl;
    }
}

void Pmerge::displayDoubleVector() const
{
    std::cout << "Display double Vector" << std::endl;
    for(std::vector<std::pair<int, int> >::const_iterator it = this->_doubleVec.begin(); it != this->_doubleVec.end(); ++it)
    {
        std::cout << *it << std::endl;
    }
}

void Pmerge::displayList(std::list<int>& list) const
{
    std::cout << "display list" << std::endl;
    if (list.empty())
        std::cout << "List is empty" << std::endl;
    for(std::list<int>::const_iterator it = list.begin(); it != list.end(); ++it)
    {
        std::cout << *it << std::endl;
    }
}

// OPERATOR
std::ostream &operator<<(std::ostream &os, const std::pair<int, int> &pair)
{
    os << pair.first << " " << pair.second << std::endl;
    return os;
}

std::ostream &operator<<(std::ostream &os, const std::vector<std::pair<int, int> > &doubleVec)
{
    for (std::vector<std::pair<int, int>  >::const_iterator it = doubleVec.begin(); it != doubleVec.end(); ++it) {
        os << *it << " ";
    }
    return os;
}