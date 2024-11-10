#include "PmergeMe.hpp"

Pmerge::Pmerge(): _even(true){}

Pmerge::~Pmerge(){}

Pmerge::Pmerge(const Pmerge &other)
{
    this->_doubleVec = other._doubleVec;
    this->_doubleList = other._doubleList;
    this->_bigNumberVector = other._bigNumberVector;
    this->_smallNumberVector = other._smallNumberVector;
    this->_bigNumberList = other._bigNumberList;
    this->_smallNumberList = other._smallNumberList;

    this->_even = other._even;
    this->_vecTemplate = other._vecTemplate;
    this->_listTemplate = other._listTemplate;
}

Pmerge &Pmerge::operator=(const Pmerge &other)
{
    if(this != &other)
    {
        this->_doubleVec = other._doubleVec;
        this->_doubleList = other._doubleList;
        this->_bigNumberVector = other._bigNumberVector;
        this->_smallNumberVector = other._smallNumberVector;
        this->_bigNumberList = other._bigNumberList;
        this->_smallNumberList = other._smallNumberList;

        this->_even = other._even;
        this->_vecTemplate = other._vecTemplate;
        this->_listTemplate = other._listTemplate;
    }
    return *this;
}

// GETTER

// METHODS
void Pmerge::process(char * input)
{
	//this->_timeBegin = std::chrono::high_resolution_clock::now();

    std::cout << "----------  VECTOR  ----------" << std::endl;
    init(input, this->_vecTemplate);
    orderPair(this->_vecTemplate);
    createDoubleContainer(this->_vecTemplate, this->_doubleVec);
    orderDoubleContainer<std::vector<int> >(this->_doubleVec);
    separateNumbers(this->_bigNumberVector, this->_smallNumberVector, this->_doubleVec);
    insertSmallNumbersToMainChain(this->_bigNumberVector, this->_smallNumberVector);
    displayContainer(this->_bigNumberVector);

    std::cout << "----------  LIST  ----------" << std::endl;
    init(input, this->_listTemplate);
    orderPair(this->_listTemplate);
    createDoubleContainer(this->_listTemplate, this->_doubleList);
    orderDoubleContainer<std::list<int> >(this->_doubleList);
    separateNumbers(this->_bigNumberList, this->_smallNumberList, this->_doubleList);
    insertSmallNumbersToMainChain(this->_bigNumberList, this->_smallNumberList);
    displayContainer(this->_bigNumberList);

	//this->_timeEnd = std::chrono::high_resolution_clock::now();
	//std::chrono::duration<double> processDuration = end_time - start_time;
    //std::cout << "Total Time : " << this->_timeEnd - this->_timeEnd << std::endl;
}

// DISPLAY

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