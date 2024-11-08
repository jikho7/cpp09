#include "PmergeMe.hpp"

Pmerge::Pmerge(){}

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

// GETTERS (REF)
std::list<int> &Pmerge::getRefBigNumberList(){
    return this->_bigNumberList;}

std::list<int> &Pmerge::getRefSmallNumberList(){
    return this->_smallNumberList;}

std::vector<int>& Pmerge::getRefVector(){
    return this->_a;}

std::vector<std::pair<int, int> > &Pmerge::getRefDoubleVec(){
    return this->_doubleVec;}

// METHODS
void Pmerge::process(char * input)
{
    initVector(input);
    displayVector();
    orderPair();

    createDoubleVector();
    orderDoubleVector();
    displayDoubleVector();

    createBigNumberList();
    createSmallNumberList();
    displayList(this->_bigNumberList);
    displayList(this->_smallNumberList);
}

void Pmerge::initVector(char * input)
{
    for(size_t i = 0; i < std::strlen(input); ++i)
    {
        while(input[i] == ' ')
            i++;
        std::stringstream ss;   // prend std::strinf en argument et pas de char*
        ss << input[i];         // faire cette etape a la place
        int res;
        ss >> res;
        this->_a.push_back(res);
    }
}

void Pmerge::orderPair()
{
    for(std::vector<int>::iterator it = this->_a.begin(); it != this->_a.end(); ++it)
    {
        if((it + 1) != this->_a.end() && *it > *(it + 1))
        {
            std::swap(*it, *(it + 1));
            ++it;
        }
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
}

void Pmerge::orderDoubleVector()
{
    int j = 1;
    while (j != 0)
    {
        j = 0;
        for(std::vector<std::pair<int, int> >::iterator it = this->_doubleVec.begin(); it != this->_doubleVec.end(); ++it)
        {
            if((it + 1) != this->_doubleVec.end() && it->second > (it + 1)->second)
            {
                std::swap(*it, *(it +1));
                j++;
            }
        }
    }
}

void Pmerge::createBigNumberList()
{
    std::cout << "creat Big number list" << std::endl;
    this->_bigNumberList.clear(); // avoir une base propre, eviter doublon
    for(std::vector<std::pair<int, int> >::iterator it = this->_doubleVec.begin(); it != this->_doubleVec.end(); ++it)
    {
        this->_bigNumberList.push_back(it->second);
    }
    std::cout << "end of creat Big number list" << std::endl;
}

void Pmerge::createSmallNumberList()
{
    std::cout << "creat Small number list" << std::endl;
    this->_smallNumberList.clear(); // avoir une base propre, eviter doublon
    for(std::vector<std::pair<int, int> >::iterator it = this->_doubleVec.begin(); it != this->_doubleVec.end(); ++it)
    {
        this->_smallNumberList.push_back(it->first);
    }
    std::cout << "end of creat Small number list" << std::endl;
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
