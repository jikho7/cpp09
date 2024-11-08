#include "PmergeMe.hpp"

Pmerge::Pmerge()
{
    std::cout << "Pmerge constructor called" << std::endl;
}

Pmerge::~Pmerge()
{
    std::cout << "Pmerge destructor called" << std::endl;
}

Pmerge::Pmerge(const Pmerge &other) // Take const reference
{
    this->_a = other._a;
    std::cout << "Pmerge copy constructor called, size: " << this->_a.size() << std::endl;
}

Pmerge &Pmerge::operator=(const Pmerge &other) // Take const reference
{
    if(this != &other)
    {
        this->_a = other._a;
        std::cout << "Pmerge assignment operator called, size: " << this->_a.size() << std::endl;
    }
    return *this;
}

std::vector<int>& Pmerge::getVector() // Return non-const reference to vector
{
    std::cout << "getVector called, size: " << this->_a.size() << std::endl;
    return this->_a;
}

std::vector<std::pair<int, int> > &Pmerge::getDoubleVec(){
    return this->_doubleVec;
}

void Pmerge::createPair()
{
    orderPair();
    createDoubleVector();
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

void Pmerge::displayVector() const
{
    if(this->_a.empty())
        std::cout << "vec is empty" << std::endl;
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
