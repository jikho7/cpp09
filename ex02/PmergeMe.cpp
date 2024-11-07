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

void Pmerge::displayVector(const std::vector<int>& vec) const // Pass vector by const reference
{
    std::cout << "displayVector called, size: " << vec.size() << std::endl;
    if(vec.empty())
        std::cout << "vec is empty" << std::endl;
    for(std::vector<int>::const_iterator it = vec.begin(); it != vec.end(); ++it)
    {
        std::cout << *it << std::endl;
    }
}

void Pmerge::createPair(std::vector<int> &vec)
{
    std::cout << "create pair" << std::endl;
    for(std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
    {
        if((it + 1) != vec.end() && *it > *(it + 1))
        {
            std::swap(*it, *(it + 1));
            ++it;
        }
    }
    std::cout << "check" << std::endl;
    for(std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
    {
        std::cout << "check 1 " << std::endl;

        if(it != vec.end())
        {
            this->_doubleVec.push_back(std::make_pair(*it, *(it + 1)));
            ++it;
        }
        else
            ++it;
    }
    std::cout << "end create pair" << std::endl;

    displayDoubleVector(this->_doubleVec);

}

void Pmerge::displayDoubleVector(std::vector<std::pair<int, int> > doubleVec)
{
    std::cout << "Display doubleVec" << std::endl;
    for(std::vector<std::pair<int, int> >::iterator it = doubleVec.begin(); it != doubleVec.end(); ++it)
    {
        std::cout << *it << std::endl;
    }
    std::cout << "End Display doubleVec" << std::endl;

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
